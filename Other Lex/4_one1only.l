%{
#include <stdio.h>
%}

num 0*10*

%%

{num} printf("Accepted\n");
.+    printf("Not Accepted\n");

%%

void main(){
    printf("Enter the string: ");
    yylex();
}
