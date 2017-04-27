import qbs;

Product {
    name: "empty"
    type: [ "dynamiclibrary" ]
    consoleApplication: false

    Depends { name: "cpp" }

    cpp.commonCompilerFlags: [
        "-Wno-unused-parameter",
        "-Wno-unused-function",
        "-Wno-empty-body",
        "-Wno-sequence-point"
    ]

    Properties {
        condition: qbs.targetOS.contains("linux")
        cpp.includePaths: outer.concat([
            "/usr/include/",
            "../interop/"
        ])
        cpp.visibility: "hidden"
        cpp.linkerFlags: base.concat([
            "-Wl,--retain-symbols-file=" + sourceDirectory + "/empty.def"
        ])
    }

    Group {
        name: "exports"
        files: [
            "empty.def"
        ]
    }

    Group {
        name: "sources"
        prefix: "../"
        files: [
            "emptyinterop.c"
        ]
    }

    Group {
        name: "interop headers"
        prefix: "../interop/"
        files: [
            "interoplib.h",
            "interopstub.h"
        ]
    }

    Group {
        // Copy produced library to install root
        fileTagsFilter: "dynamiclibrary"
        qbs.install: true
    }
}
