%{
#include <stdio.h>
%}

id   [a-zA-Z_][a-zA-Z0-9_]*
num  [0-9]+
key  (int|float|char|if|else|while|for|return)

%%
{key}       { printf("%s : KEYWORD\n", yytext); }
{id}        { printf("%s : IDENTIFIER\n", yytext); }
{num}       { printf("%s : NUMBER\n", yytext); }
"="|"=="    { printf("%s : OPERATOR\n", yytext); }
"/*"([^*]|\*+[^*/])*\*+"/"   { printf("COMMENT\n"); }
\".*\"      { printf("%s : STRING\n", yytext); }
"{"|"}"|"("|")"|";"|"," { printf("%s : SPECIAL SYMBOL\n", yytext); }
%%

int main() { yylex(); return 0; }
int yywrap() { return 1; }

