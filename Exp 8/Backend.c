#include <stdio.h>
#include <string.h>
char op[2],arg1[5],arg2[5],result[5];
void main()
{
  FILE *fp1,*fp2;
  char f[100];
  printf("Enter input file name: ");
  scanf("%[^\n]s",f);
  fp1=fopen(f,"r");
  fp2=fopen("output.txt","w");
  while(!feof(fp1))
  {

    fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);
    if(strcmp(op,"+")==0)
    {
      fprintf(fp2,"\nMOV AX,%s",arg1);
      fprintf(fp2,"\nADD AX,%s",arg2);
      fprintf(fp2,"\nMOV %s,AX",result);
    }
     if(strcmp(op,"*")==0)
    {
      fprintf(fp2,"\nMOV AX,%s",arg1);
      fprintf(fp2,"\nMUL AX,%s",arg2);
      fprintf(fp2,"\nMOV %s,AX",result);
    }
    if(strcmp(op,"-")==0)
    {
      fprintf(fp2,"\nMOV AX,%s",arg1);
      fprintf(fp2,"\nSUB AX,%s",arg2);
      fprintf(fp2,"\nMOV %s,AX",result);
    }
       if(strcmp(op,"/")==0)
    {
      fprintf(fp2,"\nMOV AX,%s",arg1);
      fprintf(fp2,"\nDIV AX,%s",arg2);
      fprintf(fp2,"\nMOV %s,AX",result);
    }
if(strcmp(op,"=")==0)
    {
      fprintf(fp2,"\nMOV AX,%s",arg1);
      fprintf(fp2,"\nMOV %s,AX",result);
    }
  }
    fclose(fp1);
    fprintf(fp2,"\n");
    fclose(fp2);
    getchar();
}
