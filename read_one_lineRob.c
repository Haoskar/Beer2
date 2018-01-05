#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Vara{
    int varunummer;
    char namn[100];
    float pris;
    float volym;
    char typ[100];
    char stil[100];
    char forpackning[20];
    char land[20];
    char producent[50];
    float alkoholhalt;
} Vara;

Vara *envara = calloc(100,sizeof(Vara));


int main (void) {

  char *oneline, *tok, *fitem;
  char envara[256];
  char delim[] = ",";
  
  printf("Name the first item: ");
  fgets(fitem, 20, stdin);
  
  struct Vara cider[10];
  struct Vara *ptr;
  ptr = &cider;

  int counter = 0;

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
