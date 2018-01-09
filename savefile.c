#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structinfo.h"
//går att utöka till att ha med ett filnamn
void save_to_file(Vara *array_with_products,int number_of_products,char* file_name){

  FILE *fp;
  strcat(file_name,".csv");
  if ((fp = fopen(file_name, "w")) == NULL) {
    fprintf(stderr, "Filen %s gick inte att öppna\n",file_name);
    exit(-1);
  }

  for(int i = 0; i < number_of_products;i++){
      fprintf(fp,"%i,%s,%f,&f,%s,%s,%s,%s,%s,%f\n",array_with_products->varunummer,array_with_products->namn,array_with_products->pris,
      array_with_products->volym,array_with_products->typ,array_with_products->stil,array_with_products->forpackning,array_with_products->land,
      array_with_products->producent,array_with_products->alkoholhalt);
      array_with_products++;
  }
  printf("Du har sparat varorna till filen %s",file_name);
}