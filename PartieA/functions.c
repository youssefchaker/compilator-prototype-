
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "header.h"

/* isNumber est une variable static 
     qui va nous indiquer si le nombre st lu précédament 
     est un chiffre ou non 
*/
static int isNumber = 0;

/* isNumber est une variable static 
     qui va nous indiquer si le mot lu 
     précédement est un identifiant ou non
*/
static int isIdentifier = 0;

/**
 * Verifier si le caractère s'il est alphabetique
 * @param char
 * @return int
 */
int isAlphabetic(char c){
     // si le caractère ∈ [a-zA-Z]
     if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
     }
     return 0;
}
/**
 * Verifier si le caractère s'il est alphanumérique
 * @param char
 * @return int
 */
int isAlphanumeric(char c){
     // si le caractère ∈ [a-zA-Z]
     if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||(c >= '0' && c <= '9')|| (c=='_')){
        return 1;
     }
     return 0;
}
/**
 * Savoir si le charatère est un chiffre
 * @param char
 * @return int
 */
int isNumeric(char c){
     // si le caractère ∈ [0-9]
     if(c >= '0' && c <= '9'){
         return 1;
     }
     return 0;
}

/**
 * Savoir si un caractere est un opérateur arithmetique
 * retourne son numero dans nameToken si caractére est une opération arithmetique, -1 sinon
 * @param char
 * @return int
 */
int oparith(char c){
     // initialisation du compteur 
     int i = 0;
     int op = (int) PLUS_TOKEN; // PLUS_TOKEN est la première opération arithmetique dans nameToken
     // verifier si le caractère appartient à la liste des opérations arithétiques
     while(i < oparith_token_size){
          if(c==oparith_token[i]){
               // si on le trouve on retourn son indice 
               op = op + i;
               return op;  
          }
          i++;
     }
     // si on le trouve pas
     return -1;
}

/**
 * Retourner le numèro 
 * @param char
 * @param int prend  1:nombre négatif|| 0:bombre positif
 * @return numberToken
 */
int getNumber(char digit, int isNegative){
     // initialisation du compteur
     int i=0;
     // Allocation du tableau qui va stocker le nombre
     char* memory = (char *)malloc(NUMBERSIZE*sizeof(char));
     numberToken A;
     // Lire tout le chiffre
     do{
         // stocker chaque caractère
         memory[i] = digit;
         // lire le caractére suivant
         digit = fgetc(fileSrc); 
         // incrimentation du compteur
         i++;
     }while(isNumeric(digit) == 1);
     // affecter un caractère de fin de chaine à la fin du tableau
     memory[i] = '\0';
     /*
       on sort de doo..while lorsqu'on lit un caractére non numérique
       il faut retourner le curseur pour que cette caractére ne soit perdu
     */
     ungetc(digit, fileSrc);
     // si le nombre est negatif
     A.n = atoi(memory);
     if(isNegative == 1){
        A.n = - A.n;               
     }
     return A.n;
}

/**
 * Retourner l'unite lexicale 
 * @param char
 * @param int 
 * @return token
 */
token getToken(){  
     // Lire le caractére suivant
     char character = fgetc(fileSrc);
     token A;
     int i = 0;
     // Eliminer les blancs
     if(character == ' ' || character == '\t' || character == '\n'){                                       
          return getToken();
     }
     
     // Reconnaissance des mots-clé et des identificateurs
     /* si c'est un identificateur
          le mot doit être de cette forme :[a-zA-z]([0-9]|[a-zA-Z]|_)*
          si c'est un mot clè le mot doit figurer dans
          la tableau des mots clès
     */
     else if(isAlphabetic(character) == 1){
          // Allocation de la mémoire pour sauvegarder le mot
          A.word = (char *)malloc(IDFSIZE*sizeof(char));
          
          // Lire tout le mot
          do{
              A.word[i] = character;
              character = fgetc(fileSrc); // Lire le caractére suivant
              i++;
              // tant que c'est un alphanumérique on continue à lire le mot
          }while(isAlphanumeric(character)==1);
          // il faut poser \0 à la fin du mot
          A.word[i] = '\0';
          /*
            La fonction do..while sort Lorsqu'elle lit un non alpha-numérique caractére
            il faut retourner en arriére le curseur par la fonction ungetc()
            pour que ce caractếre ne soit perdu, et il va être analyser
            dans le prochain appelle de la fonction getToken()
          */
          ungetc(character, fileSrc);
          i = 0;

          // vérifier si lo mot obtenue est un mot-clé :
          while(i < keyword_token_size){
               // on compare le mot avec le tableau des mot clès keyword_token
               if(strcmp(A.word, keyword_token[i]) == 0){ // Le mot est un mot-clé
                    /* Le nom token : (nameToken) i convertit l'indice par sa position
                     dans la liste d'énumaration nametoken */
                    A.name = (nameToken) i;
                    // retourner le token
                    return A;  
               }
               i++;
          }
          /* Si on arrive à cette étape, le mot n'est pas mot-clé
            Donc c'est un identificateur, et son nom est stocké dans A.properties.identifier.name
          */
         
          A.name = IDENTIFIER_TOKEN;
          // assigner 1 à isIdentifer
          isIdentifier = 1;
          return A; // retourner le token
     }
     // Reconnaissance des nombres
     else if(isNumeric(character) == 1){
          // le token est un nombre ==> isNumber = 1;
          isNumber = 1;
          // allocation de la mémoire pour le mot 
          A.word = (char *)malloc(VARCHARSIZE*sizeof(char));
          A.name = NUMBER_TOKEN;
          // pour la conversion
          // récupérer le nombre et le stocker dans A.word
          char ch [VARCHARSIZE];
          int nb = getNumber(character, 0);
          // conversion int to char
          snprintf(A.word ,32,"%d",nb);
          return A;
     }
     /* Reconnaissance des nombres positives/ negatives 
          et des opérations d'additions et de soustractions:
          Nous avons 2 cas particuliers
          exemple : 1)  3 - 5 : ici le symbole "-" est optérateur arithmétique donc le token est MINUS-TOKEN
                    2) x = -3 : ici le symbole "-" est le signe du nombre donc le token NUMBER_TOKEN
     */
     else if(character == '+' || character == '-'){
          // verifier si c'est un opérateur arithmétique "+" "-"
          nameToken symboleToken = (character == '+' ? PLUS_TOKEN : MINUS_TOKEN);
          // sauvegarder le caractère
          char ch[2] = {character,'\0'};
          // Allocation de la mémoire 
          A.word = (char *)malloc(3*sizeof(char));
          strcpy(A.word ,ch);
          
          /* verifier si le nombre est negatif 
                si negatif isNegative = 1
                sinon isNegative = 0
          */
          int isNegative = (character == '-' ? 1 : 0);

          // Eliminer les espaces
          do{
               // faire avancer le curseur
               character = fgetc(fileSrc);
          }while(character == ' ');
          // Le curseur se trouve après le signe ( + || - )
          // Si le caractére suivant de +/- est un chiffre ( - 3 || + 3)
          if(isNumeric(character) == 1){
               /*  le token précédant est un nombre ou un identificateur
                exemple : "5 - 3" ou "x + 3"
                */
               if((isNumber == 1) || (isIdentifier == 1)){
                    isIdentifier = 0;
                    isNumber =0;
                    //retourner en arriére le curseur pour que ce caractếre ne soit perdu
                    ungetc(character, fileSrc);
                    // il s'agit d'une opèratioon arithmétique
                    A.name = symboleToken;
                    return A;
               }else{ // le token précèdant n'est pas un nombre, exemple cette situation : "= - 3"
                    isNumber = 1;
                    // allocation de la mémoire pour le mot 
                    A.word = (char *)malloc(VARCHARSIZE*sizeof(char));
                    A.name = NUMBER_TOKEN;
                    // pour la conversion
                    // récupérer le nombre et le stocker dans A.word
                    char ch [VARCHARSIZE];
                    int nb = getNumber(character, isNegative);
                    // conversion int to char
                    snprintf(A.word ,32,"%d",nb);
                    return A;
               }
          }else{ // Le caractére suivant de +/- n'est pas un chiffre
               // reinitialiser les variable
               isIdentifier = 0;
               isNumber =0;
               //retourner en arriére le curseur pour que ce caractếre ne soit perdu
               ungetc(character, fileSrc);
               // sauvegarder son nom 

               A.name = symboleToken;
               return A;
          }
     }
     
     // Reconaissance des autres opèrateurs arithmétiques ( "\","*")
     else if((i = oparith(character)) > -1){
          /* sauvegarder son non
           on récupére l'indice de l'opèrateur de la fonction oparith 
           et on le convertit depuis la liste d'énumération v
          */
          A.name = (nameToken) i;
          //ajouter le caractère de fin de chaine
          char ch[2] = {character,'\0'};

          // Allocation de la mémoire pour sauvegarder le mot
          A.word= (char *)malloc(3*sizeof(char));
          strcpy(A.word ,ch);

          return A;
     }
     // Reconnaissance de =, ==
     else if(character == '='){
          // Lire le caractére suivant
          character = fgetc(fileSrc);
          if(character == '='){ // On a le symbole ==
               A.name = OP_EQ_TOKEN;          
               // Allocation de la mémoire pour sauvegarder le mot
               A.word = (char *)malloc(4*sizeof(char));
               strcpy(A.word ,"==");
               return A;
          }else{ // On a le symbole =
               A.name = ASSIGNMENT_TOKEN;
               char ch[2] = {character,'\0'};
               // Allocation de la mémoire pour sauvegarder le mot
               A.word = (char *)malloc(3*sizeof(char));
               strcpy(A.word, "=");
               //retourner en arriére le curseur pour que ce caractếre ne soit perdu
               ungetc(character, fileSrc);
               return A;
          }
     }
     // Reconnaissance de >, >=
     else if(character == '>'){
          // Lire le caractére suivant
          character = fgetc(fileSrc);
          if(character == '='){ // On a le symbole >=
               A.name = OP_GE_TOKEN;
               // Allocation de la mémoire pour sauvegarder le mot
               A.word = (char *)malloc(4*sizeof(char));
               strcpy(A.word, ">=");
               return A;
          }else{ // On a le symbole >
               A.name = GT_TOKEN;
               // Allocation de la mémoire pour sauvegarder le mot
               A.word = (char *)malloc(4*sizeof(char));
               strcpy(A.word, ">");
               //retourner en arriére le curseur pour que ce caractếre ne soit perdu
               ungetc(character, fileSrc);
               return A;
          }
     }
     // Reconnaissance de <, <=
     else if(character == '<'){
          // Lire le caractére suivant
          character = fgetc(fileSrc);
          if(character == '='){ // On a le symbole <=
               A.name = OP_LE_TOKEN;
               // Allocation de la mémoire pour sauvegarder le mot
               A.word = (char *)malloc(4*sizeof(char));
               strcpy(A.word, "<=");
               return A;
          }else{ // On a le symbole <
               A.name = LT_TOKEN;
               // Allocation de la mémoire pour sauvegarder le mot
               A.word= (char *)malloc(4*sizeof(char));
               strcpy(A.word, "<");
               //retourner en arriére le curseur pour que ce caractếre ne soit perdu
               ungetc(character, fileSrc);
               return A;
          }
     }
     // Reconnaissance de !=
     else if(character == '!'){
          // Lire le caractére suivant
          character = fgetc(fileSrc);
          if(character == '='){ // On a le symbole !=
               A.name = OP_NOT_EQ_TOKEN;
               // Allocation de la mémoire pour sauvegarder le mot
               A.word = (char *)malloc(4*sizeof(char));
               strcpy(A.word, "!=");
               return A;
          }else{  // Si on rencontre d'autre caractéres non analysés
               A.name = ERROR_TOKEN;
               A.word = (char *)malloc(VARCHARSIZE*sizeof(char));
               // sauvegarder le caractère
               char ch[2] = {character,'\0'};
               strcpy(A.word, ch);
               return A;
          }
     }
     // La fin de la lecture
     else if(character == EOF){
          A.name = EOF_TOKEN;
          A.word = (char *)malloc(VARCHARSIZE*sizeof(char));
          char ch[2] = {character,'\0'};
          strcpy(A.word, ch);
          return A;
     }
     else{// Si on rencontre d'autre caractéres non analysés
          A.name = ERROR_TOKEN;
          A.word = (char *)malloc(VARCHARSIZE*sizeof(char));
          char ch[2] = {character,'\0'};
          strcpy(A.word, ch);
          return A;
     }
}
/**
 * Determine l'expression régulière l'unite lexicale 
 * @param char[VARCHARSIZE][VARCHARSIZE]
 */
void expReg(char uniteLexicale[VARCHARSIZE][VARCHARSIZE]){
     
     int i = 0;

     
     while ( i < nbUniteLex) {
          if ((strcmp(uniteLexicale[i],"IF_TOKEN")== 0)||(strcmp(uniteLexicale[i],"ELSE_TOKEN")== 0)||
               (strcmp(uniteLexicale[i],"FOR_TOKEN")== 0) || (strcmp(uniteLexicale[i],"WHILE_TOKEN")== 0)||
               (strcmp(uniteLexicale[i],"INT_TOKEN")== 0) || (strcmp(uniteLexicale[i],"FLOAT_TOKEN")== 0)||
               (strcmp(uniteLexicale[i],"CHAR_TOKEN")== 0) || (strcmp(uniteLexicale[i],"BREAK_TOKEN")== 0 )||
               (strcmp(uniteLexicale[i],"RETURN_TOKEN")== 0)){
                    strcpy(expression[i], expRegx[0]); 

          } else if((strcmp(uniteLexicale[i],"LT_TOKEN")== 0) ||(strcmp(uniteLexicale[i],"GT_TOKEN")== 0)||
                    (strcmp(uniteLexicale[i],"OP_LE_TOKEN")== 0 )||( strcmp(uniteLexicale[i],"OP_GE_TOKEN")== 0)||
                    (strcmp(uniteLexicale[i],"OP_NOT_EQ_TOKEN")== 0) || (strcmp(uniteLexicale[i],"OP_EQ_TOKEN")== 0)){

                    strcpy(expression[i], expRegx[1]);

          } else if((strcmp(uniteLexicale[i],"PLUS_TOKEN")== 0 )||(strcmp(uniteLexicale[i],"MINUS_TOKEN")== 0)||

               (strcmp(uniteLexicale[i],"DIV_TOKEN")== 0) ||(strcmp(uniteLexicale[i],"STAR_TOKEN")== 0)){

               strcpy(expression[i],  expRegx[2]);

          } else if(strcmp(uniteLexicale[i],"ASSIGNMENT_TOKEN")== 0){

               strcpy(expression[i], expRegx[3]);

          }else if(strcmp(uniteLexicale[i],"IDENTIFIER_TOKEN")== 0){

               strcpy(expression[i], expRegx[4]);

          }else if(strcmp(uniteLexicale[i],"NUMBER_TOKEN")== 0){

               strcpy(expression[i], expRegx[5]);

          }else if(strcmp(uniteLexicale[i],"EOF_TOKEN")== 0){

               strcpy(expression[i] , "EOF_TOKEN");

          }else{
               strcpy(expression[i] , "ERROR_TOKEN");
          }
          i++;
     }

}
/**
 * affiche la table d'analyse
 * @param char [VARCHARSIZE][VARCHARSIZE]
 */
void analyseur(char uniteLexicale[VARCHARSIZE][VARCHARSIZE], char lexeme[VARCHARSIZE][VARCHARSIZE]){
     char ch[VARCHARSIZE];
     // tableau pour stocker les lexemes
     int i =0;
     // trouves l'eexpressionn régulière de chaque lexeme
     expReg(uniteLexicale);

     while (i < nbUniteLex) {
          system("setterm -bold on");
          // affichage du lexème
          printf("\033[1;35m              |    ");
          printf("\033[1;0m");
          printf("%s",lexeme[i]);

          //tabulation
          for (int j =0; j< 34 - (strlen(lexeme[i])+4); j++){
               printf(" ");
          }
          //affichage de l'unité lexcale
          printf("\033[1;35m|    ");
          printf("\033[1;0m");
          printf("%s",uniteLexicale[i]);
          
          //tabulation 
          for (int j =0; j< 34 - (strlen(uniteLexicale[i]) + 4); j++){
               printf(" ");
          }
          //afficahge de l'expression régulière
          printf("\033[1;35m|    ");
          printf("\033[1;0m");
          printf("%s",expression[i]);
          for (int j =0; j< 34 - (strlen(expression[i]) + 4); j++){
               printf(" ");
          }
          i++;
          printf("\033[1;35m");
          printf("|\n");
          printf("\033[1;0m");

     }
}

     




