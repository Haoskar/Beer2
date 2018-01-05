#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structinfo.h"

int main (void) {
  Vara *varapointer = calloc(100,sizeof(Vara));
  char *oneline, *tok, *fitem;
  char envara[256];
  char delim[] = ",";
  //char stringArray[11][];

 // printf("Name the first item: ");
  //fgets(fitem, 20, stdin);


  FILE *fp;
  
  if ((fp = fopen("varor.csv", "r")) == NULL) {
    fprintf(stderr, "Filen varor.csv gick inte att öppna\n");
    exit(-1);
  }

  fgets(envara, 256, fp);
  envara[strlen(envara) - 1] = '\0'; // Ta bort radslutstecknet
  printf("En rad; %s\n", envara);

  oneline = strdup(envara);

  tok = strtok(oneline, delim);
  while (tok != NULL) {
    printf("%s\n", tok);
    tok = strtok(NULL, delim);
  }

  free(oneline); free(tok);
  fclose(fp);

}
