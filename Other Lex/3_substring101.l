%{
#include <stdio.h>
%}

num (0|1)*101(0|1)*

%%

{num} printf("Accepted\n");
.+    printf("Not Accepted\n");

%%

void main(){
    printf("Enter the string: ");
    yylex();
}
