#ifndef SUDOKU_GENERATOR_H
#define SUDOKU_GENERATOR_H

#include "solver.h"
#include <time.h>
#include <stdlib.h>


#define FIELDS_TO_FILL_IN_GENERATION 10

extern int iRandomSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];
extern int iTempSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];
extern int iFullGeneratedSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];
extern int iGeneratedSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE];


/* ============================================================================
* Prototypen
* ============================================================================
*/
void generateSudoku(int iDifficulty);
void _sudokuBlankFields(int iDifficulty);
void _generateSudoku(int iFillFields);
void _sudokuFillWithZeros();
void _sudokuCopyToHolder();




#endif /* SUDOKU_GENERATOR_H */
