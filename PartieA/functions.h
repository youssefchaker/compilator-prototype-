#ifndef FUNCTION_H
#define FUNCTION_H

#define IDFSIZE 50 // taille maximal d'un identificateur
#define NUMBERSIZE 32 // talle maximal d'un nombre
#define VARCHARSIZE 225 // taille maximal d'un variable texte
// nombre d'unite lexicale
int nbUniteLex;
// tablkeau contenant les expressions régulières 
char expression[VARCHARSIZE][VARCHARSIZE];
// Les mots clés de notre langage
const char* keyword_token[] = {"if", "else", "for", "while", "int", "float", "char", "break","return"};

// Les operateurs arithmetiques
//"-","+", "/", "*"}
const char oparith_token[] = {'+','-', '/', '*'};
//mot-clé : 9 elements | op-rel : 6 elemnts | op-arith : 4 elements | affectation : 1 element | identifinat : [a-zA-z]([0-9]|[a-zA-Z]|_)* | nombre : [0-9]((+|-)?[0-9])*
const char* expRegx []={"Mot-cle","Op-rel","Op-arith", "Affectation","Identificateur","Nombre"};
int keyword_token_size = sizeof(keyword_token)/sizeof(keyword_token[0]); // le nombre de cases de la table keyword_token
//int oprel_token_size = sizeof(oprel_token)/sizeof(oprel_token[0]); // le nombre de cases de la table oprel_token
int oparith_token_size = sizeof(oparith_token)/sizeof(oparith_token[0]); // le nombre de cases de la table oparith_token
// Le monde des tokens
// enumération des tokens
typedef enum{
    // keywrods tokens
    IF_TOKEN, ELSE_TOKEN, FOR_TOKEN, WHILE_TOKEN, INT_TOKEN, FLOAT_TOKEN, CHAR_TOKEN,BREAK_TOKEN,RETURN_TOKEN,
    // oprel tokens
    LT_TOKEN, GT_TOKEN,OP_LE_TOKEN, OP_GE_TOKEN, OP_NOT_EQ_TOKEN, OP_EQ_TOKEN,
    // Symbole tokens
    PLUS_TOKEN, MINUS_TOKEN, DIV_TOKEN, STAR_TOKEN,
    ASSIGNMENT_TOKEN,
    // Other tokens
	IDENTIFIER_TOKEN,
	NUMBER_TOKEN,
	EOF_TOKEN,
	ERROR_TOKEN
} nameToken;

// table de tokens
const char* tokens[] = {"IF_TOKEN", "ELSE_TOKEN", "FOR_TOKEN", "WHILE_TOKEN", "INT_TOKEN", "FLOAT_TOKEN", "CHAR_TOKEN","BREAK_TOKEN","RETURN_TOKEN",
                        "LT_TOKEN", "GT_TOKEN","OP_LE_TOKEN", "OP_GE_TOKEN", "OP_NOT_EQ_TOKEN","OP_EQ_TOKEN",
                        "PLUS_TOKEN", "MINUS_TOKEN","DIV_TOKEN", "STAR_TOKEN",
                        "ASSIGNMENT_TOKEN",
                        "IDENTIFIER_TOKEN",
                        "NUMBER_TOKEN",
                        "EOF_TOKEN",
                        "ERROR_TOKEN"};


// structure du nombre
typedef struct{
    int n;
}numberToken;

// La structure d'un token
typedef struct{
	nameToken name; // Le nom du token
    char* word; // contiendra le mot lue 
    
} token;

//les fonctions
int isAlphabetic(char c);
int isAlphanumeric(char c);
int isNumeric(char c);
void analyseur(char uniteLexicale[VARCHARSIZE][VARCHARSIZE], char lexeme[VARCHARSIZE][VARCHARSIZE]);
int oparith(char c);
int getNumber(char digit, int isNegative);
token getToken();
void expReg(char uniteLexicale[VARCHARSIZE][VARCHARSIZE]);
#endif