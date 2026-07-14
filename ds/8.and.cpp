#include <stdio.h>

int main() {
    int a, b;

    printf("Truth Table for AND Operation (&&)\n");
    printf("A B | A && B\n");
    printf("------------\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf("%d %d | %d\n", a, b, a && b);
        }
    }

   return 0;
}
