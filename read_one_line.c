#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {

  char *oneline, *tok;
  char envara[256];
  char delim[] = ",";
  
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
