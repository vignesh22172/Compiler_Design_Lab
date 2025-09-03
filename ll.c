#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[30], st[30];
char m[5][6][4] = {
    {"tb","","","","tb",""},
    {"","+tb","","","n","n"},
    {"fc","","","","fc",""},
    {"","n","*fc","n","n","n"},
    {"i","","","(e)","",""}
};
int sz[5][6]={{2,0,0,2,0,0},{0,3,0,0,1,1},{2,0,0,2,0,0},{0,1,3,0,1,1},{1,0,0,3,0,0}};

int nt(char c){return c=='e'?0:c=='b'?1:c=='t'?2:c=='c'?3:4;}
int tm(char c){return c=='i'?0:c=='+'?1:c=='*'?2:c=='('?3:c==')'?4:5;}

int main(){
    int i=1,j=0,k,n,a,b;
    printf("Input: "); scanf("%s",s); strcat(s,"$"); n=strlen(s);
    st[0]='$'; st[1]='e';
    printf("\nStack\tInput\n");
    while(st[i]!='$'&&s[j]!='$'){
        if(st[i]==s[j]){i--;j++;}
        a=nt(st[i]); b=tm(s[j]);
        if(!m[a][b][0]){printf("ERROR\n");return 0;}
        if(m[a][b][0]=='n') i--;
        else{for(k=sz[a][b]-1;k>=0;k--) st[i++]=m[a][b][k]; i--;}
        for(k=0;k<=i;k++) printf("%c",st[k]); printf("\t");
        for(k=j;k<n;k++) printf("%c",s[k]); printf("\n");
    }
    printf("SUCCESS\n");
}

