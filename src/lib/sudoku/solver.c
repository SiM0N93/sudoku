/* ============================================================================
* Autoren:         Alexander Dormann
* Klasse:          FA13
* Dateiname:       sudoku/solver.c
* Datum:           20.05.2014
*
* Beschreibung:    Stellt Funktionen zur Loesung eines Sudokus bereit
*
* =============================================================================
*/

#include "../../util.h"
#include "solver.h"
#include "string.h"

int iSudokuAnzahlLoesungen = 0;
int iSudokuLoesungen[SUDOKU_MAX_LOESUNGEN][SUDOKU_GROESSE][SUDOKU_GROESSE];

int _sudokuCheckForNumber(int iColumn, int iRow, int iValue,
                          int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int iResult = 0;

   if (_sudokuCheckRowForValue(iRow, iValue, iSudoku))
   {
      iResult = 1;
   }
   else if (_sudokuCheckColumnForValue(iColumn, iValue, iSudoku))
   {
      iResult = 1;
   }
   else if (_sudokuCheckFieldForValue(iColumn, iRow, iValue, iSudoku))
   {
      iResult = 1;
   }

   return iResult;
}

int _sudokuCheckRowForValue(int iRow, int iValue,
                            int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int i, iResult = 0;

   for (i = 0; i < SUDOKU_GROESSE; i++)
   {
      if (iSudoku[iRow][i] == iValue)
         iResult = 1;
   }

   return iResult;
}

int _sudokuCheckColumnForValue(int iColumn, int iValue,
                               int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int i, iResult = 0;

   for (i = 0; i < SUDOKU_GROESSE; i++)
   {
      if (iSudoku[i][iColumn] == iValue)
      {
         iResult = 1;
      }
   }

   return iResult;
}

int _sudokuCheckFieldForValue(int iColumn, int iRow, int iValue,
                              int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int iCornerX, iCornerY, i, j;

   int iResult = 0;
   int iNumFieldsPerRow = (int)SUDOKU_GROESSE / SUDOKU_FIELD_COUNT_PER_ROW;

   /* Passende Ecke des Feldes ermitteln */
   iCornerX = (int)(iColumn / SUDOKU_FIELD_COUNT_PER_ROW) * iNumFieldsPerRow;
   iCornerY = (int)(iRow / SUDOKU_FIELD_COUNT_PER_ROW) * iNumFieldsPerRow;

   for (i = iCornerY; i < iCornerY + 3; i++)
   {
      for (j = iCornerX; j < iCornerX + 3; j++)
      {
         if (iSudoku[i][j] == iValue)
         {
            iResult = 1;
         }
      }
   }

   return iResult;
}

int sudokuSolve(int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   return _sudokuSolveWithIndex(0, 0, iSudoku);
}

int _sudokuSolveWithIndex(int iColumn, int iRow,
                          int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int i;
   if (iColumn >= SUDOKU_GROESSE)
   {
      iRow++;
      iColumn = 0;

      if (iRow >= SUDOKU_GROESSE)
      {
         return 1;
      }
   }

   if (iSudoku[iRow][iColumn] > 0)
   {
      return _sudokuSolveWithIndex(iColumn + 1, iRow, iSudoku);
   }

   for (i = 1; i <= SUDOKU_GROESSE; i++)
   {
      if (_sudokuCheckForNumber(iColumn, iRow, i, iSudoku) != 1) {
         iSudoku[iRow][iColumn] = i;

         if (_sudokuSolveWithIndex(iColumn + 1, iRow, iSudoku) &&
             iSudokuAnzahlLoesungen < SUDOKU_MAX_LOESUNGEN)
         {
            _sudokuDebugPrint(iSudoku);
            _sudokuCopy(iSudokuAnzahlLoesungen, iSudoku);
            iSudokuAnzahlLoesungen++;
         }
      }
   }

   iSudoku[iRow][iColumn] = 0;
   return 0;
}

void _sudokuDebugPrint(int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]) {
   int i, j;
   for (i = 0; i < SUDOKU_GROESSE; i++) {
      for (j = 0; j < SUDOKU_GROESSE; j++) {
         printf("%d ", iSudoku[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

void _sudokuCopy(int iIndex, int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int i, j;
   for (i = 0; i < SUDOKU_GROESSE; i++)
   {
      for (j = 0; j < SUDOKU_GROESSE; j++)
      {
         iSudokuLoesungen[iIndex][i][j] = iSudoku[i][j];
      }
   }
}