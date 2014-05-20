#include "util.h"
#include "sudoku.h"

void generateSudoku(int matrix[SUDOKU_SIZE][SUDOKU_SIZE], int difficulty)
{
    int shuffled[SUDOKU_SIZE], a, b, numbersToReset=0;
    switch(difficulty)
    {
        case 1:
            /* easy */
            numbersToReset = 60;
            break;
        case 2:
            /* medium */
            numbersToReset = 70;
            break;
        case 3:
            /* hard */
            numbersToReset = 75;
            break;
        default:
            /* medium */
            numbersToReset = 70;
            break;
    }

    srand(time(0));

    /* create an empty sudoku */
    for (a=0; a<SUDOKU_SIZE; a++)
    {
        shuffled[a] = a+1;
        for (b=0; b<SUDOKU_SIZE; b++)
        {
            matrix[a][b] = 0;
        }
    }

    /* shuffle the sudoku cells */
    for (a=0; a<4; a++)
    {
        for (b=0; b<SUDOKU_SIZE; b++)
        {
            /* swap current cell with a random other cell */
            swap(&shuffled[b], &shuffled[RAND(SUDOKU_SIZE)]);
        }
    }

    /* place the shuffled numbers at random locations */
    for (a=0; a<SUDOKU_SIZE; a++)
    {
        matrix[a][RAND(SUDOKU_SIZE)] = shuffled[a];
    }
    /* solve the puzzle, take a random solution */
    solve(matrix, RAND(25));

    /* now remove random elements from the solved puzzle */
    for (a=0; a<numbersToRemove; a++)
    {
        matrix[RAND(SUDOKU_SIZE)][RAND(SUDOKU_SIZE)] = 0;
    }

    for (a=0; a<SUDOKU_SIZE; a++)
    {
        for (b=0; b<SUDOKU_SIZE; b++)
        {
            printf("%i", matrix[a][b]);
        }
        printf("\n");
    }
}

void swap(int *a_p, int *b_p) {
    int temp = *a_p;
    *a_p = *b_p;
    *b_p = temp;
}

/* wrapper for init recursive solving of the sudoku */
int solve(int matrix[SUDOKU_SIZE][SUDOKU_SIZE], int solutionnumber)
{
    int currentsolution = 0, depth = 0, maxdepth = 0;
    solveRecur(matrix, solutionnumber, &currentsolution, &depth, &maxdepth);
    return maxdepth;
}

/* try to solve the sudoku recursively */
int solveRecur(int matrix[SUDOKU_SIZE][SUDOKU_SIZE], int solutionnumber, int *currentsolution, int *depth, int *maxdepth)
{
    int i,j,k, result;

    (*depth)++;
    if (*depth>*maxdepth)
        *maxdepth=*depth;

    /* look for empty values, filling in numbers that are free (not yet used in row/col/region),
     * recursing and backtracking on failure */
    for (i=0; i<SUDOKU_SIZE; i++)
    {
        for (j=0; j<SUDOKU_SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (k=1; k<=SUDOKU_SIZE; k++)
                {
                    if (isFreeNumber(matrix, i, j, k))
                    {
                        matrix[i][j] = k;
                        if (solveRecur(matrix, solutionnumber, currentsolution, depth, maxdepth))
                        {
                            /* we have a winner! */
                            if (*currentsolution == solutionnumber)
                            {
                                result = 1;
                            }
                            else
                            {
                                (*currentsolution)++;
                                matrix[i][j] = 0;
                            }
                        }
                        else
                        {
                            matrix[i][j] = 0;
                        }
                    }
                }
                /* either no values were available or none of
                 * them yielded a correct solution, fail. */
                result = 0;
            }
        }
    }

    return result;
}

/* return true if the number is not yet used in the
 * same row, column and region of position x, y */
int isFreeNumber(int matrix[SUDOKU_SIZE][SUDOKU_SIZE], int x, int y, int number) {
    int i, xOffset=x-x%3, yOffset=y-y%3, result=1;
    for (i=0; i<SUDOKU_SIZE; i++) {
        /* row & col of x,y */
        if(matrix[i][y] == number || matrix[x][i] == number)
        {
            result = 0;
        }
        /* region */
        if (matrix[xOffset+i%3][yOffset+i/3] == number)
        {
            result = 0;
        }
    }
    return result;
}
