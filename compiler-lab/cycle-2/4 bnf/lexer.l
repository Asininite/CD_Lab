%{
#include "parser.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
[ \t]+      ;                     /* Ignore spaces and tabs */
\n          { return '\n'; }      /* Signal end of expression */
.           { return yytext[0]; } /* Return single character */

%%

int yywrap(void) { return 1; }
