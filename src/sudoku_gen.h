#ifndef SUDOKU_GEN
#define SUDOKU_GEN

/* Prototypen */
void generateSudoku(int matrix[SUDOKU_SIZE][SUDOKU_SIZE], int difficulty);
void swap(int *a_p, int *b_p);
int solve(int[][SUDOKU_SIZE], int);
int solveRecur(int[][SUDOKU_SIZE], int, int *, int *, int *);
int isFreeNumber(int[][SUDOKU_SIZE], int, int, int);


#endif // SUDOKU_GEN
