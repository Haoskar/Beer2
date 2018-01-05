#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        //printf("Det jag skrev %c", string[i]); --- debugging
        if(!isdigit(string[i]) || string[i] == 0)// || string[i] == '\n' || string[i] == NULL)
            return 0;
    } 
    return 1;
}

int main (void) {

    bool validInput;
    char testString[20]; 
    char* end;
    int option;
   
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
                printf("3Not implemented\n");
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