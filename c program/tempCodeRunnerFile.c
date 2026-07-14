#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    float salary;
};

int main() {
    struct Employee employees[5];

    printf("Enter details of employees:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Enter employee ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("Enter employee name: ");
        scanf(" %[^\n]s", employees[i].name);
        printf("Enter employee salary: ");
        scanf("%f", &employees[i].salary);
    }

    printf("\nDetails of employees:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Employee ID: %d\n", employees[i].emp_id);
        printf("Employee name: %s\n", employees[i].name);
        printf("Employee salary: %.2f\n", employees[i].salary);
    }

    return 0;
}