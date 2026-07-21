#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *kw[] = {"int","float","char","if","else","for","while","return","void"};

int isKeyword(char s[]) {
    for(int i=0;i<9;i++)
        if(strcmp(s,kw[i])==0)
            return 1;
    return 0;
}

int main() {
    FILE *fp = fopen("input.c","r");
    char ch, str[50];
    int i;

    if(fp==NULL) {
        printf("File not found");
        return 0;
    }

    while((ch=fgetc(fp))!=EOF) {

        if(isalpha(ch) || ch=='_') {
            i=0;
            do {
                str[i++]=ch;
                ch=fgetc(fp);
            } while(isalnum(ch)||ch=='_');
            str[i]='\0';
            ungetc(ch,fp);

            if(isKeyword(str))
                printf("%-15s  Keyword\n",str);
            else
                printf("%-15s  Identifier\n",str);
        }

        else if(isdigit(ch)) {
            printf("%-15c  Number\n",ch);
        }

        else if(strchr("+-*/=%<>",ch)) {
            printf("%-15c  Operator\n",ch);
        }

        else if(strchr("(){}[];,",ch)) {
            printf("%-15c  Delimiter\n",ch);
        }
    }

    fclose(fp);
    return 0;
}