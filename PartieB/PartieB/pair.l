pairpair (aa|bb)*((ab|ba)(aa|bb)*(ab|ba)(aa|bb)*)*
%%
{pairpair} printf("[%s]: nombre pair de a et de b \n", yytext);
a*b* printf("[%s]: des a d'abord et des b ensuite \n", yytext);
.
%%
int yywrap(){return 1;}
int main(int argc, char *argv[])
{ 
++argv, --argc; 
if ( argc > 0 ) 
yyin = fopen( argv[0], "r" ); 
else 
yyin = stdin; 
yylex() ;  
}
