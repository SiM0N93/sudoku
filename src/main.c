#include "util.h"
#include "register.h"

void resize(void);
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
    rezise ();

    fflush(stdin);
    getchar();
    return 0;
}


void rezise(void)
{
   /* mode 200 means the console window is 200 lines * 200 chars on the size
    * this is enough for us to rezise. We do not care the 200 lines are too much
    * it doesnt affect us */
    system("mode 200");
    return;
}
