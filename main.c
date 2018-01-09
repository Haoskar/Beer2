#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "read_one_lineRob.c"
#include "structinfo.h"
#include "savefile.c"

typedef int (*compfn)(const void*, const void*);

int isInt(char string[]){
    for(int i = 0; i < strlen(string) - 1; i++){
        if(!isdigit(string[i]) || string[i] == 0)
            return 0;
    } 
    return 1;
}
void sort_by_varunummer();
void search_varunummer(); //<- behövs
void sort_by_namn();
static int compare_string (Vara * a, Vara * b);
int  compare(Vara *, Vara *);
Vara *products, *start_of_products,*end_of_products;
int number_of_products = 0;


//fixa en is_float funktion 
int main (void) {

    products = (Vara *) calloc(100,sizeof(Vara));
    bool valid_input;
    char test_string[20]; 
    char* end;
    int option;
    char tempString[256];
    //läs in varor från varor.csv till products arrayen
    products = Read();
    start_of_products = products;
    end_of_products = start_of_products;

    while(products->varunummer != 0){
        end_of_products++;
        number_of_products++;
        products++;
    };
    //Göra så products stå på korekt index
    

    while(true){
        
        printf("\n---------------------------------------------------------\n");
        printf("1. Display contents sorted by varunummer\n");
        printf("2. Display contents sorted by namn\n");
        printf("3. Add a product\n");
        printf("4. Search\n");
        printf("5. Save to file\n");
        printf("6. Quit\n\n");

        option = 0;
        valid_input = false;
        do{
            printf("Enter a option (1-6): ");
            fgets(test_string, 20, stdin);
            if(test_string[0] == '\n')
                valid_input = false;
            else
                valid_input = isInt(test_string);
        }while(!valid_input);

        option = strtol(test_string, &end, 10);
        char *search_word = "9";
        switch(option){
            case 1:
                sort_by_varunummer();
                break;
            case 2:
                sort_by_namn();
                break;    
            case 3:
                //Varunummer

                printf("\nEnter varunummer: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0'; //en funktion som tarbort newline tecknet och ersätter med \0
                printf("%i",strlen(tempString));
                products->varunummer = atoi(tempString);

                printf("Enter namn: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
                printf("%i",strlen(tempString));
                strcpy(products->namn,tempString);

                printf("Enter pris: ");
                fgets(tempString,256,stdin);
                tempString[strlen(tempString) - 1] = '\0';
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

                printf("\n\nYou have added: \n");
                printf("varunummer: %d\nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
                products->varunummer,products->namn,products->pris,products->volym,products->typ,
                products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
                number_of_products++;
                end_of_products++;
                printf("\n--\n");
                
                for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
                    //Använd %0.2f när du printar för att få två decimaler och så att float inte tar och visra sina felaktigheter :D
                    printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
                    products->varunummer,products->namn,products->pris,products->volym,products->typ,
                    products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
                    printf("--------------------------------------\n");
                }
                products = start_of_products;
                break;
            case 4: //hakar ibland upp sig

                printf("\nVarunummer to search: ");
                fgets(search_word,20, stdin);
                search_word[strlen(search_word) - 1] = '\0';                //removes newline char
                
                search_varunummer(search_word);
                break;
            case 5:
                while(1){
        printf("Vad ska filen kallas: ");
		fgets(name_of_file_or_number, 512, stdin);
		//ta bort allt tomrum framför talen
		strcpy(name_of_file_or_number,trimwhitespace(name_of_file_or_number));
		//se så personern inte bara har tyrckt på enter eller att det är tom sträng
		if(strlen(name_of_file_or_number) == 1 || *name_of_file_or_number == 0)
			printf("du m%cste skriva ett filnamn\n",134);
		else{
			name_of_file_or_number = strtok(name_of_file_or_number,"\n");
			strcat(name_of_file_or_number,".txt");
			//se till så det inte är ett tomt namn
			if((skrivfil = fopen(name_of_file_or_number,"w")) == NULL)
				printf("Gick inte att %cpnna denna fil!\n",148);
			else
				break;
		}
	}
                save_to_file(products,number_of_products,tempString);
                break;
            case 6:
                save_to_file(products,number_of_products,"varor");
                printf("Good bye!\n");//Implement save to file
                exit(0);
                break;
            default:
                printf("Something went wrong");

        }
        printf("Funkar fint");
    }

}

void search_varunummer(char *search_word){
    char *end;
    char temporary_string[20];
    bool match_found = false;

    //Vara *products = calloc(100,sizeof(Vara));
    //Vara *start_of_products = products;
    //products = Read();

    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        sprintf(temporary_string, "%d", products->varunummer);                  //convert current structs varunummer to string
        if (strcmp(search_word, temporary_string) == 0) {                       //compare strings
            printf("\n%s, has the foloing information: \nnamn: %s\npris: %f\nvolym: %f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %f \n", 
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

void sort_by_varunummer(){      //ev. slå ihop sorteringsfunkjtionerna

    qsort((void *)products, number_of_products, sizeof(Vara), compare); //Ändra 16
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        //Använd %0.2f för att få två decimaler och så att float inte tar och visra sina felaktigheter :D
        printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
        products->varunummer,products->namn,products->pris,products->volym,products->typ,
        products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}

void sort_by_namn(){

    qsort(products, number_of_products, sizeof(Vara),compare_string); //Ändra 16
    for(products = start_of_products; products < &start_of_products[number_of_products]; products++){
        //Använd %0.2f när du printar för att få två decimaler och så att float inte tar och visra sina felaktigheter :D
        printf("varunummer: %d\nnamn: %s\npris: %0.2f\nvolym: %0.2f\ntyp: %s\nstil: %s\nforpackning: %s\nland: %s\nproducent: %s\nalkoholhalt: %0.2f \n", 
        products->varunummer,products->namn,products->pris,products->volym,products->typ,
        products->stil,products->forpackning,products->land,products->producent,products->alkoholhalt);
        printf("--------------------------------------\n");
    }
    products = start_of_products;
}

char *trimwhitespace(char *str)
{
  //se så det inte är någon mellanslag i 
  while(isspace((unsigned char)*str)) str++;
	//se så det inte är någon mellanslag i så fall retunera stringen
  if(!(isspace((unsigned char)*str)))  
    return str;
}