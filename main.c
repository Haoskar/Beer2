#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "read_one_lineRob.c"
#include "structinfo.h"
#include "savefile.c"



int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}

int is_float(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            if(string[i] != '.')
                return 0;   
    } 
    return 1;
}
void sort_by_varunummer();
Vara *search_varunummer(); //<- behövs
void sort_by_namn();
static int compare_string (Vara * a, Vara * b);
int  compare(Vara *, Vara *);
char * trimwhitespace(char *str);
Vara *products, *start_of_products,*end_of_products;
int number_of_products = 0;


//fixa en is_float funktion 
int main (void) {

    products = (Vara *) calloc(100,sizeof(Vara));
    bool valid_input;
    char test_string[20]; 
    char* end;
    int option;
    char tempString[256];
    //läs in varor från varor.csv till products arrayen
    products = Read();
    start_of_products = products;
    end_of_products = start_of_products;

    while(products->varunummer != 0){
        end_of_products++;
        number_of_products++;
        products++;
    };
    //Göra så products stå på korekt index
    
    FILE *skrivfil;
    char name_of_file_or_number[256];

    char badChars[] = "<>:|?*\\/\" \t"; //these are invalid characters for filnames
    bool invalid_found = false;
    char fileName[100] = "textdoc";
    int numInvalidChar = 0;

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
        char *search_word = "9";
        switch(option){
            case 1:
                sort_by_varunummer(products,number_of_products,compare,start_of_products);
                break;
            case 2:
                sort_by_namn(products, number_of_products, compare_string, start_of_products);
                break;    
            case 3:
                //Varunummer
                //products = end_of_products;
                printf("\nEnter varunummer: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0'; //en funktion som tarbort newline tecknet och ersätter med \0
                
                products = search_varunummer(tempString, products, number_of_products, start_of_products);
                if (products != NULL){
                    printf("\nVarunummer not uniqe, choose another varunummer next time");
                    break;
                }
                products = end_of_products;         //adding a new product, needs to point at end of array
                products->varunummer = atoi(tempString);

                printf("Enter namn: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                strcpy(products->namn,tempString);

                printf("Enter pris: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                products->pris = atof(tempString);
                
                printf("Enter volym: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                products->volym = atof(tempString);
                
                printf("Enter typ: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                strcpy(products->typ,tempString);
                
                printf("Enter stil: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                strcpy(products->stil,tempString);
                
                printf("Enter forpackning: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                strcpy(products->forpackning,tempString);
                
                printf("Enter land: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                strcpy(products->land,tempString);
                
                printf("Enter producent: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                strcpy(products->producent,tempString);
                
                printf("Enter alkoholhalt: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                products->alkoholhalt = atof(tempString);

                printf("\n\nYou have added: \n");
                printf("varunummer: %d\nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
                products->varunummer,products->namn,products->pris,products->volym,products->typ,
                products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
                number_of_products++;
                end_of_products++;
                printf("\n--\n");
                
                for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
                    //Använd %0.2f när du printar för att få två decimaler och så att float inte tar och visra sina felaktigheter :D
                    printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
                    products->varunummer,products->namn,products->pris,products->volym,products->typ,
                    products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
                    printf("--------------------------------------\n");
                }
                products = start_of_products;
                break;
            case 4: //hakar ibland upp sig
                printf("\nVarunummer to search: ");
                fgets(tempString,20, stdin);
                tempString[strlen(tempString) - 1] = '\0'; //removes newline char

                products = search_varunummer(tempString, products, number_of_products, start_of_products);
                if(products == NULL)
                    printf("\nThe number %s did not match any varunummer", tempString);
                else{
                    printf("\n%s, has the following information: \nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
                    tempString, products->namn,products->pris,products->volym,products->typ,products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt); //horrendous printf
                }
                products = start_of_products;
                break;
            case 5:

                do{
                    printf("Enter filename here: ");
                    fgets(fileName, 200, stdin);
                    invalid_found = false;
                    numInvalidChar = 0;
                    if(fileName[0] == '\n')                             //can't have '\n' in badChars array. 
                        invalid_found = true;
                    else {        
                        invalid_found = false; 
                        for (int i = 0; i < strlen(badChars); ++i) {    //compare filename to badChars
                            if (strchr(fileName, badChars[i]) != NULL){
                                invalid_found = true;
                                numInvalidChar++;
                                }
                        }
                    }
                    if(invalid_found)
                        printf("%d invalid character(s) found, please use another name. \n", numInvalidChar);
                }while(invalid_found);
                strtok(fileName, "\n");
                products = start_of_products;
                save_to_file(products,number_of_products,fileName);
                break;
            case 6:
                printf("Save to varor.csv before quitting?(y/n)");
                fgets(tempString, 5,stdin);
                //tempString[strlen(tempString - 1)] = '\0';
                strtok(tempString, "\n");
                //printf("::%s", tempString);
                if(strcmp(tempString, "y") == 0){
                    products = start_of_products;
                    save_to_file(products,number_of_products,"varor");
                    printf("done!");
                }

                printf("Good bye!\n");
                exit(0);
                break;
            default:
                printf("\nPlease enter a number between 1-6\n");

        }
    }

}

