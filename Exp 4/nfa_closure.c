#include <stdio.h>
#include <string.h>

char result[20][20], states[20][20];
char copy[20];

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
        printf("Error opening input.txt\n");
        return 1;
    }

    char state[20], state1[20], state2[20], input[20];

    int n, i, k, end;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the states:\n");
    for (k = 0; k < n; k++){
        scanf("%s", states[k]);
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
    }

    fclose(INPUT);
    return 0;
}
