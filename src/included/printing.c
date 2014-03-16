#include "printing.h"

/**
 * =============================================================================
 * Funktion gotoxy
 * ===============
 * Allows to set the current cursor to a specific point in the console. This is
 * normally a UNIX build in command from gcc, we have just copied it here to the
 * usage.
 * This function is only possible with including 'windows.h', our platform is
 * project is only made for Win OS
 *
 * @brief gotoxy
 * @param x
 * @param y
 * @return locate the curser to a specific position
 *
 * =============================================================================
 */
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void createBlock( int height )
{
    int i=0, n=0;
    for(i=0;i<=height;i++) {
        for(n=0; n<200; n++) {
            if(i==0 && n==0) {
                printf("%c", 218);
            } else if(i==0 && n == 199)  {
                printf("%c", 191);
            } else if(i==0) {
                printf("%c", 196);
            } else if( i != height ) {
                if(n==0 || n==199)
                      printf("%c", 179);
                else
                    printf(" ");
            } else if( n==0) {
                printf("%c", 192);
            } else if( n==199) {
                printf("%c", 217);
            } else {
                printf("%c", 196);
            }
        }
    }
    return;
}
