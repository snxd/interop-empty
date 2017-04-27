#include "interoplib.h"
#include "interopstub.h"

/*********************************************************************/

int32 Interop_CreateInstance(char *TypeName, char *InstanceId, int32 InstanceIdLength,
                             void *ExecuteUserPtr, Interop_ExecuteCallback Execute,
                             Interop_InvokeInstanceCallback *InvokeInstance,
                             Interop_ReleaseInstanceCallback *ReleaseInstance,
                             Interop_ProcessInstanceCallback *ProcessInstance,
                             void **UserPtr)
{
    return FALSE;
}

int32 Interop_SetOverride(char *Key, void *Value)
{
    InteropLib_SetOverride(Key, Value);
    return TRUE;
}

int32 Interop_SetOption(char *Key, void *Value)
{
    return TRUE;
}

int32 Interop_Load()
{
    return TRUE;
}

int32 Interop_Unload()
{
    return TRUE;
}

/*********************************************************************/
