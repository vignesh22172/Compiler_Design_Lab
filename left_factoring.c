#include <stdio.h>
#include <string.h>

int main() {
    char non_terminal;
    char production[20][20];
    int num;

    printf("Enter the non-terminal: ");
    scanf(" %c", &non_terminal);

    printf("Enter number of productions: ");
    scanf("%d", &num);

    printf("Enter the productions (without spaces):\n");
    for(int i = 0; i < num; i++) {
        printf("%c -> ", non_terminal);
        scanf("%s", production[i]);
    }

    // Left factoring: find common prefix
    char prefix[20];
    int prefix_len = 0;

    // find prefix between first two productions
    for(int i = 0; production[0][i] && production[1][i]; i++) {
        if(production[0][i] == production[1][i]) {
            prefix[prefix_len++] = production[0][i];
        } else {
            break;
        }
    }
    prefix[prefix_len] = '\0';

    if(prefix_len > 0) {
        printf("\nAfter Left Factoring:\n");
        printf("%c -> %s%c'\n", non_terminal, prefix, non_terminal);
        printf("%c' -> ", non_terminal);

        for(int i = 0; i < num; i++) {
            if(strlen(production[i]) == prefix_len) {
                printf("ε"); // epsilon
            } else {
                printf("%s", production[i] + prefix_len);
            }
            if(i != num - 1) printf(" | ");
        }
        printf("\n");
    } else {
        printf("\nNo left factoring needed.\n");
    }

    return 0;
}

