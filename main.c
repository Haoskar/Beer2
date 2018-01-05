#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"

struct Vara{
    int varunummer;
    char namn[100];
    float pris;
    float volym;
    char typ[100];
    char stil[100];
    char forpackning[20];
    char land[20];
    char producent[50];
    float alkoholhalt;
};

int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}

int main (void) {

    bool validInput;
    char testString[20]; 
    char* end;
    int option;
    struct Vara nyVara;
    int v;
    char tempString[100];
    float tempFloat;
   
    while(true){
        
        printf("\n---------------------------------------------------------\n");
        printf("1. Display contents sorted by varunummer\n");
        printf("2. Display contents sorted by namn\n");
        printf("3. Add a product\n");
        printf("4. Search\n");
        printf("5. Save to file\n");
        printf("6. Quit\n\n");

        option = 0;
        validInput = false;
        do{
            printf("Enter a option (1-6): ");
            fgets(testString, 20, stdin);
            if(testString[0] == '\n')
                validInput = false;
            else
                validInput = isInt(testString);
        }while(!validInput);

        option = strtol(testString, &end, 10);

        switch(option){
            case 1:
                printf("1Not implemented\n");
                break;
            case 2:
                printf("2Not implemented\n");
                break;    
            case 3:
                printf("\nEnter varunummer: ");
                gets(tempString);
                nyVara.varunummer = strtol(tempString, end, NULL);
                printf("Enter namn: ");
                gets(nyVara.namn);
                printf("Enter pris: ");
                gets(tempString);
                nyVara.pris = strtof(tempString, NULL);
                printf("Enter volym: ");
                gets(tempString);
                nyVara.volym = strtof(tempString, NULL);
                printf("Enter typ: ");
                gets(nyVara.typ);
                printf("Enter stil: ");
                gets(nyVara.stil);
                printf("Enter forpackning: ");
                gets(nyVara.forpackning);
                printf("Enter land: ");
                gets(nyVara.land);
                printf("Enter producent: ");
                gets(nyVara.producent);
                printf("Enter alkoholhalt: ");
                gets(tempString);
                nyVara.alkoholhalt = strtof(tempString, NULL);

                printf("\n\nYou have added: \n");
                printf("varunummer: %d\nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
                nyVara.varunummer, nyVara.namn, nyVara.pris, nyVara.volym, 
                nyVara.typ, nyVara.stil, nyVara.forpackning, nyVara.land, nyVara.producent, nyVara.alkoholhalt);
                break;
            case 4:
                printf("4Not implemented\n");
                break;
            case 5:
                printf("5Not implemented\n");
                break;
            case 6:
                printf("Good bye!\n");//Implement save to file
                exit(0);
                break;
            default:
                printf("Something went wrong");

        }
    }

}