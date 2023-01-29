#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


// Stocke la grammaire sans élimination de la recursivite
int nbLigneProdWR=0, nbColProdWR=0;
char productionWR[26][128][20];

// Stocke la grammaire aprés l'élimination de la recursivite
int nbLigneProd=0, nbColProd=0;
char production[26][128][20];

// Stocke toute la liste des terminaux
char terminal[256];
// Pointeur de la liste des terminaux
int ptrTerminal=0;

/* Stocke toute la liste des terminaux
 uniquement Lettres majuscules de 'A' à 'Z'
 peuvent être des non-terminaux */
char NT[26];
// Pointeur de la liste des non terminaux
int ptrNT=0;

/* Stocke les premiers de chaque non terminale 
le non terminale est stocker dans calc_first[i][0], avec i presente 
le nombre des non terminaux, la liste des premiers est stocker 
apartir de calc_first[i]10] */
char calc_first[26][128];

//Table intermédiaire utilisé pour calculer les premiers
char first[128];
//Taille de la table des premiers
int firstSize=0;

/* Stocke les suivants de chaque non terminale 
le non terminale est stocker dans calc_follow[i][0], avec i presente
le nombre des non terminaux, la liste des suivants est stocker 
apartir de calc_follow[i]10] */
char calc_follow[26][128];

//Table intermédiaire utilisé pour calculer les suivants
char followT[128];
//Taille de la table des suivants
int followSize=0;

char suivSuiv[26][128];
/* structure pour contenir chaque production avec ces premiers
 regle[] stocke la production
 firstList[] stocke la liste des premiers
 firstListLen est la taille des premiers */
typedef struct regleFirstStruct
{
    char regle[128];
    char firstList[128];
    int firstListLen;
} regleFirstStruct;
// Stocke les regles avec ces premiers
regleFirstStruct regleFirst [100];
// Taille de RegleFirst
int ptrRegleFirst=-1;

/***************** Les fonction *****************/
/*Lecture de la grammaires
    Soit grammaire donner par l'utilisateur 
    soit grammaire donner par défaut 
*/
void readProduction();
// Afficher la grammaire avant l'élimination de la recursivité
void PrintProductionWR();

// Eliminer la récursivité
void deleteRecursivite(int);

// Afficher la grammaire aprés l'élimination de la recursivité
void PrintProduction();

// Trier les tables
void Sort(char[] , int ,int );

// Calculer les premiers
void CalculFirst();
void findfirst(char);
// Afficher les premiers de chaque non terminale
void printFirst();
int test;
int testCol;
// Calculer les suivants
void CalculFollow();
void findFollow(char c);
void followfirst(char, int, int, int);
// Afficher les suivants de chaque non terminale
void printFollow();

// Afficher les premiers de chaque regle
void regle_first();

//Afficher la table LL1
void table_LL1_print(char c);
void table_LL1();
/**************************** Stack ***********************/
int MAXSIZE = 128;       
// Stocker l'etat de la pile l'hors de la vérification du mot
typedef struct stackStruct
{
    char stack[128];
    int top; 
} stackStruct;
stackStruct pile;

void init();
int isempty();
   
int isfull() ;

char peek() ;

char pop();

void push(int data);

/***************************** Word ********************************/
char word[256];
char inv[256];
void verifWord();