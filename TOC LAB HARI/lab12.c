
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

void displayTransitionTable() {
    printf("\n--- PDA Transition Table ---\n");
    printf("Current\tInput\tStackTop\tAction\t\tNextState\n");
    printf("-------------------------------------------------------------\n");
    printf("q0\t0\tZ/0/1\t\tPush(0)\t\tq0\n");
    printf("q0\t1\tZ/0/1\t\tPush(1)\t\tq0\n");
    printf("q0\t-\tZ/0/1\t\tMove\t\tq1\n");
    printf("q1\t0\t0\t\tPop(0)\t\tq1\n");
    printf("q1\t1\t1\t\tPop(1)\t\tq1\n");
    printf("q1\t-\tZ\t\tAccept\t\tqf\n");
    printf("-------------------------------------------------------------\n");
}

int main() {
    char input[MAX];
    printf("Enter a binary string (W Wᴿ): ");
    scanf("%s", input);

    int len = strlen(input);
    int i;
    int mid = len / 2; // midpoint (approximation for even-length palindrome)
    char currentState = '0'; // q0

    push('Z'); // initial stack symbol

    displayTransitionTable();
    printf("\n--- PDA Simulation ---\n");
    printf("| Step | Input | State | StackTop | Action         | Stack After Action |\n");
    printf("--------------------------------------------------------------------------\n");

    int step = 1;

    // Phase 1: Push first half of input
    for (i = 0; i < mid; i++) {
        char symbol = input[i];
        char topSymbol = stack[top];
        printf("| %3d  |   %c   |  q0   |    %c     | Push(%c)        | ", step++, symbol, topSymbol, symbol);
        push(symbol);
        for (int j = 0; j <= top; j++) printf("%c", stack[j]);
        printf(" |\n");
    }

    // Epsilon move: q0 → q1 (guess midpoint)
    printf("| %3d  |  -  |  q0   |    %c     | Move to q1      | ", step++, stack[top]);
    for (int j = 0; j <= top; j++) printf("%c", stack[j]);
    printf(" |\n");

    // Phase 2: Pop for second half
    for (; i < len; i++) {
        char symbol = input[i];
        char topSymbol = stack[top];

        if ((symbol == '0' && topSymbol == '0') || (symbol == '1' && topSymbol == '1')) {
            printf("| %3d  |   %c   |  q1   |    %c     | Pop(%c)         | ", step++, symbol, topSymbol, topSymbol);
            pop();
        } else {
            printf("| %3d  |   %c   |  q1   |    %c     | Reject (no match)|\n", step++, symbol, topSymbol);
            printf("\nRejected: Not of the form W W^r.\n");
            return 0;
        }

        if (top >= 0) {
            for (int j = 0; j <= top; j++) printf("%c", stack[j]);
        } else {
            printf("(empty)");
        }
        printf(" |\n");
    }

    printf("--------------------------------------------------------------------------\n");
    if (stack[top] == 'Z') {
        printf("Action:  Move to qf (Final State)\n");
        printf("\nAccepted: String is of the form W W^r (Palindrome).\n");
    } else {
        printf("\nRejected: Stack not empty — unmatched symbols.\n");
    }

    return 0;
}
