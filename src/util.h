#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>

#include "included/printing.h"
#include "included/password.h"
#include "database_connection.h"
#include "lib/sudoku/solver.h"
#include "control.h"

/* DEBUG: 0 - Keine Meldungen 1 - Debugmeldungen*/
#define DEBUG 1

void DEBUG_Log(char *text);
int getArraySizeForChar( char *Array );
int getRowCountSize( MYSQL_ROW ROW );
int getArraySizeForInt( int *Array );

typedef struct account
{
    char FirstName[25];
    char LastName[25];
    char UserName[20];
} ACCOUNT;

#endif /* UTIL_H */
