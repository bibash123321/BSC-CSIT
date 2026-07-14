
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i;

    // -------------------- Print DFA Transition Table --------------------
    printf("\n================ DFA Transition Table ================\n");
    printf("| Current State | Input 0,2,4,6,8 | Input 1,3,5,7,9 |\n");
    printf("|---------------|-----------------|-----------------|\n");
    printf("| q0 (even)     | q0              | q1              |\n");
    printf("| q1 (odd)      | q0              | q1              |\n");
    printf("---------------------------------------------------------\n");

    // -------------------- Print NFA Transition Table --------------------
    printf("\n================ NFA Transition Table ================\n");
    printf("| Current State | Input 0,2,4,6,8 | Input 1,3,5,7,9 |\n");
    printf("|---------------|-----------------|-----------------|\n");
    printf("| q0 (even)     | q0              | q1              |\n");
    printf("| q1 (odd)      | q0              | q1              |\n");
    printf("---------------------------------------------------------\n");

    // -------------------- Take Input --------------------
    printf("\nEnter a decimal number: ");
    scanf("%s", str);
    len = strlen(str);

    // -------------------- DFA --------------------
    int dfa_state = 0; // q0 = even, q1 = odd
    printf("\n================ DFA Working Mechanism ================\n");
    printf("| Step | Input | From | To  |\n");
    printf("--------------------------------\n");

    for(i = 0; i < len; i++){
        char ch = str[i];
        int prev = dfa_state;
        if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='8') dfa_state = 0;
        else if(ch=='1'||ch=='3'||ch=='5'||ch=='7'||ch=='9') dfa_state = 1;
        else {
            printf("Invalid input! Only digits 0-9 allowed.\n");
            return 1;
        }
        printf("| %3d  |   %c   | q%d   | q%d |\n", i+1, ch, prev, dfa_state);
    }

    printf("--------------------------------\n");
    printf("DFA Result: %s\n", (dfa_state==0)?"Accepted":"Rejected");

    // -------------------- NFA --------------------
    int nfa_curr[2] = {1,0}; // q0 active
    int nfa_next[2];

    printf("\n================ NFA Working Mechanism ================\n");
    printf("| Step | Input | Active States After Input |\n");
    printf("-----------------------------------------------\n");

    for(i = 0; i < len; i++){
        char ch = str[i];
        nfa_next[0] = nfa_next[1] = 0;

        for(int j=0;j<2;j++){
            if(nfa_curr[j]){
                if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='8') nfa_next[0]=1;
                else if(ch=='1'||ch=='3'||ch=='5'||ch=='7'||ch=='9') nfa_next[1]=1;
            }
        }

        printf("| %3d  |   %c   | {", i+1, ch);
        for(int j=0;j<2;j++) if(nfa_next[j]) printf("q%d ", j);
        printf("} |\n");

        for(int j=0;j<2;j++) nfa_curr[j] = nfa_next[j];
    }

    printf("-----------------------------------------------\n");
    printf("NFA Result: %s\n", (nfa_curr[0])?"Accepted":"Rejected");

    return 0;
}
