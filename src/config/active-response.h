/*   $OSSEC, active-response.h, v0.1, 2005/10/30, Daniel B. Cid$   */

/* Copyright (C) 2004,2005 Daniel B. Cid <dcid@ossec.net>
 * All right reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */

 
#ifndef _CAR__H
#define _CAR__H


typedef struct _ar_command
{
    int expect;
    int timeout_allowed;
    char *name;
    char *executable;
}ar_command;


typedef struct _ar
{
    int timeout;
    int location;
    char *name;
    char *command;
    char *agent_id;
    char *rules_id;
    char *rules_group;
    char *level;

    ar_command *ar_cmd;
}active_response;


#include "list_op.h"

int ar_flag;
OSList *ar_commands;
OSList *active_responses;


/* function prototypes */
void AS_Init();
int AS_GetActiveResponses(char * config_file);
int AS_GetActiveResponseCommands(char * config_file);

#endif
