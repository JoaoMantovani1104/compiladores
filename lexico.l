%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGITO  [0-9]
NUMERO  {DIGITO}+
LETRA   [a-zA-Z]
ID      {LETRA}({LETRA}|{DIGITO}|_)*

%%
"program"   {printf("(PROGRAM, %s)\n", yytext);}
"var"   {printf("(VAR, %s)\n",yytext);}
"procedure"   {printf("(PROCEDURE, %s)\n",yytext);}
"function"   {printf("(FUNCTION, %s)\n",yytext);}
"begin"   {printf("(BEGIN, %s)\n",yytext);}
"end"   {printf("(END, %s)\n",yytext);}
"false"   {printf("(FALSE, %s)\n",yytext);}
"true"   {printf("(TRUE, %s)\n",yytext);}
"if"   {printf("(IF, %s)\n",yytext);}
"then"   {printf("(THEN, %s)\n",yytext);}
"else"   {printf("(ELSE, %s)\n",yytext);}
"while"   {printf("(WHILE, %s)\n",yytext);}
"do"   {printf("(DO, %s)\n",yytext);}
"read"   {printf("(READ, %s)\n",yytext);}
"write"   {printf("(WRITE, %s)\n",yytext);}
"and"   {printf("(AND, %s)\n",yytext);}
"or"   {printf("(OR, %s)\n",yytext);}
"not"   {printf("(NOT, %s)\n",yytext);}
"div"   {printf("(DIV, %s)\n",yytext);}
"integer"   {printf("(INTEGER, %s)\n",yytext);}
"boolean"   {printf("(BOOLEAN, %s)\n",yytext);}
"+"   {printf("(SOMA, %s)\n",yytext);}
"-"   {printf("(SUBT, %s)\n",yytext);}
"*"   {printf("(MULT, %s)\n",yytext);}
"="   {printf("(IGUAL, %s)\n",yytext);}
")"   {printf("(PARD, %s)\n",yytext);}
"("   {printf("(PARE, %s)\n",yytext);}
";"   {printf("(PONTOVIRG, %s)\n",yytext);}
","   {printf("(VIRG, %s)\n",yytext);}
"."   {printf("(PONTO, %s)\n",yytext);}
"<>"   {printf("(DIF, %s)\n",yytext);}
">"   {printf("(MAIOR, %s)\n",yytext);}
"<"   {printf("(MENOR, %s)\n",yytext);}
">="   {printf("(MAIORIGUAL, %s)\n",yytext);}
"<="   {printf("(MENORIGUAL, %s)\n",yytext);}
":="   {printf("(ATRIB, %s)\n",yytext);}
":"   {printf("(DOISP, %s)\n",yytext);}

{NUMERO}+{ID}  {printf("Erro léxico: numero NO identificador => %s \n", yytext); /*exit(1);*/}
[0-9]+\.+(\.|{DIGITO}|{ID})*    {printf("Numero nao aceito : %s \n", yytext); /*exit(1);*/}
{ID}    {printf("(ID, %s)\n",yytext);}
{NUMERO}   {printf("(NUM, %s)\n",yytext);}

[ \n\t]+    ;

.   {printf("Erro léxico: Simbolo Invalido => %s \n", yytext); /*exit(1);*/}

%%

int yywrap() {return 1;}