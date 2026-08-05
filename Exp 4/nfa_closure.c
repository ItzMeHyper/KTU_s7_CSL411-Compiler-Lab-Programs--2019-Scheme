#include <stdio.h>
#include <string.h>

char result[20][20];
char copy[20];
char states[20][20];

void add_state(char a[], int *count){
    int i;

    for (i = 0; i < *count; i++){
        if (strcmp(result[i], a) == 0)
            return;
    }

    strcpy(result[*count], a);
    (*count)++;
}

void display(int n){
    int k;

    printf("Epsilon closure of %s = { ", copy);

    for (k = 0; k < n; k++){
        printf("%s ", result[k]);
    }

    printf("}\n");
}

int main(){
    FILE *INPUT;

    INPUT = fopen("input.dat", "r");

    if (INPUT == NULL){
        printf("Error opening input.dat\n");
        return 1;
    }

    char state[20];
    char state1[20], input[20], state2[20];

    int n, i, k, end;

    fscanf(INPUT, "%d", &n);

    for (k = 0; k < n; k++){
        fscanf(INPUT, "%s", states[k]);
    }

    for (k = 0; k < n; k++){
        i = 0;

        strcpy(state, states[k]);
        strcpy(copy, state);

        add_state(state, &i);

        while (1){
            end = fscanf(INPUT, "%s %s %s", state1, input, state2);

            if (end == EOF)
                break;

            if (strcmp(state, state1) == 0 && strcmp(input, "e") == 0){
                add_state(state2, &i);
                strcpy(state, state2);
            }
        }

        display(i);

        rewind(INPUT);
        fscanf(INPUT, "%d", &n);

        for (i = 0; i < n; i++){
            fscanf(INPUT, "%s", states[i]);
        }
    }

    fclose(INPUT);
    return 0;
}
