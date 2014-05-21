#define _CRT_SECURE_NO_WARNINGS 1

#include "util.h"
#include "register.h"
#include "login.h"
#include "toplist.h"
#include "sudoku_gen.h"

#define MAIN_MENUE_SIZE 3
#define GAME_MENUE_SIZE 5

int LoadMainMenue(void);
void LoadGameMenue(ACCOUNT user);

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
	int m_Exit = 0;
	char mode[50];
	do
	{
	  resizeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	  m_Exit = LoadMainMenue( );
	} while(!m_Exit);
   
	system("cls");
   printf("\n\n\n\t\tWe hope you enjoyed your time. Visit us again!");
	printf("\n\n\n\n\n\n\n\n\n\n\n\nPress a key to exit");
	getchar();
   return 0;
}

int LoadMainMenue(void) {
	int iStatus = 0, iTemp = 1, i, m_Exit=0;
   char *cMenu[MAIN_MENUE_SIZE] = { "Register        ", "Login           ", "Exit            "};
   ACCOUNT user;

   //createBorder();
	//createBlock(28);
   do
   {
		system("cls");
		printf("\t\tM E N U E\n");
		printf("\t= = = = = = = = = = = = =\n\n");

		for (i = 0; i < MAIN_MENUE_SIZE; i++)
		{
			if (i == iTemp-1)
			{
				printf("\t%c\t%s%c\n", 16, cMenu[i], 17);
			}
			else
			{
				printf("\t\t%s\n", cMenu[i]);
			}
		}

		iStatus = control();

		if (iStatus == 2) 
		{
			if (iTemp > 1) 
			{
				iTemp--;
			}
		}
		else if (iStatus == 3) 
		{
			if (iTemp < MAIN_MENUE_SIZE && iTemp > 0)
			{
				iTemp++;
			}
		}
   } while (iStatus != 6);

   system("cls");

   switch(iTemp) 
   {
		case 1:
			registrierung();
			system("cls");
		break;
		case 2:
			user = login();
			system("cls");
			if( user.FirstName=="" )
			{
				printf("\n\n\n\nError, couldn't log in, the game will shut down automatically now.");
				m_Exit = 1;
				getchar( );
			}
			else
			{
				LoadGameMenue(user);
			}
		break;
		default:
			m_Exit=1;
			break;
   }
	return m_Exit;
}

void LoadGameMenue(ACCOUNT user) {
	int iStatus = 0, iTemp = 1, iLength = 0, i, m_Exit = 0;
   char *cMenu[GAME_MENUE_SIZE] = { "Play Sudoku     ", 
												"How To Play     ", 
												"Top List        ",
												"Settings        ",
												"Exit            "};
	if(user.WindowHeight!=0 && user.WindowWidth!=0) {
	  resizeWindow(user.WindowWidth, user.WindowHeight);
	}

   //createBorder();
   do
   {
		system("cls");
		printf("\t\tG A M E M E N U E\n");
		printf("\t= = = = = = = = = = = = =\n\n");
		for (i = 0; i < GAME_MENUE_SIZE; i++)
		{
			if (i == iTemp-1)
			{
				printf("\t%c\t%s%c\n", 16, cMenu[i], 17);
			}
			else
			{
				printf("\t\t%s\n", cMenu[i]);
			}
		}

		iStatus = control();

		if (iStatus == 2) 
		{
			if (iTemp > 1) 
			{
				iTemp--;
			}
		}
		else if (iStatus == 3) 
		{
			if (iTemp < GAME_MENUE_SIZE && iTemp > 0)
			{
				iTemp++;
			}
		}
   } while (iStatus != 6);

	switch(iTemp) 
   {
		case 1:
			//LoadDifficultyMenue();
		break;
		case 2:
			//HowToPlay();
		break;
		case 3:
			toplist();
		break;
		case 4:
			//loadSettings();
		break;
		default:
			m_Exit = 1;
		break;
   }
}