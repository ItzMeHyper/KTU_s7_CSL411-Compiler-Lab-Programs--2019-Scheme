%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *);
%}

%token NUMBER NL

%left '+' '-'
%left '*' '/'

%%

stmt
        : exp NL
          {
              printf("Result = %d\n", $1);
              return 0;
          }
        ;

exp
        : exp '+' exp     { $$ = $1 + $3; }
        | exp '-' exp     { $$ = $1 - $3; }
        | exp '*' exp     { $$ = $1 * $3; }
        | exp '/' exp     
          { 
              if ($3 == 0) {
                  printf("\nError: Division by zero!\n");
                  exit(1);
              }
              $$ = $1 / $3; 
          }
        | '(' exp ')'     { $$ = $2; }
        | NUMBER          { $$ = $1; }
        ;

%%

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("\nInvalid Expression\n");
    return 0;
}