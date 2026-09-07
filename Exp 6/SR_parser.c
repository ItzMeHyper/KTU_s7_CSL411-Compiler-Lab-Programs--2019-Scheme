#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = 0;

char input[MAX];
int input_ptr = 0;

void print_status(const char *action) {
    printf("%-20s %-20s %-20s\n", stack, &input[input_ptr], action);
}

int reduce_once() {
    if (top >= 2 && stack[top - 2] == 'i' && stack[top - 1] == 'd') {
        stack[top - 2] = 'F';
        stack[top - 1] = '\0';
        top -= 1;
        print_status("REDUCE: F -> id");
        return 1;
    }

    if (top >= 3 && stack[top - 3] == '(' && stack[top - 2] == 'E' && stack[top - 1] == ')') {
        stack[top - 3] = 'F';
        stack[top - 2] = '\0';
        top -= 2;
        print_status("REDUCE: F -> (E)");
        return 1;
    }

    if (top >= 3 && stack[top - 3] == 'T' && stack[top - 2] == '*' && stack[top - 1] == 'F') {
        stack[top - 3] = 'T';
        stack[top - 2] = '\0';
        top -= 2;
        print_status("REDUCE: T -> T * F");
        return 1;
    }

    if (top >= 3 && stack[top - 3] == 'E' && stack[top - 2] == '+' && stack[top - 1] == 'T') {
        if (input[input_ptr] != '*') {
            stack[top - 3] = 'E';
            stack[top - 2] = '\0';
            top -= 2;
            print_status("REDUCE: E -> E + T");
            return 1;
        }
    }

    if (top >= 1 && stack[top - 1] == 'F') {
        stack[top - 1] = 'T';
        print_status("REDUCE: T -> F");
        return 1;
    }

    if (top >= 1 && stack[top - 1] == 'T') {
        if (input[input_ptr] != '*') {
            stack[top - 1] = 'E';
            print_status("REDUCE: E -> T");
            return 1;
        }
    }

    return 0;
}

void reduce_all() {
    while (reduce_once()) {
    }
}

int main() {
    char raw_input[MAX];

    printf("Enter expression (e.g., id+id*id): ");
    if (scanf("%s", raw_input) != 1) {
        return 1;
    }

    stack[top++] = '$';
    stack[top] = '\0';

    strcpy(input, raw_input);
    strcat(input, "$");

    printf("\n%-20s %-20s %-20s\n", "STACK", "INPUT", "ACTION");
    printf("----------------------------------------------------------------\n");
    print_status("INITIAL");

    reduce_all();

    int parse_error = 0;
    while (input[input_ptr] != '$') {
        if (input[input_ptr] == 'i' && input[input_ptr + 1] == 'd') {
            stack[top++] = input[input_ptr++];
            stack[top++] = input[input_ptr++];
            stack[top] = '\0';
            print_status("SHIFT id");
        } else if (input[input_ptr] == '+' || input[input_ptr] == '*' || 
                   input[input_ptr] == '(' || input[input_ptr] == ')') {
            stack[top++] = input[input_ptr++];
            stack[top] = '\0';
            print_status("SHIFT symbol");
        } else {
            parse_error = 1;
            break;
        }

        reduce_all();
    }

    if (!parse_error) {
        reduce_all();
    }

    printf("----------------------------------------------------------------\n");
    if (!parse_error && strcmp(stack, "$E") == 0 && input[input_ptr] == '$') {
        printf("Result: SUCCESS (String Accepted)\n");
    } else {
        printf("Result: REJECTED (Invalid Expression)\n");
    }

    return 0;
}