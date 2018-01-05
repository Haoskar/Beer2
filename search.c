#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"
#include "read_one_lineRob.c"

int main (void) {
    char *search_word = "9", *end;
    char temporary_string[10];
    bool match_found = false;


    Vara *products = calloc(100,sizeof(Vara));
    Vara *start_of_products = products;
    products = Read();

    //printf("%i", products->varunummer);
    printf("\nVarunummer to search: ");
    fgets(search_word,20, stdin);
    search_word[strlen(search_word) - 1] = '\0';                //removes newline char

    for(int i = 0; i < 16; i++){                   //ändra 16 till något bättre
        sprintf(temporary_string, "%d", products->varunummer);  //convert current structs varunummer to string
        //printf("\n%s", temporary_string);
        if (strcmp(search_word, temporary_string) == 0) {       //compare strings
            printf("\n%s, has the name %s", search_word, products->namn);
            match_found = true;
            break;
        }  
        else
            products++;     //move over to next struct
    }
    if(!match_found)
        printf("\nThe number %s did not match any varunummer", search_word);
    
        return 0;
}