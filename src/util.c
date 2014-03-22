#include "util.h"

/* =============================================================================
* Funktion:        output
* Input:           -
* Output:          -
*
* Beschreibung:    Output fuer eventuelle Fehlerund Debugausgaben.
* ==============================================================================
*/
void output(char *text, int debug)
{
    if (debug == 1)
    {
        printf("\n[Debug] %s\n", text);
    }
	 getchar();
    return;
}