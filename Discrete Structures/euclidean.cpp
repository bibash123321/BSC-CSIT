#include <iostream>
#include<stdio.h>

int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    
    printf("The GCD of %d and %d using iterative approach is %d\n", x, y, gcd_iterative(x, y));
    
return 0;
}
