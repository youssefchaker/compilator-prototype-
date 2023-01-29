
#include <stdio.h>
#include <stdlib.h>
// Lire le fichier source
const char* fileName = "myfile.txt";
FILE *fileSrc = fopen(fileName, "r");

#include "functions.c"

int main(){
    int k;
    int i= 0;
    nbUniteLex = 0;
    char uniteLexicale[VARCHARSIZE][VARCHARSIZE];
    char lexeme[VARCHARSIZE][VARCHARSIZE];
    printf("\033[1;34m");
    printf("\t                             ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤                      \n");
    printf("\t                             ¤                                                                     ¤\n");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("\033[1;35m");
    printf("\t                             ¤               Bienvenue dans Notre Analyseur lexicale               ¤                       \n");
    printf("\033[0m");
    printf("\033[1;34m");
    printf("\t                             ¤                                                                     ¤\n");
    printf("\t                             ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤                      \n");
    printf("\n\n");
    printf("\033[0m");
    printf("\033[1;30m");
    printf("                                     Notre analyseur lexicale permet d'identifer les unités lexicales :\n");
    printf("\033[0m");
    printf("\n");
    printf("\033[1;33m");
    printf("                                        ¤-------------------------------------------------------¤\n");
    printf("                                        |\033[0m    1) \033[1;34m Mot-clé \033[0m : int, char, float...                 \033[1;33m| \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("                                        |\033[0m    2) \033[1;34m Nombre \033[0m  :((+|-)?)[0-9]([0-9])*                \033[1;33m| \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("                                        |\033[0m    3) \033[1;34m Opérateur  arithméthique\033[0m  : +, *, - , /        \033[1;33m| \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("                                        |\033[0m    4) \033[1;34m Opérateur relationel \033[0m : >, <=, ==, < ...       \033[1;33m| \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("                                        |\033[0m    5) \033[1;34m Identificateur \033[0m : [a-zA-z]([0-9]|[a-zA-Z]|_)*  \033[1;33m| \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("                                        |\033[0m    6) \033[1;34m Affectation \033[0m : =                               \033[1;33m| \n");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("                                        ¤-------------------------------------------------------¤\n");
    printf("\033[0m");
    printf("\033[1;34m"); 
    printf("\n\n");
                                                              
    printf("\t      ¤----------------------------------¤----------------------------------¤----------------------------------¤\n");
    system("setterm -bold on");
    printf("\033[1;0m");
    printf("\t \033[1;35m     |              Lexeme              |          Unité Lexicale          |       Expression Regulière       |\n");
    printf("\033[0m");
    system("setterm -bold off");
    printf("\033[1;34m");
    printf("\t      ¤----------------------------------¤----------------------------------¤----------------------------------¤\n");
    printf("\033[0m");
    fileSrc = fopen(fileName, "r");
    token currentToken = getToken();
    
    do{

        k = (int) currentToken.name;
        strcpy(uniteLexicale[i], tokens[k]);

        strcpy(lexeme[i],currentToken.word);

           
        nbUniteLex++;
        i++;
        currentToken = getToken(); 

    }while(currentToken.name != EOF_TOKEN);
    analyseur(uniteLexicale, lexeme);
    printf("\033[1;34m");
    printf("\t      ¤----------------------------------¤----------------------------------¤----------------------------------¤\n");
    printf("\033[0m");
    printf("\n\n");
    return 0;
}
