#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a string (letters a/b only): ");
    scanf("%s", str);
    len = strlen(str);

    /* -------------------- DFA -------------------- */
    int state = 0; // q0=start, q1=first 'a', q2=accepted, q3=dead
    int q_dead = 3;

    printf("\n================ DFA Simulation ================\n");

    printf("DFA Transition Table:\n");
    printf("--------------------------------\n");
    printf("| Current | Input | Next State |\n");
    printf("--------------------------------\n");
    printf("|   q0    |   a   |    q1      |\n");
    printf("|   q0    |   b   |   q3       |\n");
    printf("|   q1    |   a   |    q2      |\n");
    printf("|   q1    |   b   |   q3       |\n");
    printf("|   q2    |   a   |    q2      |\n");
    printf("|   q2    |   b   |    q2      |\n");
    printf("|   q3    |   a   |    q3      |\n");
    printf("|   q3    |   b   |    q3      |\n");
    printf("--------------------------------\n\n");

    printf("DFA Working Mechanism:\n");
    printf("---------------------------\n");
    printf("| Input | From | To  |\n");
    printf("---------------------------\n");

    for(i=0; i<len; i++) {
        char ch = str[i];
        int prev = state;
        switch(state) {
            case 0: state = (ch=='a')?1:q_dead; break;
            case 1: state = (ch=='a')?2:q_dead; break;
            case 2: state = 2; break;
            case 3: state = q_dead; break;
        }
        printf("|   %c    |  q%d  | q%d |\n", ch, prev, state);
    }
    printf("---------------------------\n");
    printf("DFA Result: %s\n", (state==2)?"Accepted":"Rejected");


    /* -------------------- NFA -------------------- */
    int s0=1, s1=0, s2=0; // q0=start, q1=first 'a', q2=accepted

    printf("\n================ NFA Simulation ================\n");

    printf("NFA Transition Table:\n");
    printf("----------------------------------\n");
    printf("| Current | Input | Next State(s) |\n");
    printf("----------------------------------\n");
    printf("|   q0    |   a   |   q0, q1      |\n");
    printf("|   q0    |   b   |     q0        |\n");
    printf("|   q1    |   a   |     q2        |\n");
    printf("|   q1    |   b   |      -        |\n");
    printf("|   q2    |   a,b |     q2        |\n");
    printf("----------------------------------\n\n");

    printf("NFA Working Mechanism (Active States after each input):\n");
    printf("--------------------------------------------------\n");
    printf("Input\tActive States\n");
    printf("--------------------------------------------------\n");

    for(i=0;i<len;i++) {
        char ch = str[i];
        int ns0=0, ns1=0, ns2=0;

        if(ch=='a') {
            if(s0) { ns0=1; ns1=1; }
            if(s1) ns2=1;
            if(s2) ns2=1;
        } else if(ch=='b') {
            if(s0) ns0=1;
            if(s2) ns2=1;
        }

        printf("%c\t{", ch);
        if(s0) printf("q0 ");
        if(s1) printf("q1 ");
        if(s2) printf("q2 ");
        printf("}\n");

        s0=ns0; s1=ns1; s2=ns2;
    }
    printf("--------------------------------------------------\n");
    printf("NFA Result: %s\n", (s2)?"Accepted":"Rejected");

    return 0;
}