%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "sintatico.tab.h"
extern YYSTYPE yylval;
%}

DIGITO  [0-9]
NUMERO  {DIGITO}+
LETRA   [a-zA-Z]
ID      {LETRA}({LETRA}|{DIGITO}|_)*

%%
"program"   {return TOKEN_PROGRAM;}
"var"   {return TOKEN_VAR;}
"procedure" {return TOKEN_PROCEDURE;}
"function"  {return TOKEN_FUNCTION;}
"begin"     {return TOKEN_BEGIN;}
"end"       {return TOKEN_END;}
"false"     {return TOKEN_FALSE;}
"true"      {return TOKEN_TRUE;}
"if"        {return TOKEN_IF;}
"then"      {return TOKEN_THEN;}
"else"      {return TOKEN_ELSE;}
"while"     {return TOKEN_WHILE;}
"do"        {return TOKEN_DO;}
"read"      {return TOKEN_READ;}
"write"     {return TOKEN_WRITE;}
"and"       {return TOKEN_AND;}
"or"        {return TOKEN_OR;}
"not"       {return TOKEN_NOT;}
"div"       {return TOKEN_DIV;}
"integer"   {return TOKEN_INTEGER;}
"boolean"   {return TOKEN_BOOLEAN;}
"+"         {return TOKEN_SOMA;}
"-"         {return TOKEN_SUBT;}
"*"         {return TOKEN_MULT;}
"="         {return TOKEN_IGUAL;}
")"         {return TOKEN_FECHAPAR;}
"("         {return TOKEN_ABREPAR;}
";"         {return TOKEN_PONTOVIRG;}
","         {return TOKEN_VIRG;}
"."         {return TOKEN_PONTO;}
"<>"        {return TOKEN_DIF;}
">"         {return TOKEN_MAIOR;}
"<"         {return TOKEN_MENOR;}
">="        {return TOKEN_MAIORIGUAL;}
"<="        {return TOKEN_MENORIGUAL;}
":="        {return TOKEN_ATRIB;}
":"         {return TOKEN_DOISP;}


{NUMERO}+{ID}  {printf("Erro léxico: numero NO identificador => %s \n", yytext); /*exit(1);*/}
[0-9]+\.+(\.|{DIGITO}|{ID})*    {printf("Numero nao aceito : %s \n", yytext); /*exit(1);*/}

{ID} {
    yyval.sval = strdup(yytext);
    return ID;
}
{NUMERO} {
    yyval.sval = strdup(yytext);
    return NUMERO;
}

[ \r\n\t]+    ;

.   {printf("Erro léxico: Simbolo Invalido => %s \n", yytext); /*exit(1);*/}

%%

int yywrap() {return 1;}