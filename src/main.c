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
        printf("\t\tM E N U E\n");
        printf("\t\t= = = = =\n");
        printf("\n\t\t1. Register\n\t\t2. Login\n\t\t3. Exit\n\nInput: ");
        iSuccessEingabe = scanf("%i", &iEingabe );
        fflush(stdin);
        if( iEingabe == 1 ) {
            registrierung();
            system("cls");
        }
    } while( iSuccessEingabe == 0 || iEingabe < 1 || iEingabe > 3 );

    if( iEingabe == 2 ) 
    {
        user = login();
        system("cls");
        if( user.FirstName=="" )
            printf("Error. Couldnt log in.\n\n\n\n");
        else
            printf("Successfully logged in.\nWelcome %s!\n\n\n", user.UserName);
    }
   if (iEingabe != 3)
   {
      getchar();
   }
        
    return 0;
}
