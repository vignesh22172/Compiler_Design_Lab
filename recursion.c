#include <stdio.h>
#include <string.h>

int main() {
    char nt, prod[20][20];
    int n;
    printf("Enter Non-Terminal: ");
    scanf(" %c",&nt);
    printf("Enter number of productions: ");
    scanf("%d",&n);
    printf("Enter productions:\n");
    for(int i=0;i<n;i++) scanf("%s",prod[i]);

    int hasLR=0;
    printf("\nAfter Eliminating Left Recursion:\n");
    for(int i=0;i<n;i++) {
        if(prod[i][0]==nt) hasLR=1;
    }

    if(hasLR) {
        printf("%c -> ",nt);
        for(int i=0;i<n;i++) {
            if(prod[i][0]!=nt) printf("%s%c' ",prod[i],nt);
        }
        printf("\n%c' -> ",nt);
        for(int i=0;i<n;i++) {
            if(prod[i][0]==nt) printf("%s%c' ",prod[i]+1,nt);
        }
        printf("| ε\n");
    } else {
        for(int i=0;i<n;i++) printf("%c -> %s\n",nt,prod[i]);
    }
    return 0;
}

