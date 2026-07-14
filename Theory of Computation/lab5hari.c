
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i;

    printf("Enter a binary string: ");
    scanf("%s", str);
    len = strlen(str);

    // DFA states: q0, q1, q2, q3
    // q0 = even0, even1
    // q1 = even0, odd1 (ACCEPTING)
    // q2 = odd0, even1
    // q3 = odd0, odd1

    // -------------------- DFA --------------------
    int dfa_state = 0;

    printf("\n================ DFA Transition Table ================\n");
    printf("| Current | Input 0 | Input 1 |\n");
    printf("-----------------------------------\n");
    printf("| q0      | q2      | q1      |\n");
    printf("| q1      | q3      | q0      |\n");
    printf("| q2      | q0      | q3      |\n");
    printf("| q3      | q1      | q2      |\n");
    printf("-----------------------------------\n");

    printf("\n================ DFA Working Mechanism ================\n");
    printf("| Step | Input | From | To  |\n");
    printf("--------------------------------\n");

    for(i = 0; i < len; i++){
        char ch = str[i];
        int prev = dfa_state;
        switch(dfa_state){
            case 0: dfa_state = (ch=='0')?2:1; break;
            case 1: dfa_state = (ch=='0')?3:0; break;
            case 2: dfa_state = (ch=='0')?0:3; break;
            case 3: dfa_state = (ch=='0')?1:2; break;
        }
        printf("| %3d  |   %c   | q%d   | q%d |\n", i+1, ch, prev, dfa_state);
    }

    printf("--------------------------------\n");
    printf("DFA Result: %s\n", (dfa_state==1)?"Accepted":"Rejected");

    // -------------------- NFA --------------------
    int nfa_curr[4] = {1,0,0,0}; // start at q0
    int nfa_next[4];

    printf("\n================ NFA Transition Table ================\n");
    printf("| Current | Input 0 | Input 1 |\n");
    printf("-----------------------------------\n");
    printf("| q0      | q2      | q1      |\n");
    printf("| q1      | q3      | q0      |\n");
    printf("| q2      | q0      | q3      |\n");
    printf("| q3      | q1      | q2      |\n");
    printf("-----------------------------------\n");

    printf("\n================ NFA Working Mechanism ================\n");
    printf("| Step | Input | Active States After Input |\n");
    printf("-----------------------------------------------\n");

    for(i=0;i<len;i++){
        char ch = str[i];
        for(int j=0;j<4;j++) nfa_next[j]=0;

        for(int j=0;j<4;j++){
            if(nfa_curr[j]){
                if(ch=='0'){
                    if(j==0) nfa_next[2]=1;
                    else if(j==1) nfa_next[3]=1;
                    else if(j==2) nfa_next[0]=1;
                    else if(j==3) nfa_next[1]=1;
                } else if(ch=='1'){
                    if(j==0) nfa_next[1]=1;
                    else if(j==1) nfa_next[0]=1;
                    else if(j==2) nfa_next[3]=1;
                    else if(j==3) nfa_next[2]=1;
                }
            }
        }

        printf("| %3d  |   %c   | {", i+1, ch);
        for(int j=0;j<4;j++) if(nfa_next[j]) printf("q%d ", j);
        printf("} |\n");

        for(int j=0;j<4;j++) nfa_curr[j]=nfa_next[j];
    }

    printf("-----------------------------------------------\n");
    printf("NFA Result: %s\n", (nfa_curr[1])?"Accepted":"Rejected");

    return 0;
}
