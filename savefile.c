#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"
#include "other_functions.c"

typedef int (*compfn)(const void*, const void*);

void save_to_file(Vara *array_with_products,int number_of_products,char* file_name){

  FILE *fp;
  strcat(file_name,".csv");
  if ((fp = fopen(file_name, "w")) == NULL) {
    fprintf(stderr, "Filen %s gick inte att öppna\n",file_name);
    exit(-1);
  }
  for(int i = 0; i < number_of_products;i++){
      fprintf(fp,"%d,%s,%0.2f,%0.2f,%s,%s,%s,%s,%s,%0.2f\n",array_with_products->varunummer,array_with_products->namn,array_with_products->pris,
      array_with_products->volym,array_with_products->typ,array_with_products->stil,array_with_products->forpackning,array_with_products->land,array_with_products->producent,array_with_products->alkoholhalt);
      array_with_products++;
  }
  printf("Du har sparat varorna till filen %s",file_name);
  fclose(fp);
}

Vara *search_varunummer(char *search_word,Vara *products, int number_of_products, Vara *start_of_products){
    char *end;
    char temporary_string[20];
    bool match_found = false;

    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        sprintf(temporary_string, "%d", products->varunummer); //convert current structs varunummer to string              
        if (strcmp(search_word, temporary_string) == 0)                      //compare strings
           return products;
    }
    return NULL;
}

void sort_by_varunummer(Vara *products, int number_of_products,int compare, Vara *start_of_products){      //ev. slå ihop sorteringsfunkjtionerna
    products = start_of_products;     //Måste peka på första elementet i pekararrayen
    qsort(products, number_of_products, sizeof(Vara), (compfn)compare); //Ändra 16
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
        products->varunummer,products->namn,products->pris,products->volym,products->typ,products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}

void sort_by_namn(Vara *products, int number_of_products,int compare_string, Vara *start_of_products){
    products = start_of_products;     //Måste peka på första elementet i pekararrayen
    qsort(products, number_of_products, sizeof(Vara), (compfn)compare_string); 
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
        products->varunummer,products->namn,products->pris,products->volym,products->typ,products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}

Vara *add_vara(Vara *products, int number_of_products, Vara *start_of_products, Vara *end_of_products){
    double d;
    char tempString[256];
    printf("\nEnter varunummer: ");
    fgets(tempString,256,stdin);
    tempString[strlen(tempString) - 1] = '\0'; //en funktion som tarbort newline tecknet och ersätter med \0
               
    products = search_varunummer(tempString, products, number_of_products, start_of_products);
    if (products != NULL){
        printf("\nVarunummer not uniqe, choose another varunummer next time");
        return NULL;
    }
    products = end_of_products;         //adding a new product, needs to point at end of array
    products->varunummer = atoi(tempString);

    printf("Enter namn: ");
    fgets(tempString,256,stdin);
    tempString[strlen(tempString) - 1] = '\0';
    strcpy(products->namn,tempString);

    do{
    printf("Enter pris: ");
    fgets(tempString,256,stdin);
    tempString[strlen(tempString) - 1] = '\0';
    }while(!is_float(tempString));
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
    return products;                        //returns the added vara
}