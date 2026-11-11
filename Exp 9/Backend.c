#include <stdio.h>
#include <string.h>
char op[2], arg1[5], arg2[5], result[5];

void main() {
  FILE *fp1, *fp2;
  char f[100];
  //printf("Enter input file name: ");
  //scanf("%[^\n]s", f);
  fp1 = fopen("k.txt", "r");
  fp2 = fopen("output.txt", "w");
  while (!feof(fp1)){
    fscanf(fp1, "%s%s%s%s", op, arg1, arg2, result);

    if (strcmp(op, "+") == 0) {
      fprintf(fp2, "MOV AX,%s\n", arg1);
      fprintf(fp2, "ADD AX,%s\n", arg2);
      fprintf(fp2, "MOV %s,AX\n", result);
    }else if (strcmp(op, "*") == 0) {
      fprintf(fp2, "MOV AX,%s\n", arg1);
      fprintf(fp2, "MUL AX,%s\n", arg2);
      fprintf(fp2, "MOV %s,AX\n", result);
    }else if (strcmp(op, "-") == 0) {
      fprintf(fp2, "MOV AX,%s\n", arg1);
      fprintf(fp2, "SUB AX,%s\n", arg2);
      fprintf(fp2, "MOV %s,AX\n", result);
    }else if (strcmp(op, "/") == 0) {
      fprintf(fp2, "MOV AX,%s\n", arg1);
      fprintf(fp2, "DIV AX,%s\n", arg2);
      fprintf(fp2, "MOV %s,AX\n", result);
    }else if (strcmp(op, "=") == 0) {
      fprintf(fp2, "MOV AX,%s\n", arg1);
      fprintf(fp2, "MOV %s,AX\n", result);
    }
  }

  fclose(fp1);
  fclose(fp2);
}