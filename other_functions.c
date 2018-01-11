#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"
#ifndef ____OTHERF____
#define ____OTHERF____
/*denna funktionen måste användas med en sträng som har 1 tecken i slutet av stängen som man inte läsa
 *detta p.g.a att den läser till mindre än strlen - 1*/
int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}
/* denna funktion måste bara användas med en sträng som bara har float delen alltså man måste ta bort
 *sådana tecken man inte vill ha innan man använder funktionen 
 *p.g.a att den läser till mindre än strlen*/
int is_float(char *string){
    int dots = 0;
    for(int i = 0; i < strlen(string) ; i++){
        if(string[i] == '.'){
            dots++;
            i++;
        }
        if(!(isdigit(string[i])) || dots > 1){
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

char *trimwhitespace(char *str)
{
  //se så det inte är någon mellanslag i 
  while(isspace((unsigned char)*str)) str++;
	//se så det inte är någon mellanslag i så fall retunera stringen
  if(!(isspace((unsigned char)*str)))  
    return str;
}
#endif