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
	int status=0, iEingabe=0, iSuccessEingabe=0;
	do
	{
		printf("M E N U E\n");
		printf("= = = = =");
		printf("\n1. Register\n2.Login\n3.Beenden\n");
		iSuccessEingabe = scanf("%i", &iEingabe );
		fflush(stdin);
		if( iEingabe == 1 ) {
			registrierung();
			system("cls");
		}
	} while( iSuccessEingabe == 0 || iEingabe < 1 || iEingabe > 3 );

	 if( iEingabe == 2 ) {
		status = login();
		system("cls");
		if( status==0)
			printf("Error. Couldnt log in.\n\n\n\n");
		else
			printf("Successfully logged in.\n\n\n\n");
	}
	
   getchar();
   return 0;
}
