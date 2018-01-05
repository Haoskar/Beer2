#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"

int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}

int main (void) {

    Vara *varor = calloc(100,sizeof(Vara));
    bool validInput;
    char testString[20]; 
    char* end;
    int option;
    Vara nyVara;
    int v;
    char tempString[256];
    float tempFloat;
    varor = Read();
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
                for(int i = 0; i < 16; i++){
                printf("%i %s %f %f %s %s %s %s %s %f\n\n",varor->varunummer,varor->namn,varor->pris,varor->volym,varor->typ,varor->stil,varor->forpackning,varor->land,varor->producent,varor->alkoholhalt);
                varor++;
                }
                break;
            case 2:
                printf("2Not implemented\n");
                break;    
            case 3:
                //Varunummer
                printf("\nEnter varunummer: ");
                fgets(tempString,256,stdin);
                varor->varunummer = atoi(tempString);

                printf("Enter namn: ");
                fgets(tempString,256,stdin);
                strcpy(varor->namn,tempString);

                printf("Enter pris: ");
                fgets(tempString,256,stdin);
                varor->pris = atof(tempString);
                
                printf("Enter volym: ");
                fgets(tempString,256,stdin);
                varor->volym = atof(tempString);
                
                printf("Enter typ: ");
                fgets(tempString,256,stdin);
                strcpy(varor->typ,tempString);
                
                printf("Enter stil: ");
                fgets(tempString,256,stdin);
                strcpy(varor->stil,tempString);
                
                printf("Enter forpackning: ");
                fgets(tempString,256,stdin);
                strcpy(varor->forpackning,tempString);
                
                printf("Enter land: ");
                fgets(tempString,256,stdin);
                strcpy(varor->land,tempString);
                
                printf("Enter producent: ");
                fgets(tempString,256,stdin);
                strcpy(varor->producent,tempString);
                
                printf("Enter alkoholhalt: ");
                fgets(tempString,256,stdin);
                varor->alkoholhalt = atof(tempString);

                printf("\n\nYou have added: \n");
                printf("varunummer: %d\nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
                varor->varunummer,varor->namn,varor->pris,varor->volym,varor->typ,
                varor->stil,varor->forpackning,varor->land,varor->producent,varor->alkoholhalt);
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