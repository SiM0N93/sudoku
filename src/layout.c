//#include "layout.h"
#include <stdlib.h>
#include <stdio.h>



void createBorder (){
	//char s  w = 9472;
	int i, j;
	int height = 200;
	int width = 200;
	
	printf("\n");
	printf("\t   _____           _       _          \n");
	printf("\t  / ____|         | |     | |         \n");
	printf("\t | (___  _   _  __| | ___ | | ___   _ \n");
	printf("\t  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |\n");
	printf("\t  ____) | |_| | (_| | (_) |   <| |_| |\n");
	printf("\t |_____/ \\__,_|\\__,_|\\___/|_|\\_\\__,__|\n\n");
	printf("\t= = = = = = = = = = = = = = = = = = = =\n\n");
	printf("\n");
	
	for(i=0; i<=width; i++) {
		for(j=0; j<height; j++) {
			if(i==0 && j==0) {
                printf("%c", 218);
            } else if(i==0 && j == 199)  {
                printf("%c", 191);
            } else if(i==0) {
                printf("%c", 196);
            } else if( i != height ) {
                if(j==0 || j==199)
                    printf("%c", 179);
                else
                    printf(" ");
            } else if( j==0) {
                printf("%c", 192);
            } else if( j==199) {
                printf("%c", 217);
            } else {
                printf("%c", 196);
            }
        }
    }
    return;
}
