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

/**
 *  @file
 *
 *  @brief Platform LOG Service
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Service
 *
 *  @{
 */

/**
 *  @defgroup Platform_LOG LOG
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

#ifndef LOG_H_
    #define LOG_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include <stdarg.h>

    #include "LOG_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief LOG Operation Status
     *
     *  @enum LOG_Status_t
     */
    typedef enum LOG_Status
    {
        LOG_Status_Success = 0,     ///< Success
        LOG_Status_ArgumentInvalid, ///< Argument Invalid
        LOG_Status_NotSupported,    ///< Not Supported
        LOG_Status_Error,           ///< General Error
        LOG_Status_Busy,            ///< Busy
        LOG_Status_Timeout,         ///< Timeout
    } LOG_Status_t;

    /**
     *  @brief LOG Level Type
     *
     *  @enum LOG_Level_t
     */
    typedef enum LOG_Level
    {
        LOG_Level_Default = 0, ///< Default
        LOG_Level_Trace,       ///< Trace
        LOG_Level_Debug,       ///< Debug
        LOG_Level_Information, ///< Information
        LOG_Level_Warning,     ///< Warning
        LOG_Level_Error,       ///< Error
        LOG_Level_Fatal,       ///< Fatal
        LOG_Level_None,        ///< None
    } LOG_Level_t;

    /**
     *  @brief LOG Format Type
     */
    typedef const char * LOG_Format_t;

    /**
     *  @brief LOG Arguments Type
     */
    typedef va_list LOG_Args_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize logging interface
     *
     *  @note MUST BE called before using any LOG API
     *
     *  @param[in] LOGx Interface
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Initialize( LOG_t LOGx );

    /**
     *  @brief Cycle logging interface
     *
     *  @param[in] LOGx Interface
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Cycle( LOG_t LOGx );

    /**
     *  @brief DeInitialize logging interface
     *
     *  @param[in] LOGx Interface
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_DeInitialize( LOG_t LOGx );

    /**
     *  @brief Set level threshold to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Level  Severity level threshold
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_SetLevel( LOG_t LOGx, LOG_Level_t Level );

    /**
     *  @brief Write trace formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Trace( LOG_t LOGx, LOG_Format_t Format, ... );

    /**
     *  @brief Write debug formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Debug( LOG_t LOGx, LOG_Format_t Format, ... );

    /**
     *  @brief Write information formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Info( LOG_t LOGx, LOG_Format_t Format, ... );

    /**
     *  @brief Write warning formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Warning( LOG_t LOGx, LOG_Format_t Format, ... );

    /**
     *  @brief Write error formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Error( LOG_t LOGx, LOG_Format_t Format, ... );

    /**
     *  @brief Write fatal formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Fatal( LOG_t LOGx, LOG_Format_t Format, ... );

    /**
     *  @brief Write raw formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Level  Severity level
     *  @param[in] Format Formatted message
     *  @param[in] ...    Arguments to formatted message (optional)
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_Raw( LOG_t LOGx, LOG_Level_t Level, LOG_Format_t Format, ... );

    /**
     *  @brief Write trace formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_TraceWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args );

    /**
     *  @brief Write debug formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_DebugWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args );

    /**
     *  @brief Write information formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_InfoWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args );

    /**
     *  @brief Write warning formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_WarningWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args );

    /**
     *  @brief Write error formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_ErrorWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args );

    /**
     *  @brief Write fatal formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_FatalWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args );

    /**
     *  @brief Write raw formatted message to logging interface
     *
     *  @param[in] LOGx   Interface
     *  @param[in] Level  Severity level
     *  @param[in] Format Formatted message
     *  @param[in] Args   Arguments to formatted message
     *
     *  @return LOG_Status_t
     */
    LOG_Status_t LOG_RawWithArgs( LOG_t LOGx, LOG_Level_t Level, LOG_Format_t Format, LOG_Args_t Args );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char LOG_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* LOG_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
