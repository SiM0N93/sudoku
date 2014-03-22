#define _CRT_SECURE_NO_WARNINGS 1

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
	ACCOUNT user;
	do
	{
		printf("M E N U E\n");
		printf("= = = = =");
		printf("\n1. Register\n2. Login\n3. Exit\n\nInput: ");
		iSuccessEingabe = scanf("%i", &iEingabe );
		fflush(stdin);
		if( iEingabe == 1 ) {
			registrierung();
			system("cls");
		}
	} while( iSuccessEingabe == 0 || iEingabe < 1 || iEingabe > 3 );

	 if( iEingabe == 2 ) {
		user = login();
		system("cls");
		if( user.FirstName=="" )
			printf("Error. Couldnt log in.\n\n\n\n");
		else
			printf("Successfully logged in.\nWelcome %s!\n\n\n", user.UserName);
	}
	 if(iEingabe != 3 )
	   getchar();

   return 0;
}
