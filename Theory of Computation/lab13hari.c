
#include <stdio.h>
#include <string.h>

// Function to check if the string is even palindrome using a TM simulation
int isEvenPalindrome(char tape[]) {
    int left = 0;
    int right = strlen(tape) - 1;

    int step = 1;
    printf("\n| Step | Left | Right | Read(L) | Read(R) | Action                   |\n");
    printf("--------------------------------------------------------------------\n");

    // TM Simulation
    while (left <= right) {
        char leftSym = tape[left];
        char rightSym = tape[right];

        // Print transition step
        printf("| %3d  |  %2d  |  %2d   |   %c     |   %c     | ", step++, left, right, leftSym, rightSym);

        if ((leftSym == 'a' && rightSym == 'a') || (leftSym == 'b' && rightSym == 'b')) {
            printf("Match -> Move inward\n");
            left++;
            right--;
        } else {
            printf("Mismatch -> Reject\n");
            return 0;  // Reject
        }
    }

    // After comparison
    printf("--------------------------------------------------------------------\n");
    if ((strlen(tape) % 2) == 0) {
        printf(" Accepted: Even-length palindrome detected.\n");
        return 1;
    } else {
        printf(" Rejected: Odd-length palindrome not accepted.\n");
        return 0;
    }
}

int main() {
    char tape[100];

    printf("Enter string over {a,b}: ");
    scanf("%s", tape);

    printf("\nSimulating Turing Machine for even palindrome over {a,b}...\n");

    // Show initial tape
    printf("\nInitial Tape: %s\n", tape);

    int result = isEvenPalindrome(tape);

    if (!result)
        printf("Result: String Rejected.\n");
    else
        printf("Result: String Accepted.\n");

    return 0;
}
