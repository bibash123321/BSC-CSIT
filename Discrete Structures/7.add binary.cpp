#include <stdio.h>

int main() {
    long a, b;
    int i = 0, c = 0;
    int sum[20];

    printf("Enter the first binary number: ");
    scanf("%ld", &a);

    printf("Enter the second binary number: ");
    scanf("%ld", &b);

    while (a != 0 || b != 0) {
        sum[i++] = (a % 10 + b % 10 + c) % 2;
        c = (a % 10 + b % 10 + c) / 2;
        a = a / 10;
        b = b / 10;
    }

    if (c != 0) {
        sum[i++] = c;
    }
    --i;
    printf("Sum of two binary numbers: ");
    while (i >= 0) {
        printf("%d", sum[i--]);
    }
    printf("\n");
    return 0;
}
