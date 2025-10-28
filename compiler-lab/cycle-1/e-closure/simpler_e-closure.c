#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int n, trans[MAX][MAX], visited[MAX];

void epsilonClosure(int s){
    visited[s] = 0;
    for(int i = 0; i < n; i++){
        if(trans[s][i] && !visited[i]) {
            epsilonClosure(i);
        }
    }
}

int main(){
    int from, to;
    char symbol[5];

    printf("Enter number of states ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            trans[i][j] = 0;
        }
    }

    printf("Enter transitons like 1 e 2 \t");
    while(1){
        scanf("%s", symbol);
        if(strcmp(symbol, "-1") == 0) break;
        from = atoi(symbol);
        scanf("%s", symbol);
        scanf("%s", &to);
        if(symbol[0] == 'e') trans[from - 1][to - 1] = 1; // e transition
    }

    for(int s = 0; s < n; s++){
        for(int i = 0; i < n; i++) visited[i] = 0;
        epsilonClosure(s);
        printf("epsilon closure(%d) : { ", s + 1);

        for(int i = 0; i < n; i++){
            if(visited[i]) printf("%d", i + 1);
        }

        printf("} \n");
    }

    return 0;
}