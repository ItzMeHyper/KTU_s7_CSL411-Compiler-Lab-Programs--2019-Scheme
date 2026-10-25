%{
#include <stdio.h>
int lines = 0;
int words = 0;
int chars = 0;
%}

%%

\n              { lines++; chars++; }
[ \t]+          { chars += yyleng; }
[^ \t\n]+       { words++; chars += yyleng; }

%%


void main(){
    printf("Enter the text (Press Ctrl+D to end in Linux / Ctrl+Z then Enter in Windows):\n");
    yylex();

    printf("\nLines : %d", lines);
    printf("\nWords : %d", words);
    printf("\nCharacters : %d\n", chars);
}