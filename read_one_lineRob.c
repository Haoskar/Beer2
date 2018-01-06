#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structinfo.h"

Vara *Read (void) {
  Vara *varapointer = calloc(100,sizeof(Vara));
  char *oneline, *tok, *fitem;
  char envara[256];
  char delim[] = ",";
  Vara *startvara = varapointer;


  FILE *fp;
  
  if ((fp = fopen("varor.csv", "r")) == NULL) {
    fprintf(stderr, "Filen varor.csv gick inte att öppna\n");
    exit(-1);
  }

  while(fgets(envara, 256, fp) !=NULL){
  envara[strlen(envara) - 1] = '\0'; // Ta bort radslutstecknet

  oneline = strdup(envara);

  tok = strtok(oneline, delim);
    varapointer->varunummer = atoi(tok);
    tok = strtok(NULL, delim);

    strcpy(varapointer->namn,tok);
    tok = strtok(NULL, delim);
   
    varapointer->pris = strtof(tok,NULL);
    tok = strtok(NULL, delim);
   
    varapointer->volym = atof(tok);
    tok = strtok(NULL, delim);
   
    strcpy(varapointer->typ,tok);
    tok = strtok(NULL, delim);
   
    strcpy(varapointer->stil,tok);
    tok = strtok(NULL, delim);
   
    strcpy(varapointer->forpackning,tok);
    tok = strtok(NULL, delim);
   
    strcpy(varapointer->land,tok);
    tok = strtok(NULL, delim);
   
    strcpy(varapointer->producent,tok);
    tok = strtok(NULL, delim);
   
    varapointer->alkoholhalt = atof(tok);
    tok = strtok(NULL, delim);
    
    varapointer++;
  free(oneline); free(tok);
}
  varapointer = startvara;
  fclose(fp);
return varapointer;
}
