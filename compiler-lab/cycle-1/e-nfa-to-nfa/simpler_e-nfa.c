#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
int n, visited[MAX], eTrans[MAX][MAX], trans[MAX][MAX][MAX]; // trans[from][symbol][to]
char symbols[MAX];
int nSymbols = 0;

void epsilonClosure(int s, int closure[MAX]) {
    visited[s] = 1;
    closure[s] = 1;
    for (int i = 0; i < n; i++)
        if (eTrans[s][i] && !visited[i])
            epsilonClosure(i, closure);
}

int findSymbolIndex(char c) {
    for (int i = 0; i < nSymbols; i++)
        if (symbols[i] == c)
            return i;
    symbols[nSymbols++] = c;
    return nSymbols - 1;
}

int main() {
    int from, to;
    char sym[5];
    printf("Enter number of states: ");
    scanf("%d", &n);

    memset(eTrans, 0, sizeof(eTrans));
    memset(trans, 0, sizeof(trans));

    printf("Enter transitions (e.g. 1 e 2 or 1 0 3). Type -1 to stop:\n");
    while (1) {
        scanf("%s", sym);
        if (strcmp(sym, "-1") == 0) break;
        from = atoi(sym);
        scanf("%s", sym);
        scanf("%d", &to);
        if (sym[0] == 'e') eTrans[from - 1][to - 1] = 1;
        else {
            int idx = findSymbolIndex(sym[0]);
            trans[from - 1][idx][to - 1] = 1;
        }
    }

    // Compute ε-closures
    int eClosure[MAX][MAX] = {0};
    for (int s = 0; s < n; s++) {
        memset(visited, 0, sizeof(visited));
        epsilonClosure(s, eClosure[s]);
    }

    // Print ε-closures
    printf("\nε-closures:\n");
    for (int s = 0; s < n; s++) {
        printf("ε-closure(%d): { ", s + 1);
        for (int i = 0; i < n; i++)
            if (eClosure[s][i]) printf("%d ", i + 1);
        printf("}\n");
    }

    // Convert ε-NFA to NFA
    printf("\nEquivalent NFA transitions (without ε):\n");
    for (int s = 0; s < n; s++) {
        for (int a = 0; a < nSymbols; a++) {
            int reach[MAX] = {0};
            for (int i = 0; i < n; i++) if (eClosure[s][i]) {
                for (int j = 0; j < n; j++) if (trans[i][a][j]) {
                    for (int k = 0; k < n; k++)
                        if (eClosure[j][k]) reach[k] = 1;
                }
            }
            printf("δ(%d, %c) = { ", s + 1, symbols[a]);
            int any = 0;
            for (int j = 0; j < n; j++)
                if (reach[j]) { printf("%d ", j + 1); any = 1; }
            if (!any) printf("—");
            printf("}\n");
        }
    }

    return 0;
}
