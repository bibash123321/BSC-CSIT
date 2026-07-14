
#include <stdio.h>
#include <string.h>

// Function to simulate TM for odd palindrome
int isOddPalindrome(char tape[]) {
    int left = 0;
    int right = strlen(tape) - 1;

    int step = 1;
    printf("\n| Step | Left | Right | Read(L) | Read(R) | Action                   |\n");
    printf("--------------------------------------------------------------------\n");

    // Simulate reading from both ends
    while (left < right) {
        char leftSym = tape[left];
        char rightSym = tape[right];

        printf("| %3d  |  %2d  |  %2d   |   %c     |   %c     | ", step++, left, right, leftSym, rightSym);

        if ((leftSym == '0' && rightSym == '0') || (leftSym == '1' && rightSym == '1')) {
            printf("Match -> Move inward\n");
            left++;
            right--;
        } else {
            printf("Mismatch -> Reject\n");
            return 0;  // Reject on mismatch
        }
    }

    // At this point, if we reach the middle correctly
    printf("--------------------------------------------------------------------\n");
    if ((strlen(tape) % 2) == 1) {
        printf(" Accepted: Odd-length palindrome detected.\n");
        return 1;
    } else {
        printf(" Rejected: Even-length palindrome not accepted.\n");
        return 0;
    }
}

int main() {
    char tape[100];

    printf("Enter string over {0,1}: ");
    scanf("%s", tape);

    printf("\nSimulating Turing Machine for odd palindrome over {0,1}...\n");
    printf("\nInitial Tape: %s\n", tape);

    int result = isOddPalindrome(tape);

    if (!result)
        printf("Result:  String Rejected.\n");
    else
        printf("Result:  String Accepted.\n");

    return 0;
}
