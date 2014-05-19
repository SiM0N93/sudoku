/* ============================================================================
 * Autoren:         Alexander Dormann
 * Klasse:          FA13
 * Dateiname:       sudoku/solver.c
 * Datum:           20.05.2014
 *
 * Beschreibung:    Stellt Funktionen zur Loesung eines Sudokus bereit
 *
 * ============================================================================
 */

#include "solver.h"
#include "../../util.h"

/*
 * ============================================================================
 * Globale Variablen
 * ============================================================================
 */
int iSudokuAnzahlLoesungen = 0;
int iSudokuLoesungen[SUDOKU_MAX_LOESUNGEN][SUDOKU_GROESSE][SUDOKU_GROESSE];



/* ============================================================================
 * Funktion:        _sudokuCheckForNumber
 * Beschreibung:    Prueft, ob sich eine bestimmte Ziffer iValue bereits
 *                  in der Reihe iRow, der Spalte iColumn oder dem dazu-
 *                  gehorigem 3x3-Feld befindet.
 *
 * Level:           Interne Funktion
 * Autor:           Dormann
 *
 * Input:           int     iColumn    Spaltenindex
 *                  int     iRow       Reihenindex
 *                  int     iValue     Zu suchender Wert
 *                  int[][] iSudoku    Zu durchsuchendes Sudoku
 *
 * Output:          int iResult
 *                  1 wenn Nummer bereits vorhanden
 *                  0 wenn nicht
 *
 * ============================================================================
 */
int _sudokuCheckForNumber(int iColumn, int iRow, int iValue,
                          int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int iResult = 0;

   if (_sudokuCheckColumnForValue(iColumn, iValue, iSudoku))
   {
      iResult = 1;
   }
   else if (_sudokuCheckRowForValue(iRow, iValue, iSudoku))
   {
      iResult = 1;
   }
   else if (_sudokuCheckFieldForValue(iColumn, iRow, iValue, iSudoku))
   {
      iResult = 1;
   }

   return iResult;
}

/* ============================================================================
 * Funktion:        _sudokuCheckRowForValue
 * Beschreibung:    Prueft, ob sich eine bestimmte Ziffer iValue bereits
 *                  in der Reihe iRow befindet.
 *
 * Level:           Interne Funktion
 * Autor:           Dormann
 *
 * Input:           int     iRow       Reihenindex
 *                  int     iValue     Zu suchender Wert
 *                  int[][] iSudoku    Zu durchsuchendes Sudoku
 *
 * Output:          int iResult
 *                  1 wenn Nummer bereits vorhanden
 *                  0 wenn nicht
 *
 * ============================================================================
 */
int _sudokuCheckRowForValue(int iRow, int iValue,
                            int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int i, iResult = 0;

   for (i = 0; i < SUDOKU_GROESSE; i++)
   {
      if (iSudoku[iRow][i] == iValue)
      {
         iResult = 1;
      }

   }

   return iResult;
}

/* ============================================================================
 * Funktion:        _sudokuCheckForNumber
 * Beschreibung:    Prueft, ob sich eine bestimmte Ziffer iValue bereits
 *                  in der Spalte iColumn befindet.
 *
 * Level:           Interne Funktion
 * Autor:           Dormann
 *
 * Input:           int     iColumn    Spaltenindex
 *                  int     iValue     Zu suchender Wert
 *                  int[][] iSudoku    Zu durchsuchendes Sudoku
 *
 * Output:          int iResult
 *                  1 wenn Nummer bereits vorhanden
 *                  0 wenn nicht
 *
 * ============================================================================
 */
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

/* ============================================================================
 * Funktion:        _sudokuCheckFieldForValue
 * Beschreibung:    Prueft, ob sich eine bestimmte Ziffer iValue bereits
 *                  in dem zu Reihe iRow und Spalte iColumn gehorigem 3x3-Feld
 *                  befindet.
 *
 * Level:           Interne Funktion
 * Autor:           Dormann
 *
 * Input:           int     iColumn    Spaltenindex
 *                  int     iRow       Reihenindex
 *                  int     iValue     Zu suchender Wert
 *                  int[][] iSudoku    Zu durchsuchendes Sudoku
 *
 * Output:          int iResult
 *                  1 wenn Nummer bereits vorhanden
 *                  0 wenn nicht
 *
 * ============================================================================
 */
int _sudokuCheckFieldForValue(int iColumn, int iRow, int iValue,
                              int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   int iCornerX, iCornerY, i, j;

   int iResult = 0;
   /* Anzahl Felder pro Sudokureihe */
   int iNumFields = (int)SUDOKU_GROESSE / SUDOKU_FIELD_COUNT_PER_ROW;

   /* Passendes 3x3-Feld zu Reihen und Spaltenindex ermitteln */
   iCornerX = (int)(iColumn / SUDOKU_FIELD_COUNT_PER_ROW) * iNumFields;
   iCornerY = (int)(iRow / SUDOKU_FIELD_COUNT_PER_ROW) * iNumFields;

   /* Pruefung, ob Wert bereits vorhanden: */
   for (i = iCornerY; i < iCornerY + iNumFields; i++)
   {
      for (j = iCornerX; j < iCornerX + iNumFields; j++)
      {
         if (iSudoku[i][j] == iValue)
         {
            iResult = 1;
         }
      }
   }

   return iResult;
}

/* ============================================================================
 * Funktion:        sudokuSolve
 * Beschreibung:    Befuellt iSudokuAnzahlLoesungen und iSudokuLoesungen mit
 *                  geloesten Sudokus des Parameters iSudoku.
 *
 *
 * Level:           Oeffentliche Funktion
 * Autor:           Dormann
 *
 * Input:           int[][] iSudoku  Zweidimensionaler Array aus Integern. Die
 *                                   Ziffer "0" stellt noch leere Felder dar.
 *                                   Beispiel:
 *                                     int iTest[SUDOKU_GROESSE][...] = {
 *                                        { 5, 3, 0, 0, 0, 0, 0, 0, 0 },
 *                                        { 6, 0, 0, 0, 9, 5, 3, 0, 0 },
 *                                        ...
 *                                        { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
 *                                     };
 *
 * Output:          Integer; 1 wenn das Sudoku geloest werden konnte, 0 wenn
 *                  nicht
 *
 * ============================================================================
 */
int sudokuSolve(int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   return _sudokuSolveWithIndex(0, 0, iSudoku, 0);
}

/* ============================================================================
 * Funktion:        sudokuIsSolveable
 * Beschreibung:    Ueberprueft ob ein gegebenes Sudoku loesbar ist.
 *
 *
 * Level:           Oeffentliche Funktion
 * Autor:           Dormann
 *
 * Input:           int[][] iSudoku  Zweidimensionaler Array aus Integern. Die
 *                                   Ziffer "0" stellt noch leere Felder dar.
 *                                   Beispiel:
 *                                     int iTest[SUDOKU_GROESSE][...] = {
 *                                        { 5, 3, 0, 0, 0, 0, 0, 0, 0 },
 *                                        { 6, 0, 0, 0, 9, 5, 3, 0, 0 },
 *                                        ...
 *                                        { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
 *                                     };
 *
 * Output:          Integer; 1 wenn das Sudoku geloest werden konnte, 0 wenn
 *                  nicht
 *
 * ============================================================================
 */
int sudokuIsSolveable(int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE])
{
   return _sudokuSolveWithIndex(0, 0, iSudoku, 1);
}


/* ============================================================================
 * Funktion:        _sudokuSolveWithIndex
 * Beschreibung:    Rekursive Funktion zur Loesung eines Sudokus. Testet pro
 *                  Feld jede Zahl einmal aus und schaut was passt.
 *
 *                  Erzeugt die Funktion ein geloestes Sudoku, so wird die
 *                  globale Variable iSudokuAnzahlLoesungen und legt das
 *                  geloeste Sudoku als Teil des Arrays iSudokuLoesungen ab.
 *
 *
 * Level:           Interne Funktion
 * Autor:           Dormann
 *
 * Input:           int     iColumn        Spaltenindex
 *                  int     iRow           Reihenindex
 *                  int[][] iSudoku        Zu durchsuchendes Sudoku
 *                  int     iSolveOnlyOnce Ziffer 1 wenn das Sudoku nur einmal
 *                                         geloest werden soll
 *
 * Output:          int iResult
 *                  1 wenn Sudoku geloest
 *                  0 wenn nicht
 *
 * ============================================================================
 */
int _sudokuSolveWithIndex(int iColumn, int iRow,
                          int iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE],
                          int iSolveOnlyOnce)
{
   int i;

   if (iColumn >= SUDOKU_GROESSE)
   {
      /* Zeilenende erreicht, springe in naechste Zeile */
      iRow++;
      iColumn = 0;

      /* Keine naechste Zeile? Dann ist das Sudoku geloest! */
      if (iRow >= SUDOKU_GROESSE)
      {
         return 1;
      }
   }

   /* Springe in das naechste Feld wenn das aktuelle nicht leer ist. */
   if (iSudoku[iRow][iColumn] > 0)
   {
      return _sudokuSolveWithIndex(iColumn + 1, iRow,
                                   iSudoku, iSolveOnlyOnce);
   }

   /* Ziffern 0 - 9 einsetzen und testen, ob dieser Zug moeglich ist. */
   for (i = 1; i <= SUDOKU_GROESSE; i++)
   {
      if (_sudokuCheckForNumber(iColumn, iRow, i, iSudoku) != 1) {
         /* Funktioniert! */
         iSudoku[iRow][iColumn] = i;

         if (_sudokuSolveWithIndex(
                  iColumn + 1, iRow, iSudoku, iSolveOnlyOnce
             ) && iSudokuAnzahlLoesungen < SUDOKU_MAX_LOESUNGEN)
         {
            /* Sudoku geloest? Loesungszahl erhoehen und Loesungsvariante
               speichern */
            _sudokuCopy(iSudokuAnzahlLoesungen, iSudoku);
            iSudokuAnzahlLoesungen++;

            /* Soll das Sudoku nur einmal geloest werden und dieser Punkt
               wird erreicht, kann die Rekursion aufgeloest werden */
            if( iSolveOnlyOnce == 1 )
            {
               return 1;
            }
         }
      }
   }

   iSudoku[iRow][iColumn] = 0;
   return 0;
}

/* ============================================================================
 * Funktion:        _sudokuDebugPrint
 * Beschreibung:    Gibt ein Sudoku zu Debugzwecken mithilfe von printf aus.
 *
 * Level:           Hilfsfunktion
 * Autor:           Dormann
 *
 * Input:           int[][] iSudoku    Auszugebendes Sudoku
 *
 * Output:          -
 *
 * ============================================================================
 */
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

/* ============================================================================
 * Funktion:        _sudokuCopy
 * Beschreibung:    Kopiert ein Sudoku in den Loesungsarray an Stelle iIndex
 *
 * Level:           Hilfsfunktion
 * Autor:           Dormann
 *
 * Input:           int     iIndex     Index, an dessen Stelle das Sudoku
 *                                     kopiert werden soll
 *                  int[][] iSudoku    Auszugebendes Sudoku
 *
 * Output:          -
 *
 * ============================================================================
 */
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
