#ifndef _STRUCTH_
#define _STRUCTH_

typedef struct vara{
    int varunummer;
    char namn[100];
    float pris;
    float volym;
    char typ[100];
    char stil[100];
    char forpackning[20];
    char land[20];          //20 är för kort för ölet med varunummer 1282, har 21 tecken
    char producent[50];
    float alkoholhalt;
}Vara;

#endif