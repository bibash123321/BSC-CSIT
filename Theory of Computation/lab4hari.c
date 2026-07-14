#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100];
    int i, len, n;

    printf("Enter a binary string: ");
    scanf("%s", str);
    len = strlen(str);

    printf("Enter number of consecutive 1's to accept: ");
    scanf("%d", &n);

    /* -------------------- DFA -------------------- */
    int state = 0;

    printf("\n================ DFA Simulation ================\n");
    printf("DFA Transition Table:\n");
    printf("--------------------------------\n");
    printf("| Current | Input | Next State |\n");
    printf("--------------------------------\n");
    for(i = 0; i <= n; i++){
        printf("|   q%d    |   0   |   q0      |\n", i);
        if(i < n) printf("|   q%d    |   1   |   q%d      |\n", i, i+1);
        else printf("|   q%d    |   1   |   q%d      |\n", i, n);
    }
    printf("--------------------------------\n\n");

    printf("DFA Working Mechanism:\n");
    printf("---------------------------\n");
    printf("| Input | From | To  |\n");
    printf("---------------------------\n");

    for(i = 0; i < len; i++){
        char ch = str[i];
        int prev = state;
        if(state < n){
            state = (ch == '1') ? state + 1 : 0;
        }
        printf("|   %c    |  q%d  | q%d |\n", ch, prev, state);
    }
    printf("---------------------------\n");
    printf("DFA Result: %s\n", (state == n) ? "Accepted" : "Rejected");

    /* -------------------- NFA -------------------- */
    int *curr = (int*)calloc(n+1, sizeof(int));
    curr[0] = 1; // initial state active

    printf("\n================ Enhanced NFA Simulation ================\n");
    printf("NFA Transition Table:\n");
    printf("--------------------------------------\n");
    printf("| Current | Input | Next State(s) |\n");
    printf("--------------------------------------\n");
    for(i = 0; i <= n; i++){
        printf("|   q%d    |   0   |   q0       |\n", i);
        if(i < n) printf("|   q%d    |   1   |   q%d       |\n", i, i+1);
        else printf("|   q%d    |   1   |   q%d       |\n", i, n);
    }
    printf("--------------------------------------\n\n");

    printf("Enhanced NFA Working Mechanism:\n");
    printf("-------------------------------------------------------------\n");
    printf("Step | Input | Active States After Input\n");
    printf("-------------------------------------------------------------\n");

    for(i = 0; i < len; i++){
        char ch = str[i];
        int *next = (int*)calloc(n+1, sizeof(int));

        if(ch == '0'){
            for(int j = 0; j <= n; j++){
                if(curr[j]) next[0] = 1;
            }
        } else if(ch == '1'){
            for(int j = 0; j <= n; j++){
                if(curr[j] && j < n) next[j+1] = 1;
                else if(curr[j] && j == n) next[n] = 1;
            }
        }

        printf("%3d  |   %c   | {", i+1, ch);
        for(int j = 0; j <= n; j++){
            if(next[j]) printf("q%d ", j);
        }
        printf("}\n");

        free(curr);
        curr = next;
    }
    printf("-------------------------------------------------------------\n");
    printf("NFA Result: %s\n", (curr[n]) ? "Accepted" : "Rejected");

    free(curr);
    return 0;
}