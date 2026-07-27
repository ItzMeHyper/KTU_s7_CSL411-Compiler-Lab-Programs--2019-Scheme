%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+  {
            yylval = atoi(yytext);
            return NUMBER;
        }

\n      { return NL; }

[ \t]   ;  /* Ignore whitespace */

.       { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}