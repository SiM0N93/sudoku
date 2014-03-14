#include "util.h"
#include "register.h"


/* ============================================================================
* Funktion:        main
* Input:           -
* Output:          int
*
* Beschreibung:    Funktionsaufrufe für Registrierung.
* ============================================================================
*/
int main(void)
{
    /* Funktionsaufruf fuer registrierung */
    registrierung();

    /* Eingabespeicher leeren und pausieren */
    fflush(stdin);
    getchar();
    return 0;
}
