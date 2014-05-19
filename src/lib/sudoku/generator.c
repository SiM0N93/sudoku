/* ============================================================================
* Autoren:         Alexander Dormann
* Klasse:          FA13
* Dateiname:       sudoku/generator.c
* Datum:           20.05.2014
*
* Beschreibung:    Stellt Funktionen zur Erzeugung eines Sudokus bereit
*
* ============================================================================
*/

#include "generator.h"
#include "../../util.h"

/*
* ============================================================================
* Globale Variablen
* ============================================================================
*/
int iRandomSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];
int iFullGeneratedSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];
int iGeneratedSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];

void generateSudoku( int iDifficulty )
{
	/*while(iSudokuAnzahlLoesungen < 1)
	{
		_generateSudoku(FIELDS_TO_FILL_IN_GENERATION);
		sudokuIsSolveable(iRandomSudoku);
	}

	_sudokuCopyToHolder(iSudokuLoesungen[0]);*/
	_generateSudoku(81);
	//_sudokuCopyToHolder(iRandomSudoku);

	//_sudokuBlankFields( iDifficulty );
}

void _sudokuBlankFields( int iDifficulty )
{
	int iRow, iColumn, iZeroedFields = 0;

	while (iZeroedFields < iDifficulty)
	{
		iRow    = rand() % ( SUDOKU_GROESSE + 1 );
		iColumn = rand() % ( SUDOKU_GROESSE + 1 );

		if ( iGeneratedSudoku[iRow][iColumn] != 0 )
		{
			iGeneratedSudoku[iRow][iColumn] = 0;
			iZeroedFields++;
		}
	}
}

void _generateSudoku(int iFillFields)
{
	int iRow, iColumn, iNumber, iFilledFields = 0;

	srand(time(NULL));
	_sudokuFillWithZeros();

	while (iFilledFields < iFillFields)
	{
		iRow    = rand() % ( SUDOKU_GROESSE + 1 );
		iColumn = rand() % ( SUDOKU_GROESSE + 1 );
		iNumber = rand() % ( SUDOKU_GROESSE + 1 );

		//_sudokuCopyToTemp();

		if ( iRandomSudoku[iRow][iColumn] == 0 && _sudokuCheckForNumber(iColumn, iRow, iNumber, iRandomSudoku) != 1 )
		{
			iRandomSudoku[iRow][iColumn] = iNumber;
			iFilledFields++;
		}
	}
}

void _sudokuFillWithZeros()
{
	int i, j;
	for (i = 0; i < SUDOKU_GROESSE; i++) {
		for (j = 0; j < SUDOKU_GROESSE; j++) {
			iRandomSudoku[i][j] = 0;
		}
	}

}

void _sudokuCopyToHolder(int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
	int i, j;
	for (i = 0; i < SUDOKU_GROESSE; i++) {
		for (j = 0; j < SUDOKU_GROESSE; j++) {
			iFullGeneratedSudoku[i][j] = iSudoku[i][j];
		}
	}

}
