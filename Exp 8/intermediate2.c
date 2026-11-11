#include <stdio.h>
#include <string.h>

int main() {
    char e[100], t = 'Z', lhs;
    int i, j, n;

    printf("Enter the expression: ");
    scanf("%99s", e);

    lhs = e[0];

    memmove(e, e + 2, strlen(e + 2) + 1);

    for (j = 0; j < 2; j++) {
        char *ops = (j == 0) ? "*/" : "+-";

        for (i = 1; i < (int)strlen(e) - 1; i++) {
            if (strchr(ops, e[i])) {
                printf("%c := %c%c%c\n", t, e[i - 1], e[i], e[i + 1]);

                e[i - 1] = t;

                n = strlen(e);
                memmove(e + i, e + i + 2, n - i - 1);

                t--;
                i = 0;
            }
        }
    }
    printf("%c := %s\n", lhs, e);
    return 0;
}