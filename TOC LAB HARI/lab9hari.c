#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop operation
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

// Function to show stack content
void showStack() {
    printf("Stack: [");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("]\n");
}

// Function to display PDA Transition Table
void displayTransitionTable() {
    printf("\n--- PDA Transition Table ---\n");
    printf("Current\tInput\tStackTop\tAction\t\tNextState\n");
    printf("------------------------------------------------------------\n");
    printf("q0\t0\tZ\t\tPush(0)\t\tq0\n");
    printf("q0\t0\t0\t\tPush(0)\t\tq0\n");
    printf("q0\t1\t0\t\tPop(0)\t\tq1\n");
    printf("q1\t1\t0\t\tPop(0)\t\tq1\n");
    printf("q1\tε\tZ\t\tAccept\t\tqf\n");
    printf("------------------------------------------------------------\n");
}

int main() {
    char input[MAX];
    int i, len;
    char currentState = '0'; // '0' means q0, '1' means q1

    printf("Enter a string over {0,1}: ");
    scanf("%s", input);
    len = strlen(input);

    // Initial stack symbol
    push('Z');

    displayTransitionTable();

    printf("\n--- PDA Simulation ---\n");

    for (i = 0; i < len; i++) {
        char symbol = input[i];
        char topSymbol = stack[top];

        printf("\nStep %d: State=q%c, Input=%c, StackTop=%c\n", i + 1, currentState, symbol, topSymbol);

        // State q0 transitions
        if (currentState == '0') {
            if (symbol == '0') {
                if (topSymbol == 'Z' || topSymbol == '0') {
                    push('0');
                    printf("Action: Push(0), NextState=q0\n");
                } else {
                    printf("Invalid transition!\n");
                    return 0;
                }
            } else if (symbol == '1') {
                if (topSymbol == '0') {
                    pop();
                    currentState = '1';
                    printf("Action: Pop(0), NextState=q1\n");
                } else {
                    printf("Invalid transition!\n");
                    return 0;
                }
            } else {
                printf("Invalid input symbol!\n");
                return 0;
            }
        }

        // State q1 transitions
        else if (currentState == '1') {
            if (symbol == '1') {
                if (topSymbol == '0') {
                    pop();
                    printf("Action: Pop(0), NextState=q1\n");
                } else {
                    printf("Invalid transition!\n");
                    return 0;
                }
            } else {
                printf("Invalid transition in q1!\n");
                return 0;
            }
        }

        // Show stack after each step
        showStack();
    }

    // End of input
    printf("\nEnd of input reached.\n");
    showStack();

    // Acceptance condition
    if (currentState == '1' && stack[top] == 'Z') {
        printf("Action:  Move to qf (Final State)\n");
        printf("\n String Accepted by PDA!\n");
    } else {
        printf("\n String Rejected by PDA!\n");
    }

    return 0;
}
