#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"

typedef int (*compfn)(const void*, const void*);

void save_to_file(Vara *array_with_products,int number_of_products,char* file_name){

  FILE *fp;
  strcat(file_name,".csv");
  if ((fp = fopen(file_name, "w")) == NULL) {
    fprintf(stderr, "Filen %s gick inte att öppna\n",file_name);
    exit(-1);
  }
  for(int i = 0; i < number_of_products;i++){
      fprintf(fp,"%d,%s,%f,%f,%s,%s,%s,%s,%s,%f\n",array_with_products->varunummer,array_with_products->namn,array_with_products->pris,
      array_with_products->volym,array_with_products->typ,array_with_products->stil,array_with_products->forpackning,array_with_products->land,
      array_with_products->producent,array_with_products->alkoholhalt);
      array_with_products++;
  }
  printf("Du har sparat varorna till filen %s",file_name);
}

void search_varunummer(char *search_word,Vara *products, int number_of_products, Vara *start_of_products){
    char *end;
    char temporary_string[20];
    bool match_found = false;

    //Vara *products = calloc(100,sizeof(Vara));
    //Vara *start_of_products = products;
    //products = Read();
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        sprintf(temporary_string, "%d", products->varunummer); //convert current structs varunummer to string              
        if (strcmp(search_word, temporary_string) == 0) {                       //compare strings
            printf("\n%s, has the following information: \nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
            search_word, products->namn,products->pris,products->volym,products->typ,
            products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt); //horrendous printf
            match_found = true;
           break;
        }  
    }
    products = start_of_products;
    if(!match_found)
        printf("\nThe number %s did not match any varunummer", search_word);
}

int compare(Vara *elem1, Vara *elem2)
{
   if ( elem1->varunummer < elem2->varunummer)
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

void sort_by_varunummer(Vara *products, int number_of_products,int compare, Vara *start_of_products){      //ev. slå ihop sorteringsfunkjtionerna
    //Måste peka på första elementet i pekararrayen
    products = start_of_products;
    qsort(products, number_of_products, sizeof(Vara), (compfn)compare); //Ändra 16
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        //Använd %0.2f för att få två decimaler och så att float inte tar och visra sina felaktigheter :D
        printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
        products->varunummer,products->namn,products->pris,products->volym,products->typ,
        products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}

void sort_by_namn(Vara *products, int number_of_products,int compare_string, Vara *start_of_products){
    //Måste peka på första elementet i pekararrayen
    products = start_of_products;
    qsort(products, number_of_products, sizeof(Vara), (compfn)compare_string); //Ändra 16
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        //Använd %0.2f när du printar för att få två decimaler och så att float inte tar och visra sina felaktigheter :D
        printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
        products->varunummer,products->namn,products->pris,products->volym,products->typ,
        products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}