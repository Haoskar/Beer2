#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"
#ifndef ____OTHERF____
#define ____OTHERF____

int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}

int is_float(char *string){
    int dots = 0;
    for(int i = 0; i < strlen(string) - 1; i++){
        if(string[i] == '.'){
            dots++;
        }
        if(!isdigit(string[i]) || dots > 1){
            return 0;
        }
    } 
    return 1;
}

int compare(Vara *elem1, Vara *elem2)
{
   if (elem1->varunummer < elem2->varunummer)
      return -1;
   else if (elem1->varunummer > elem2->varunummer)
      return 1;
   else
      return 0;
}

static int compare_string (Vara *elem1, Vara *elem2)
{
    return strcmp (elem1->namn, elem2->namn);
}

#endif