// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef LOG_INTERNAL_H_
    #define LOG_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "LOG_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef LOG_TIM
        #define LOG_TIM PLATFORM_DEFAULT_TIM
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct LOG_Instance_Context LOG_Instance_Context_t;

    typedef struct LOG_Instance
    {
        LOG_t LOGx;
        LOG_Level_t Level;

        union
        {
            LOG_Instance_Context_t * Context;
        };
    } LOG_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    LOG_Status_t LOG_Level_IsValid( LOG_Level_t Level );

    // The following APIs MUST be provided by the port
    LOG_Status_t LOG_IsValid( LOG_t LOGx );

    LOG_Status_t LOG_Instance_Initialize( LOG_Instance_t * Instance );
    LOG_Status_t LOG_Instance_Cycle( LOG_Instance_t * Instance );
    LOG_Status_t LOG_Instance_DeInitialize( LOG_Instance_t * Instance );

    LOG_Status_t LOG_Instance_Write( LOG_Instance_t * Instance, LOG_Level_t Level, LOG_Format_t Format, LOG_Args_t Args );

    // TODO Add More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* LOG_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
