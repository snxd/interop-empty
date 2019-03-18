## Empty Interop Example for DIRECT 5.2

### Requirements

* CMake 2.8

### Overview

This is an empty project for interop development.

### Build Instructions

CMake is a makefile generator that produces solutions and project files for various compiler toolkits. 

#### Visual Studio

```
cmake .
cmake --build . --config Debug
```

#### Xcode

```
cmake . -G Xcode
cmake --build . --config Debug
```

#### Unix Makefiles

```
cmake . -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```