#include "util.h"
#include "register.h"
#include "login.h"

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
	int status=0;
	status = login();
	fflush(stdin);
   getchar();
   return 0;
}
