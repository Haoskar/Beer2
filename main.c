#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void) {
    bool validInput = false;
    char testString[20]; 
    
    do{
        printf("Enter a option (1-6): ");//have tested a maximum of 1 500 000 rows, taking up ~ 55 Mb of space
        fgets(testString, 20, stdin);
        if(testString[0] == '\n')
            validInput = false;
        else
            validInput = isInt(testString);
    }while(!validInput);
}