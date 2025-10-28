#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *p; 

// Forward declarations
int E(), T(), F();

void error() {
    printf("Invalid Expression!\n");
    exit(1);
}

// Match expected character
void match(char c) {
    if (*p == c) p++;
    else error();
}

// Grammar:
// E → T { + T }
// T → F { * F }
// F → (E) | digit

int E() {
    int val = T();
    while (*p == '+') { p++; val += T(); }
    return val;
}

int T() {
    int val = F();
    while (*p == '*') { p++; val *= F(); }
    return val;
}

int F() {
    if (isdigit(*p)) return *p++ - '0';
    if (*p == '(') { p++; int val = E(); match(')'); return val; }
    error();
    return 0;
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);
    p = expr;
    int result = E();
    if (*p == '\0') printf("Result = %d\n", result);
    else error();
}
