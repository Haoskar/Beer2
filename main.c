#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "read_one_lineRob.c"
#include "structinfo.h"

int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}

int main (void) {

    Vara *products = calloc(100,sizeof(Vara));
    Vara *start_of_products = products;
    bool valid_input;
    char test_string[20]; 
    char* end;
    int option;
    char tempString[256];
    //läs in varor från varor.csv till products arrayen
    products = Read();
    //Göra så products stå på korekt index
    while(products->varunummer != 0)
    products++;

    while(true){
        
        printf("\n---------------------------------------------------------\n");
        printf("1. Display contents sorted by varunummer\n");
        printf("2. Display contents sorted by namn\n");
        printf("3. Add a product\n");
        printf("4. Search\n");
        printf("5. Save to file\n");
        printf("6. Quit\n\n");

        option = 0;
        valid_input = false;
        do{
            printf("Enter a option (1-6): ");
            fgets(test_string, 20, stdin);
            if(test_string[0] == '\n')
                valid_input = false;
            else
                valid_input = isInt(test_string);
        }while(!valid_input);

        option = strtol(test_string, &end, 10);

        switch(option){
            case 1:
                printf("1Not implemented\n");
                printf("%i %s %f %f %s %s %s %s %s %f\n\n",products->varunummer,products->namn,products->pris,products->volym,products->typ,products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
                break;
            case 2:
                printf("2Not implemented\n");
                break;    
            case 3:
                //Varunummer
                printf("\nEnter varunummer: ");
                fgets(tempString,256,stdin);
                int i = 0;
                while(tempString[i] != '\n')
                    i++;
                tempString[i] = '\0';
                products->varunummer = atoi(tempString);

                printf("Enter namn: ");
                fgets(tempString,256,stdin);
                strcpy(products->namn,tempString);

                printf("Enter pris: ");
                fgets(tempString,256,stdin);
                products->pris = atof(tempString);
                
                printf("Enter volym: ");
                fgets(tempString,256,stdin);
                products->volym = atof(tempString);
                
                printf("Enter typ: ");
                fgets(tempString,256,stdin);
                strcpy(products->typ,tempString);
                
                printf("Enter stil: ");
                fgets(tempString,256,stdin);
                strcpy(products->stil,tempString);
                
                printf("Enter forpackning: ");
                fgets(tempString,256,stdin);
                strcpy(products->forpackning,tempString);
                
                printf("Enter land: ");
                fgets(tempString,256,stdin);
                strcpy(products->land,tempString);
                
                printf("Enter producent: ");
                fgets(tempString,256,stdin);
                strcpy(products->producent,tempString);
                
                printf("Enter alkoholhalt: ");
                fgets(tempString,256,stdin);
                products->alkoholhalt = atof(tempString);

                printf("\n\nYou have added: \n");
                printf("varunummer: %d\nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
                products->varunummer,products->namn,products->pris,products->volym,products->typ,
                products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
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