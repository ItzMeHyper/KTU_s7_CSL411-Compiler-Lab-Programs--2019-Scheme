%{
#include <stdio.h>
%}

keyword     if|else|while|for|int|float|char|double|return|void
letter      [a-zA-Z]
digit       [0-9]
identifier  {letter}({letter}|{digit})*
number      {digit}+
operator    \+|\-|\*|\/|%|=|==|!=|<=|>=|<|>
delimiter   \(|\)|\{|\}|\[|\]|;|,

%%

{keyword}      { printf("Keyword : %s", yytext); }

{number}       { printf("Number : %s", yytext); }

{identifier}   { printf("Identifier : %s", yytext); }

{operator}     { printf("Operator : %s", yytext); }

{delimiter}    { printf("Delimiter : %s", yytext); }

.+             { printf("Unknown : %s", yytext); }

%%

void main()
{
    yylex();
}