#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {
   char buffer[512];
   printf("Meny: skriv det nummer occh tryck enter för att gå till det\n1.Lista innehåll\n2.Lägg till ny vara\n3.Sök\nSpara till fil");
   fgets(buffer,511,stdin);
   switch(sscanf(buffer,"%i")){
    case 1:
   //Lägg till nya varor
        printf("Val 1");
    break;
    case 2:
   //Sök
        printf("val 2");
    break;
    case 3:
   //spara till fil
        printf("Val 3");
    break;
    default:
        printf("Fel!!");
    break;
    }
}