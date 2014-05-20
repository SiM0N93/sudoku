#define _CRT_SECURE_NO_WARNINGS 1

#include "util.h"
#include "register.h"
#include "login.h"
#include "toplist.h"
#include "sudoku_gen.h"

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
   int iStatus = 0, iTemp = 1, iLength = 0, i;
   char cAuswahl, *cMenu[5] = { "Register", "Login", "Bestenliste", "Exit"};
   ACCOUNT user;

   iLength = getArraySizeForChar(*cMenu);
   createBorder();
   do
   {
   system("cls");
   //system("mode con cols=100 lines=70");
   printf("\t\tM E N U E\n");
   printf("\t= = = = = = = = = = = = =\n\n");

   for (i = 0; i <= iLength; i++)
   {
      if (i == iTemp-1)
      {
         printf("\t%c\t%s\n", 16, cMenu[i]);
      }
      else
      {
         printf("\t\t%s\n", cMenu[i]);
      }
   }
   cAuswahl = _getch();
   iStatus = control(cAuswahl);

   if (iStatus == 2) 
   {
      if (iTemp > 1) 
      {
         iTemp--;
      }
   }
   else if (iStatus == 3) 
   {
      if (iTemp < iLength+1 && iTemp > 0)
      {
         iTemp++;
      }
   }

   } while (iStatus != 6);

   system("cls");

   if(iTemp == 1) 
   {
      registrierung();
      system("cls");
   }
   if(iTemp == 2) 
   {
      user = login();
      system("cls");
      if( user.FirstName=="" )
         printf("Error. Couldnt log in.\n\n\n\n");
      else
         printf("Successfully logged in.\nWelcome %s!\n\n\n", user.UserName);
   }
   if (iTemp == 3)
   {
      toplist();
      system("cls");
   }
   if (iTemp == 4)
   {
      
   }
        
	getchar();
    return 0;
}