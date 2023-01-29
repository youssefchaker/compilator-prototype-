/* Partie 1 : Les déclarations en c */
%{

%}
/* Partie 2 : Déclartion des définitions régulier   */

/* Nom *    * expression régulière */

lettre      [a-zA-Z]

chiffre     [0-9]

ident       ({lettre}|_)({lettre}|{chiffre}|_)*

nombre       [+-]?[0-9]+

mot_cle     if|else|for|while|int|float|char|break|return 
 
oparith     "-"|"+"|"*"|"/"

oprel       <|>|>=|<=|!=|==

opaffect     = 

/* Partie 3 : Règles de traduction */

/* Unité lexicale *                     * Actions */

%%

{mot_cle}                 { printf ("\n%s : Mot clé\n" , yytext); }

{nombre}                  { printf ("\n%d : Nombre\n" , atoi(yytext)); }

{ident}                   { printf ("\n%s : Identificateur\n" , yytext);}

{oparith}                 { printf ("\n%s : Opérateur arithmétique\n" , yytext); }

{oprel}                   { printf ("\n%s : Opérateur relationnel\n" , yytext); }

{opaffect}                { printf ("\n%s : Opérateur d'affectation\n" , yytext); } 

"/*"[^*/]*"*/"             /* pas d'action */ 

"//"[^\n]*                /* pas d'action */

[ \t]+                  /* pas d'action */ 

\n                    /* pas d'action */ 

.                 { printf ("\n%s : Caractère non reconnu\n" , yytext); }

%%
/* Partie 4 : Bloc principal et fonctions auxiliaires en C */

/* yywrap ( ) :  appelée à la fin du texte d’entrée.*/

int yywrap(){return 1;}

/* yylex() : trouve les lexèmes 
   et exécute les actions correspondantes *

 * yyin fichier de lecture (par défaut: stdin) *

**/

int main(int argc, char *argv[])
{ 
++argv, --argc; 
if ( argc > 0 )
yyin = fopen( argv[0], "r" ); 
else 
yyin = stdin; 
yylex();
}

