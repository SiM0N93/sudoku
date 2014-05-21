#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "included/printing.h"
#include "included/password.h"
#include "included/control.h"
#include "layout.h"
#include "database_connection.h"
#include "lib/sudoku/solver.h"

/* DEBUG: 0 - Keine Meldungen 1 - Debugmeldungen*/
#define DEBUG 1
#define SUDOKU_SIZE 9
#define RAND(max) (int)(((float)rand() / RAND_MAX) * max)
#define WINDOW_WIDTH 120
#define WINDOW_HEIGHT 50

void DEBUG_Log(char *text);
int getArraySizeForChar( char *Array );
int getRowCountSize( MYSQL_ROW ROW );
int getArraySizeForInt( int *Array );
void resizeWindow(int width, int height );

int UTIL_ToInt( char input );

typedef struct account
{
    char FirstName[25];
    char LastName[25];
    char UserName[20];
	 int WindowWidth;
	 int WindowHeight;
} ACCOUNT;

#endif /* UTIL_H */
