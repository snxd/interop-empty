#include "interoptypes.h"
#include "interoplib.h"

/*********************************************************************/

#define FALSE   (0)
#define TRUE    (1)

/*********************************************************************/

int32 Interop_CreateInstance(char *TypeName, char *InstanceId, int32 InstanceIdLength,
                             void *ExecuteUserPtr, InteropExecuteCallback Execute,
                             InteropInvokeInstanceCallback *InvokeInstance,
                             InteropRemoveInstanceCallback *RemoveInstance,
                             InteropProcessInstanceCallback *ProcessInstance,
                             void **UserPtr)
{
    return FALSE;
}

int32 Interop_SetOverride(char *Key, char *Value)
{
    return TRUE;
}

int32 Interop_SetOption(char *Key, char *Value)
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
