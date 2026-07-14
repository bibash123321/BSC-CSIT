#include <stdio.h>
#include <string.h>

int main() {
    char str[100], stack[100];
    int top = -1, step = 1;

    printf("Enter string over {a,b}: ");
    scanf("%s", str);
    int n = strlen(str);

    printf("\n|Step|Inp|Top|Action   |Stack|\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < n; i++) {
        char a = str[i];
        char X = (top >= 0) ? stack[top] : ' ';

        if (a == 'a') {
            stack[++top] = 'a';
            printf("|%3d | %c | %c | Push a  | ", step++, a, X);
            for (int j = 0; j <= top; j++) printf("%c", stack[j]);
            printf("\n");
        }
        else if (a == 'b') {
            if (top >= 0 && stack[top] == 'a') {
                top--;
                printf("|%3d | %c | %c | Pop a   | ", step++, a, X);
                if (top == -1) printf("(empty)");
                else for (int j = 0; j <= top; j++) printf("%c", stack[j]);
                printf("\n");
            } else {
                printf("|%3d | %c | %c | Reject  | (no match)\n", step++, a, X);
                printf("-----------------------------------\nRejected: invalid order or more b's.\n");
                return 0;
            }
        }
        else {
            printf("|%3d | %c | %c | Invalid | \n", step++, a, X);
            printf("-----------------------------------\nRejected: invalid symbol found.\n");
            return 0;
        }
    }

    printf("-----------------------------------\n");
    if (top == -1)
        printf("Accepted: equal number of a followed by b.\n");
    else
        printf("Rejected: unmatched 'a' remaining.\n");

    return 0;
}

