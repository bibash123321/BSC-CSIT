#include <stdio.h>

#define NAND(a, b) (!(a && b))
#define NOR(a, b) (!(a || b))

void print_nand_truth_table() {
    int a, b;
    printf("NAND Gate Truth Table:\n");
    printf("A B | NAND\n");
    printf("-----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf("%d %d | %d\n", a, b, NAND(a, b));
        }
    }
}

void print_nor_truth_table() {
    int a, b;
    printf("NOR Gate Truth Table:\n");
    printf("A B | NOR\n");
    printf("----------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            printf("%d %d | %d\n", a, b, NOR(a, b));
        }
    }
}

int main() {
    print_nand_truth_table();
    print_nor_truth_table();
    return 0;
}

