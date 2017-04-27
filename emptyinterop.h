#pragma once

#ifndef _EMPTYINTEROP_H_
#define _EMPTYINTEROP_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************/

/*! 
 * Called when an instance is created
 * \param TypeName type of object to be created
 * \param InstanceId id of the object to be created
 * \param InstanceIdLength maximum length of the InstanceId
 * \param ExecuteUserPtr user pointer stored with execute callback
 * \param Execute execute callback
 * \param Invoke pointer to the instance invocation callback function
 * \param Release pointer to the instance release/delete callback function
 * \param Process pointer to the instance process callback function
 * \param UserPtr pointer associated with instance id
 * \return TRUE on success, FALSE otherwise
 */
int32 Interop_CreateInstance(char *TypeName, char *InstanceId, int32 InstanceIdLength, 
                             void *ExecuteUserPtr, Interop_ExecuteCallback Execute,
                             Interop_InvokeInstanceCallback *Invoke,
                             Interop_ReleaseInstanceCallback *Remove,
                             Interop_ProcessInstanceCallback *Process,
                             void **UserPtr);

/*! 
 * Set an interop function to override by key
 * \param Key identifier of option
 * \param Value pointer to the function
 * \return TRUE on success, FALSE otherwise
 */
int32 Interop_SetOverride(char *Key, void *Value);

/*! 
 * Set an interop option by key
 * \param Key identifier of option
 * \param Value value of option
 * \return TRUE on success, FALSE otherwise
 */
int32 Interop_SetOption(char *Key, void *Value);

/*! 
 * Loads interop functions
 * \return TRUE on success, FALSE otherwise
 */
int32 Interop_Load(void);
/*! 
 * Unloads interop functions
 * \return TRUE on success, FALSE otherwise
 */
int32 Interop_Unload(void);

/*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif