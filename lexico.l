%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sintatico_novo.tab.h"
#include "globals.h"
extern YYSTYPE yylval;
extern int contador_erros_lexicos;
void adicionar_erro_lexico(const char *mensagem);
%}

DIGITO  [0-9]
NUMERO  {DIGITO}+
LETRA   [a-zA-Z]
ID      {LETRA}({LETRA}|{DIGITO}|_)*

%%
"program"   { return TOKEN_PROGRAM; }
"var"       { return TOKEN_VAR; }
"procedure" { return TOKEN_PROCEDURE; }
"function"  { return TOKEN_FUNCTION; }
"begin"     { return TOKEN_BEGIN; }
"end"       { return TOKEN_END; }
"false"     { return TOKEN_FALSE; }
"true"      { return TOKEN_TRUE; }
"if"        { return TOKEN_IF; }
"then"      { return TOKEN_THEN; }
"else"      { return TOKEN_ELSE; }
"while"     { return TOKEN_WHILE; }
"do"        { return TOKEN_DO; }
"read"      { return TOKEN_READ; }
"write"     { return TOKEN_WRITE; }
"and"       { return TOKEN_AND; }
"or"        { return TOKEN_OR; }
"not"       { return TOKEN_NOT; }
"div"       { return TOKEN_DIV; }
"integer"   { return TOKEN_INTEGER; }
"boolean"   { return TOKEN_BOOLEAN; }
"+"         { return TOKEN_SOMA; }
"-"         { return TOKEN_SUBT; }
"*"         { return TOKEN_MULT; }
"="         { return TOKEN_IGUAL; }
")"         { return TOKEN_FECHAPAR; }
"("         { return TOKEN_ABREPAR; }
";"         { return TOKEN_PONTOVIRG; }
","         { return TOKEN_VIRG; }
"."         { return TOKEN_PONTO; }
"<>"        { return TOKEN_DIF; }
">"         { return TOKEN_MAIOR; }
"<"         { return TOKEN_MENOR; }
">="        { return TOKEN_MAIORIGUAL; }
"<="        { return TOKEN_MENORIGUAL; }
":="        { return TOKEN_ATRIB; }
":"         { return TOKEN_DOISP; }

{NUMERO}+{ID}  {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Erro lexico: numero NO identificador => %s\n", yytext);
    adicionar_erro_lexico(buffer);
}
[0-9]+\.+(\.|{DIGITO}|{ID})*    {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Numero nao aceito: %s\n", yytext);
    adicionar_erro_lexico(buffer);
}


{ID}        {
    yylval.sval = strdup(yytext);
    return ID;
}

{NUMERO}    {
    yylval.sval = strdup(yytext);
    return NUMERO;
}

[ \r\t]+ ;
\n  { yylineno++; }

.   {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "Erro lexico: Simbolo Invalido => %s na linha %i\n", yytext, yylineno);
    adicionar_erro_lexico(buffer);
}

%%

int yywrap() {return 1;}