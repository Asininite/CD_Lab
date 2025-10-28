#include <stdio.h>
#include <string.h>

char in[100], st[100]; int top=-1, n;

void show(int i, char *act){
    printf("$%.*s\t\t%s$\t\t%s\n", top+1, st, in+i, act);
}

void reduce(int i){
    int f=1;
    while(f){
        f=0;
        if(top>=2 && st[top-2]=='S' && (st[top-1]=='+'||st[top-1]=='-') && st[top]=='S'){
            top-=2; st[top]='S'; show(i,"REDUCE"); f=1;
        }
        else if(top>=2 && st[top-2]=='('&&st[top-1]=='S'&&st[top]==')'){
            top-=2; st[top]='S'; show(i,"REDUCE"); f=1;
        }
        else if(st[top]=='i'){ st[top]='S'; show(i,"REDUCE"); f=1; }
    }
}

int main(){
    printf("Enter input: "); scanf("%s",in);
    n=strlen(in);
    printf("Stack\t\tInput\t\tAction\n");
    for(int i=0;i<n;i++){
        st[++top]=in[i];
        show(i,"SHIFT");
        reduce(i+1);
    }
    if(top==0&&st[0]=='S') printf("Accepted.\n");
    else printf("Rejected.\n");
}
