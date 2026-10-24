%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token ID NL INVALID

%%
stmt : exp NL
     {
         printf("Valid Identifier\n");
         exit(0);
     }
     ;

exp  : ID
     ;
%%

void yyerror(const char *s)
{
    printf("Invalid Identifier\n");
}

int main()
{
    printf("Enter the token: ");
    yyparse();
    return 0;
}