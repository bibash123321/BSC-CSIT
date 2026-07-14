#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char stack[100];
    int top = -1, step = 1;

    printf("Enter string over {0,1}: ");
    scanf("%s", str);

    int n = strlen(str);

    printf("\n================ Transition Table =================\n");
    printf("| Step | Input | Stack Top | Action        | Stack Content |\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        char a = str[i];
        char X = (top >= 0) ? stack[top] : 'ε';   // ε represents empty stack

        // Push for '0'
        if (a == '0') {
            stack[++top] = '0';
            printf("| %3d  |   %c   |     %c     | Push 0       | ", step++, X, a);
            for (int j = 0; j <= top; j++) printf("%c", stack[j]);
            printf("\n");
        }

        // Pop for '1'
        else if (a == '1') {
            if (top >= 0 && stack[top] == '0') {
                top--;
                printf("| %3d  |   %c   |     %c     | Pop 0        | ", step++, X, a);
                if (top == -1) printf("ε");
                else for (int j = 0; j <= top; j++) printf("%c", stack[j]);
                printf("\n");
            } else {
                printf("| %3d  |   %c   |     %c     | Reject       | (no match)\n", step++, X, a);
                printf("-------------------------------------------------------------\n");
                printf("Rejected: more 1’s than 0’s or wrong order.\n");
                return 0;
            }
        }

        // Invalid symbol
        else {
            printf("| %3d  |   %c   |     %c     | Invalid      | \n", step++, X, a);
            printf("-------------------------------------------------------------\n");
            printf("Rejected: invalid input symbol.\n");
            return 0;
        }
    }

    printf("-------------------------------------------------------------\n");
    if (top == -1)
        printf("Accepted: equal number of 0’s followed by 1’s.\n");
    else
        printf("Rejected: unmatched 0’s remaining in stack.\n");

    return 0;
}
