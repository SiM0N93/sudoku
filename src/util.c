#include "util.h"

/* =============================================================================
* Funktion:        output
* Input:           -
* Output:          -
*
* Beschreibung:    Output fuer eventuelle Fehlerund Debugausgaben.
* ==============================================================================
*/
void DEBUG_Log(char *text)
{
    if (DEBUG == 1)
    {
        printf("\n[Debug] %s\n", text);
    }
    return;
}

int getArraySizeForChar( char *Array ) {
    int Size = sizeof(Array) / sizeof(char);
    return Size-1;
}
int getRowCountSize( MYSQL_ROW ROW ) {
    int Size = sizeof(ROW) / sizeof(char);
    return Size-1;
}

int getArraySizeForInt( int *Array ) {
    int Size = sizeof(Array) / sizeof(int);
    return Size;
}

void resizeWindow(int width, int height ) {
	char mode[50];
	sprintf(mode, "mode con cols=%i lines=%i", width, height);
	system(mode);
}

int UTIL_ToInt( char input ) {
	int a = input - '0';
	return a;
}