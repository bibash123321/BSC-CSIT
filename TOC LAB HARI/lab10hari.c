
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

// Display PDA transition table
void displayTransitionTable() {
    printf("\n--- PDA Transition Table ---\n");
    printf("Current\tInput\tStackTop\tAction\t\tNextState\n");
    printf("------------------------------------------------------------\n");
    printf("q0\t(\tZ\t\tPush(\t\tq0\n");
    printf("q0\t(\t(\t\tPush(\t\tq0\n");
    printf("q0\t)\t(\t\tPop(\t\tq0\n");
    printf("q0\t-\tZ\t\tAccept\t\tqf\n");
    printf("------------------------------------------------------------\n");
}

int main() {
    char input[MAX];
    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    int len = strlen(input);
    int i;
    char currentState = '0'; // q0

    push('Z'); // Initial stack symbol

    displayTransitionTable();
    printf("\n--- PDA Simulation ---\n");
    printf("| Step | Input | StackTop | Action        | Stack After Action |\n");
    printf("---------------------------------------------------------------\n");

    int step = 1;

    for (i = 0; i < len; i++) {
        char symbol = input[i];
        char topSymbol = stack[top];

        if (symbol == '(') {
            // Push '('
            printf("| %3d  |   %c   |     %c     | Push(          | ", step++, topSymbol, symbol);
            push('(');
        } else if (symbol == ')') {
            // Pop '('
            if (topSymbol == '(') {
                printf("| %3d  |   %c   |     %c     | Pop(           | ", step++, topSymbol, symbol);
                pop();
            } else {
                printf("| %3d  |   %c   |     %c     | Reject         | \n", step++, topSymbol, symbol);
                printf("\n Rejected: Unbalanced parentheses.\n");
                return 0;
            }
        } else {
            printf("| %3d  |   %c   |     %c     | Invalid symbol  | \n", step++, topSymbol, symbol);
            printf("\n Rejected: Invalid input character.\n");
            return 0;
        }

        // Display current stack content
        if (top >= 0) {
            for (int j = 0; j <= top; j++) printf("%c", stack[j]);
        } else {
            printf("(empty)");
        }
        printf(" |\n");
    }

    // End of input
    printf("---------------------------------------------------------------\n");
    if (stack[top] == 'Z') {
        printf("Action: Move to qf (Final State)\n");
        printf("\n String Accepted  Well-formed parentheses.\n");
    } else {
        printf("\n Rejected: Stack not empty — Unbalanced parentheses.\n");
    }

    return 0;
}
