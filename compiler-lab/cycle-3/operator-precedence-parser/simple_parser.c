#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, i = 0;

// Precedence table for +, *, (, ), i, #
char table[6][6] = {
    //   +    *    (    )   i    #
    {'>', '<', '<', '>', '<', '>'}, // +
    {'>', '>', '<', '>', '<', '>'}, // *
    {'<', '<', '<', '=', '<', ' '}, // (
    {'>', '>', ' ', '>', ' ', '>'}, // )
    {'>', '>', ' ', '>', ' ', '>'}, // i (id)
    {'<', '<', '<', ' ', '<', 'a'}  // # (end marker)
};

// Map symbol to table index
int getIndex(char c) {
    if (c == '+') return 0;
    if (c == '*') return 1;
    if (c == '(') return 2;
    if (c == ')') return 3;
    if (c == 'i') return 4; // treat 'id' as 'i'
    if (c == '#') return 5;
    return -1;
}

// Find precedence relation between two symbols
char relation(char a, char b) {
    int x = getIndex(a), y = getIndex(b);
    if (x == -1 || y == -1) return ' ';
    return table[x][y];
}

int main() {
    printf("Enter expression ending with #: ");
    scanf("%s", input); // e.g., i+i*i#

    stack[++top] = '#'; // initialize stack

    printf("\n%-10s %-15s %-15s %-10s\n", "Step", "Stack", "Input", "Action");
    printf("----------------------------------------------------\n");

    int step = 1;
    while (1) {
        char a = stack[top]; // top of stack
        char b = input[i];   // next input symbol
        char rel = relation(a, b);

        // Show current status
        printf("%-10d %-15s %-15s ", step++, stack, input + i);

        if (rel == '<' || rel == '=') {
            printf("Shift %c\n", b);
            stack[++top] = b;
            i++;
        } 
        else if (rel == '>') {
            printf("Reduce %c\n", stack[top]);
            top--; // pop (reduce)
        } 
        else if (rel == 'a') {
            printf("Accept\n");
            printf("\nExpression Accepted!\n");
            break;
        } 
        else {
            printf("Reject\n");
            printf("\nInvalid Expression!\n");
            break;
        }
    }
    return 0;
}
