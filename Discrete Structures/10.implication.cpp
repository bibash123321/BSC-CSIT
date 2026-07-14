#include <stdio.h>

int implicationOperation(int a, int b) {
    return !a || b;
}

int main() {
    int a, b;

    printf("A B | A ? B\n");
    printf("-----------\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf("%d %d | %d\n", a, b, implicationOperation(a, b));
        }
    }

    return 0;
}

