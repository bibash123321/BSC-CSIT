// (())

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// PDA States
typedef enum { q0, q1, q2, q_reject } State;

// Stack for PDA
char stack[MAX];
int top = -1;

// Transition record for table
typedef struct {
    int step;
    char input;
    char stack_top;
    char action[20];
    State current;
    State next;
} Transition;

Transition table[1000];
int row = 0;

// Push to stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '#'; // bottom of stack
}

// Print state name
const char* stateName(State s) {
    switch(s) {
        case q0: return "q0 (Start)";
        case q1: return "q1 (Loop)";
        case q2: return "q2 (Accept)";
        case q_reject: return "REJECT";
        default: return "UNKNOWN";
    }
}

// Add transition to table
void addTransition(int step, char input, char stack_top, const char* action, State curr, State next) {
    table[row].step = step;
    table[row].input = input;
    table[row].stack_top = stack_top;
    strcpy(table[row].action, action);
    table[row].current = curr;
    table[row].next = next;
    row++;
}

// Print the transition table
void printTable() {
    printf("\n");
    printf("+-------+-------+-----------+----------------+-------------+-------------+\n");
    printf("| Step  | Input | Stack Top | Action         | Current     | Next        |\n");
    printf("+-------+-------+-----------+----------------+-------------+-------------+\n");

    for (int i = 0; i < row; i++) {
        printf("| %-5d | %-5c | %-9c | %-14s | %-11s | %-11s |\n",
               table[i].step,
               table[i].input ? table[i].input : ' ',
               table[i].stack_top,
               table[i].action,
               stateName(table[i].current),
               stateName(table[i].next));
    }

    printf("+-------+-------+-----------+----------------+-------------+-------------+\n");
}

// PDA Simulation with tracing
int simulatePDA(char *str) {
    State current = q0;
    int i = 0, step = 1;
    char ch;
    top = -1;
    push('#'); // Stack bottom marker

    // Initial state
    addTransition(step++, '-', '#', "Start", q0, q0);

    while (str[i] != '\0') {
        ch = str[i];

        if (ch != '(' && ch != ')') {
            addTransition(step++, ch, stack[top], "Invalid Char", current, q_reject);
            return 0;
        }

        if (current == q0 || current == q1) {
            if (ch == '(') {
                push('(');
                addTransition(step++, '(', stack[top-1], "Push '('", current, q1);
                current = q1;
            }
            else if (ch == ')') {
                if (top <= 0 || stack[top] != '(') {
                    addTransition(step++, ')', stack[top], "Pop Fail", current, q_reject);
                    return 0;
                }
                pop();
                addTransition(step++, ')', '(', "Pop '('", current, q1);
                current = q1;
            }
        }
        i++;
    }

    // Final check
    if (top == 0 && stack[top] == '#') { // Only bottom marker left
        addTransition(step++, '-', '#', "Accept", q1, q2);
        current = q2;
    } else {
        addTransition(step++, '-', stack[top], "Stack Not Empty", q1, q_reject);
        current = q_reject;
    }

    return (current == q2);
}

int main() {
    char str[MAX];

    printf("=== PDA for Well-Formed Parentheses ===\n");
    printf("Enter string (only '(' and ')'): ");
    scanf("%s", str);

    printf("\nSimulating PDA...\n\n");

    int accepted = simulatePDA(str);

    // Print the trace table
    printTable();

    // Final Result
    printf("\n>>> ");
    if (accepted) {
        printf("ACCEPTED: \"%s\" is WELL-FORMED\n", str);
    } else {
        printf("REJECTED: \"%s\" is NOT well-formed\n", str);
    }

    return 0;
}