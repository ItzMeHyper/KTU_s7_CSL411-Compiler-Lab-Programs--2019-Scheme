#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch, str[50];
    char keywords[][10] = {
        "int", "float", "char", "double",
        "if", "else", "while", "for",
        "return", "void"
    };

    int i, j, flag;

    fp = fopen("input.txt", "r");

    if(fp == NULL){
        printf("Cannot open file.\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF){
        if(ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        if(ch == '/'){
            char next = fgetc(fp);

            if(next == '/' || '*'){
                while((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            } else {
                printf("/ Operator\n");
                ungetc(next, fp);
                continue;
            }
        }

        if(isalpha(ch) || ch == '_'){
            i = 0;
            str[i++] = ch;

            while((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_')){
                str[i++] = ch;
            }

            str[i] = '\0';

            if(ch != EOF)
                ungetc(ch, fp);

            flag = 0;

            for(j = 0; j < 10; j++){
                if(strcmp(str, keywords[j]) == 0){
                    flag = 1;
                    break;
                }
            }

            if(flag)
                printf("%s \t\tKeyword\n", str);
            else
                printf("%s \t\tIdentifier\n", str);
        } else if(isdigit(ch)){
            i = 0;
            str[i++] = ch;

            while((ch = fgetc(fp)) != EOF && (isdigit(ch) || ch == '.')){
                str[i++] = ch;
            }

            str[i] = '\0';

            if(ch != EOF)
                ungetc(ch, fp);

            printf("%s \t\tNumber\n", str);
        } else if(ch == '+' || ch == '-' || ch == '*' ||
                ch == '=' || ch == '<' || ch == '>') {
            printf("%c \t\tOperator\n", ch);
        } else if(ch == '(' || ch == ')' || ch == '{' ||
                ch == '}' || ch == ';' || ch == ',') {
            printf("%c \t\tDelimiter\n", ch);
        }
    }

    fclose(fp);
    return 0;
}