%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]    { vowels++; }
[a-zA-Z]        { consonants++; }
[ \t\n]         ;

%%

int main()
{
printf("Enter a string (Ctrl+D to stop):\n\n");
yylex();
printf("\n--- Result ---\n");
printf("Vowels     = %d\n", vowels);
printf("Consonants = %d\n", consonants);
return 0;
}

int yywrap()
{
    return 1;
}

