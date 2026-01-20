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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "LOG.h"
#include "LOG_Internal.h"

#include <stdarg.h>
#include <stdio.h>

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct LOG_Context
{
    LOG_Instance_t Instance[ LOG_Count ];
} LOG_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static LOG_Status_t LOG_Context_Initialize( void );
static LOG_Status_t LOG_Context_Cycle( void );
static LOG_Status_t LOG_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static LOG_Context_t LOG_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static LOG_Status_t LOG_Context_Initialize( void )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        for ( LOG_t LOG_x = LOG_Null; LOG_x < LOG_Count; ++LOG_x )
        {
            LOG_Context.Instance[ LOG_x ].LOGx = LOG_x;
        }

        Status = LOG_Status_Success;
    }
    while ( 0 );

    return Status;
}

static LOG_Status_t LOG_Context_Cycle( void )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_Status_Success;
    }
    while ( 0 );

    return Status;
}

static LOG_Status_t LOG_Context_DeInitialize( void )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

LOG_Status_t LOG_Initialize( LOG_t LOGx )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        if ( ( Status = LOG_IsValid( LOGx ) ) != LOG_Status_Success )
        {
            break;
        }

        if ( ( Status = LOG_Context_Initialize( ) ) != LOG_Status_Success )
        {
            break;
        }

        for ( LOG_t LOG_x = LOG_Null; LOG_x < LOG_Count; ++LOG_x )
        {
            if ( LOGx != LOG_All && LOGx != LOG_x )
            {
                continue;
            }

            LOG_Status_t LOG_Status = LOG_Status_Success;
            if ( ( LOG_Status = LOG_Instance_Initialize( &LOG_Context.Instance[ LOG_x ] ) ) != LOG_Status_Success )
            {
                Status = LOG_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Cycle( LOG_t LOGx )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        if ( ( Status = LOG_IsValid( LOGx ) ) != LOG_Status_Success )
        {
            break;
        }

        if ( ( Status = LOG_Context_Cycle( ) ) != LOG_Status_Success )
        {
            break;
        }

        for ( LOG_t LOG_x = LOG_Null; LOG_x < LOG_Count; ++LOG_x )
        {
            if ( LOGx != LOG_All && LOGx != LOG_x )
            {
                continue;
            }

            LOG_Status_t LOG_Status = LOG_Status_Success;
            if ( ( LOG_Status = LOG_Instance_Cycle( &LOG_Context.Instance[ LOG_x ] ) ) != LOG_Status_Success )
            {
                Status = LOG_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_DeInitialize( LOG_t LOGx )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        if ( ( Status = LOG_IsValid( LOGx ) ) != LOG_Status_Success )
        {
            break;
        }

        for ( LOG_t LOG_x = LOG_Null; LOG_x < LOG_Count; ++LOG_x )
        {
            if ( LOGx != LOG_All && LOGx != LOG_x )
            {
                continue;
            }

            LOG_Status_t LOG_Status = LOG_Status_Success;
            if ( ( LOG_Status = LOG_Instance_DeInitialize( &LOG_Context.Instance[ LOG_x ] ) ) != LOG_Status_Success )
            {
                Status = LOG_Status;
            }
        }

        Status = LOG_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_SetLevel( LOG_t LOGx, LOG_Level_t Level )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        if ( ( Status = LOG_IsValid( LOGx ) ) != LOG_Status_Success )
        {
            break;
        }

        if ( ( Status = LOG_Level_IsValid( Level ) ) != LOG_Status_Success )
        {
            break;
        }

        if ( Level == LOG_Level_Default )
        {
            Level = LOG_Level_Information;
        }

        for ( LOG_t LOG_x = LOG_Null; LOG_x < LOG_Count; ++LOG_x )
        {
            if ( LOGx != LOG_All && LOGx != LOG_x )
            {
                continue;
            }

            LOG_Context.Instance[ LOG_x ].Level = Level;
        }

        Status = LOG_Status_Success;
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Trace( LOG_t LOGx, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Trace, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Debug( LOG_t LOGx, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Debug, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Info( LOG_t LOGx, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Information, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Warning( LOG_t LOGx, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Warning, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Error( LOG_t LOGx, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Error, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Fatal( LOG_t LOGx, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Fatal, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_Raw( LOG_t LOGx, LOG_Level_t Level, LOG_Format_t Format, ... )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        LOG_Args_t Args;
        va_start( Args, Format );
        Status = LOG_RawWithArgs( LOGx, Level, Format, Args );
        va_end( Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_TraceWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Trace, Format, Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_DebugWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Debug, Format, Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_InfoWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Information, Format, Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_WarningWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Warning, Format, Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_ErrorWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Error, Format, Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_FatalWithArgs( LOG_t LOGx, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        Status = LOG_RawWithArgs( LOGx, LOG_Level_Fatal, Format, Args );
    }
    while ( 0 );

    return Status;
}

LOG_Status_t LOG_RawWithArgs( LOG_t LOGx, LOG_Level_t Level, LOG_Format_t Format, LOG_Args_t Args )
{
    LOG_Status_t Status = LOG_Status_Error;

    do
    {
        if ( ( Status = LOG_IsValid( LOGx ) ) != LOG_Status_Success )
        {
            break;
        }

        if ( ( Status = LOG_Level_IsValid( Level ) ) != LOG_Status_Success )
        {
            break;
        }

        if ( Level == LOG_Level_Default )
        {
            Level = LOG_Level_Information;
        }

        for ( LOG_t LOG_x = LOG_Null; LOG_x < LOG_Count; ++LOG_x )
        {
            if ( LOGx != LOG_All && LOGx != LOG_x )
            {
                continue;
            }

            LOG_Instance_t * Instance = &LOG_Context.Instance[ LOG_x ];

            if ( Level < Instance->Level )
            {
                // skip the logging
                continue;
            }

            LOG_Status_t LOG_Status = LOG_Status_Success;
            if ( ( LOG_Status = LOG_Instance_Write( Instance, Level, Format, Args ) ) != LOG_Status_Success )
            {
                Status = LOG_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char LOG_VERSION[] = "0.0.0.v20260120-0211";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
