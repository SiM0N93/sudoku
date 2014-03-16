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
