#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>

#include "included/printing.h"

#define _CRT_SECURE_NO_WARNINGS 1
/* DEBUG: 0 - Keine Meldungen 1 - Debugmeldungen*/
#define DEBUG 1

void DEBUG_Log(char *text);
int getArraySizeForChar( char *Array );

typedef struct account
{
   char FirstName[25];
   char LastName[25];
   char UserName[20];
} ACCOUNT;

#endif // UTIL_H
