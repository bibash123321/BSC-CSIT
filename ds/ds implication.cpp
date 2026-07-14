#include <stdio.h>

int main() {
    double num1, num2;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Addition: %.2lf\n", num1 + num2);
    printf("Subtraction: %.2lf\n", num1 - num2);
    printf("Multiplication: %.2lf\n", num1 * num2);

    if (num2 != 0) {
        printf("Division: %.2lf\n", num1 / num2);
    } else {
        printf("Error: Division by zero is not allowed.\n");
}

return 0;
}
