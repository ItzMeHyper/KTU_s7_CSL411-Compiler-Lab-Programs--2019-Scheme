%{
#include <stdio.h>

int vowels = 0;
int consonants = 0;
%}

%%

[aeiouAEIOU]          { vowels++; }
[a-zA-Z]              { consonants++; }
.|\n                  { }

%%

void main() {
    printf("Enter a string:\n");
    yylex();

    printf("\nNumber of Vowels: %d\n", vowels);
    printf("Number of Consonants: %d\n", consonants);
}