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
         printf("%-11s: %d\n%-11s: %s\n%-11s: %0.2f\n%-11s: %0.2f\n%-11s: %s\n%-11s: %s\n%-11s: %s\n%-11s: %s\n%-11s: %s\n%-11s: %0.2f \n", 
                "varunummer",products->varunummer,"namn",products->namn,"pris",products->pris,"volym",products->volym,"typ",products->typ,"stil",products->stil,"forpackning",products->forpackning,"land",products->land,"producent",products->producent,"alkoholhalt",products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}
//denna funktion sorterar efterstora bokstäver först sedan små
void sort_by_namn(Vara *products, int number_of_products,int compare_string, Vara *start_of_products){
    products = start_of_products;     //Måste peka på första elementet i pekararrayen
    qsort(products, number_of_products, sizeof(Vara), (compfn)compare_string); 
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
         printf("%-11s: %d\n%-11s: %s\n%-11s: %0.2f\n%-11s: %0.2f\n%-11s: %s\n%-11s: %s\n%-11s: %s\n%-11s: %s\n%-11s: %s\n%-11s: %0.2f \n", 
                "varunummer",products->varunummer,"namn",products->namn,"pris",products->pris,"volym",products->volym,"typ",products->typ,"stil",products->stil,"forpackning",products->forpackning,"land",products->land,"producent",products->producent,"alkoholhalt",products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}

Vara *add_vara(Vara *products, int number_of_products, Vara *start_of_products, Vara *end_of_products){
    char *temp_string = (char *) calloc(256,sizeof(char));
    do{
    printf("\nEnter varunummer: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!isInt(temp_string) || !strcmp(temp_string, ""));       

    products = search_varunummer(temp_string, products, number_of_products, start_of_products);
    if (products != NULL){
        printf("\nVarunummer not uniqe, choose another varunummer next time");
        return NULL;
    }
    products = end_of_products;         //adding a new product, needs to point at end of array
    products->varunummer = atoi(temp_string);

    do{
    printf("Enter namn: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!strcmp(temp_string, ""));
    strcpy(products->namn,temp_string);

    do{
    printf("Enter pris: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!is_float(temp_string) || !strcmp(temp_string, ""));
    products->pris = atof(temp_string);

    do{          
    printf("Enter volym: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!is_float(temp_string) || !strcmp(temp_string, ""));
    products->volym = atof(temp_string);

    do{                
    printf("Enter typ: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!strcmp(temp_string, ""));
    strcpy(products->typ,temp_string);

    do{                
    printf("Enter stil: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!strcmp(temp_string, ""));
    strcpy(products->stil,temp_string);

    do{               
    printf("Enter forpackning: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!strcmp(temp_string, ""));
    strcpy(products->forpackning,temp_string);
    
    do{              
    printf("Enter land: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!strcmp(temp_string, ""));
    strcpy(products->land,temp_string);

    do{           
    printf("Enter producent: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!strcmp(temp_string, ""));
    strcpy(products->producent,temp_string);

    do{      
    printf("Enter alkoholhalt: ");
    fgets(temp_string,256,stdin);
    temp_string = trimwhitespace(temp_string);
    temp_string[strlen(temp_string) - 1] = '\0';
    }while(!is_float(temp_string) || !strcmp(temp_string, ""));
    products->alkoholhalt = atof(temp_string);

    return products;                        //returns the added vara
}