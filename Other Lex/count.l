
%{
#include <stdio.h>

int k=0, id=0, n=0, op=0, d=0;
%}

keyword     if|else|while|for|int|float|char|double|return|void
letter      [a-zA-Z]
digit       [0-9]
identifier  {letter}({letter}|{digit})*
number      {digit}+
operator    \+|\-|\*|\/|%|==|!=|<=|>=|=|<|>
delimiter   \(|\)|\{|\}|\[|\]|;|,

%%

{keyword}      { k++; }

{number}       { n++; }

{identifier}   { id++; }

{operator}     { op++; }

{delimiter}    { d++; }

[ \t\n]+       ;

.              ;

%%

int main()
{
    printf("Enter the input:\n");
    yylex();

    printf("\n--- COUNT ---\n");
    printf("Keywords   = %d\n", k);
    printf("Identifiers= %d\n", id);
    printf("Numbers    = %d\n", n);
    printf("Operators  = %d\n", op);
    printf("Delimiters = %d\n", d);

    return 0;
}

int yywrap()
{
    return 1;
}
