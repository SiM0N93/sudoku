#include "password.h"

#include "../util.h"
#include <conio.h>
#include <math.h>

void GetPassword( char password[] ) {
	 int c = ' ',i=0;
    do   //Loop until 'Enter' is pressed
    {
        c = _getch();
        switch(c)
        {
            case 0:
            {
                _getch();
                break;
            }
            case '\b':
            {
                if(i != 0)  //If the password string contains data, erase last character
                {
                    printf("\b \b");
                    i--;
                    password[i] = *"";
                }
                break;
            }
            default:
            {
                if(isalnum(c) || ispunct(c))
                {
                    password[i]=c;
                    printf("*");
                    i++;
                }
                break;
            }
        };
    }
    while(c != '\r');
}
