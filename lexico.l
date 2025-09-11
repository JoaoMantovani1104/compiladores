%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGITO  [0-9]
NUMERO  {DIGITO}+
LETRA   [a-zA-Z]
ID      {LETRA}({LETRA}|{DIGITO}|_)*

%%

%%

int yywrap() {return 1;}