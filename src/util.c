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
int getArraySizeForInt( int *Array ) {
	int Size = sizeof(Array) / sizeof(int);
   return Size;
}
