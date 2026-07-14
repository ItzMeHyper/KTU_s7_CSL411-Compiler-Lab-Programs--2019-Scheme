%{
#include <stdio.h>
%}

keyword if|else|while|int|float|char

%%

{keyword}  { printf("Keyword\n"); }
[0-9]+      { printf("Number\n"); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identifier\n"); }
.+          { printf("Not Accepted\n"); }

%%

void main(){
    printf("Enter the string: ");
    yylex();
}