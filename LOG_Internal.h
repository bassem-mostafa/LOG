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

    #include "LOG.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef LOG_TIM
        #define LOG_TIM PLATFORM_DEFAULT_TIM
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum LOG_Type
    {
        LOG_Type_Unknown = 0,
        LOG_Type_Null,
        LOG_Type_USB,
        LOG_Type_UART,
        LOG_Type_CLI,
    } LOG_Type_t;

    typedef struct LOG_Instance
    {
        LOG_Type_t Type;

        union
        {
            struct
            {
                USB_t Instance;
                USB_Interface_t Interface;
            } USBx;

            UART_t UARTx;
            CLI_t CLIx;
        };

        LOG_Level_t Level;

        BUFFER_t Transmit;
    } LOG_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    LOG_Status_t LOG_Port_Initialize( LOG_t LOGx );
    LOG_Status_t LOG_Port_Cycle( LOG_t LOGx );
    LOG_Status_t LOG_Port_DeInitialize( LOG_t LOGx );

    LOG_Status_t LOG_Port_SetLevel( LOG_t LOGx, LOG_Level_t Level );

    LOG_Status_t LOG_Port_Write( LOG_t LOGx, LOG_Level_t Level, LOG_Format_t Format, LOG_Args_t Args );

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
