#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <string.h>

#include "included/printing.h"

#define _CRT_SECURE_NO_WARNINGS
/* DEBUG: 0 - Keine Meldungen 1 - Debugmeldungen*/
#define DEBUG 1

void output(char *text, int debug);

#endif // UTIL_H
