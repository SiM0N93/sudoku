#define _CRT_SECURE_NO_WARNINGS 1

#include "util.h"
#include "register.h"
#include "login.h"
#include "toplist.h"

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
	int iTest[SUDOKU_GROESSE][SUDOKU_GROESSE] = {
		{ 5, 3, 0, 0, 0, 0, 0, 0, 0 },
		{ 6, 0, 0, 0, 9, 5, 3, 0, 0 },
		{ 0, 9, 8, 0, 0, 0, 0, 6, 0 },
		{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
		{ 4, 0, 0, 0, 0, 3, 0, 0, 1 },
		{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
		{ 0, 6, 0, 0, 0, 0, 2, 8, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 5 },
		{ 0, 0, 0, 0, 8, 0, 0, 7, 9 }
	};
	/*
	int iTest[SUDOKU_GROESSE][SUDOKU_GROESSE] = {
	{ 5, 3, 0, 0, 0, 0, 0, 0, 0 },
	{ 6, 0, 0, 1, 9, 5, 3, 0, 0 },
	{ 0, 9, 8, 0, 0, 0, 0, 6, 0 },
	{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
	{ 4, 0, 0, 8, 0, 3, 0, 0, 1 },
	{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
	{ 0, 6, 0, 0, 0, 0, 2, 8, 0 },
	{ 0, 0, 0, 4, 1, 9, 0, 0, 5 },
	{ 0, 0, 0, 0, 8, 0, 0, 7, 9 }
	};*/

	//_sudokuDebugPrint(iTest);

	generateSudoku( 20 );
	_sudokuDebugPrint(iRandomSudoku);
	//_sudokuDebugPrint(iFullGeneratedSudoku);
	//_sudokuDebugPrint(iGeneratedSudoku);

	printf("\n\n");

	sudokuSolve(iRandomSudoku);
	printf("%i Loesungen gefunden", iSudokuAnzahlLoesungen);

	system("pause");
	return 0;
}
