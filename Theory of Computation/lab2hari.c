#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;

    printf("Enter a binary string: ");
    scanf("%s", str);
    len = strlen(str);

    /* -------------------- DFA SECTION -------------------- */
    int state = 0;

    printf("\n================ DFA Simulation ================\n");
    printf("Transition Table:\n");
    printf("--------------------------------\n");
    printf("| Current | Input | Next State |\n");
    printf("--------------------------------\n");
    printf("|   q0    |   0   |    q0      |\n");
    printf("|   q0    |   1   |    q1      |\n");
    printf("|   q1    |   0   |    q2      |\n");
    printf("|   q1    |   1   |    q1      |\n");
    printf("|   q2    |   0   |    q0      |\n");
    printf("|   q2    |   1   |    q3      |\n");
    printf("|   q3    |   0   |    q2      |\n");
    printf("|   q3    |   1   |    q1      |\n");
    printf("--------------------------------\n\n");

    printf("Working Mechanism:\n");
    printf("---------------------------\n");
    printf("| Input | From | To  |\n");
    printf("---------------------------\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];
        int prev = state;
        switch (state) {
            case 0:
                if (ch == '0') state = 0;
                else if (ch == '1') state = 1;
                break;
            case 1:
                if (ch == '0') state = 2;
                else if (ch == '1') state = 1;
                break;
            case 2:
                if (ch == '0') state = 0;
                else if (ch == '1') state = 3;
                break;
            case 3:
                if (ch == '0') state = 2;
                else if (ch == '1') state = 1;
                break;
        }
        printf("|   %c    |  q%d  | q%d |\n", ch, prev, state);
    }
    printf("---------------------------\n");

    if (state == 3)
        printf("DFA Result: Accepted (ends with 101)\n");
    else
        printf("DFA Result: Rejected\n");


    /* -------------------- NFA SECTION -------------------- */
    int s0 = 1, s1 = 0, s2 = 0, s3 = 0;

    printf("\n================ NFA Simulation ================\n");
    printf("Transition Table:\n");
    printf("----------------------------------\n");
    printf("| Current | Input | Next State(s) |\n");
    printf("----------------------------------\n");
    printf("|   q0    |   0   |     q0        |\n");
    printf("|   q0    |   1   |   q0, q1      |\n");
    printf("|   q1    |   0   |     q2        |\n");
    printf("|   q2    |   1   |     q3        |\n");
    printf("----------------------------------\n\n");

    printf("Working Mechanism (Active States after each input):\n");
    printf("--------------------------------------------------\n");
    printf("Input\tActive States\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < len; i++) {
        char ch = str[i];
        int ns0 = 0, ns1 = 0, ns2 = 0, ns3 = 0;

        if (ch == '0') {
            if (s0) ns0 = 1;
            if (s1) ns2 = 1;
        }
        else if (ch == '1') {
            if (s0) { ns0 = 1; ns1 = 1; }
            if (s2) ns3 = 1;
        }

        printf("%c\t{", ch);
        if (s0) printf("q0 ");
        if (s1) printf("q1 ");
        if (s2) printf("q2 ");
        if (s3) printf("q3 ");
        printf("}\n");

        s0 = ns0; s1 = ns1; s2 = ns2; s3 = ns3;
    }

    printf("--------------------------------------------------\n");
    if (s3)
        printf("NFA Result: Accepted (ends with 101)\n");
    else
        printf("NFA Result: Rejected\n");

    printf("==================================================\n");

    return 0;
}