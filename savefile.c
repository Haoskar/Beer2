#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"
//går att utöka till att ha med ett filnamn
void save_to_file(Vara *array_with_products,int number_of_products){

  FILE *fp;
  
  if ((fp = fopen("varor.csv", "r")) == NULL) {
    fprintf(stderr, "Filen varor.csv gick inte att öppna\n");
    exit(-1);
  }

  for(int i = 0; i < number_of_products;i++){
      fprintf(fp,"%i,%s,%f,&f,%s,%s,%s,%s,%s,%f",array_with_products->varunummer,array_with_products->namn,array_with_products->pris,
      array_with_products->volym,array_with_products->typ,array_with_products->stil,array_with_products->forpackning,array_with_products->land,
      array_with_products->producent,array_with_products->alkoholhalt);
      array_with_products++;
  }
  printf("Du har sparat varorna till filen varor.csv");
}