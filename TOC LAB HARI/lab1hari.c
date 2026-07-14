#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j, n;
    printf("Enter string: ");
    scanf("%s", s);
    n = strlen(s);

    printf("\nPrefixes:\n");
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) printf("%c", s[j]);
        printf("\n");
    }

    printf("\nSuffixes:\n");
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) printf("%c", s[j]);
        printf("\n");
    }

    printf("\nSubstrings:\n");
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            for (int k = i; k <= j; k++) printf("%c", s[k]);
            printf("\n");
        }
    }

    printf("\nTransition Table:\n");
    for (i = 0; i < n; i++) printf("State %d -> %c\n", i, s[i]);
    printf("State %d -> End\n", n);

    return 0;
}