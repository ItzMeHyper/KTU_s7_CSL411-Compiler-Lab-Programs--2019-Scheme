%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *);
%}

%token DIGIT ID NL

%left '+' '-'
%left '*' '/'

%%

stmt
        : ID '=' exp NL          /* Rule for assignments: a = b + c */
          {
              printf("\nValid Expression\n");
              return 0;
          }
        | exp NL                 /* Rule for pure expressions: a + b */
          {
              printf("\nValid Expression\n");
              return 0;
          }
        ;

exp
        : exp '+' exp
        | exp '-' exp
        | exp '*' exp
        | exp '/' exp
        | '(' exp ')'
        | DIGIT
        | ID
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