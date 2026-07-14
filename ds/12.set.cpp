#include <stdio.h>

int main() {
    int i, j, k, n1, n2, set1[10], set2[10], set3[20], flag;

    printf("Enter size of set1: ");
    scanf("%d", &n1);
    printf("Enter elements of set 1: ");
    for(i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    printf("Enter size of set2: ");
    scanf("%d", &n2);
    printf("Enter elements of set 2: ");
    for(i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // Calculate union
    k = 0;
    printf("\nThe union is:\n");
    for(i = 0; i < n1; i++) {
        set3[k++] = set1[i];
    }
    for(i = 0; i < n2; i++) {
        flag = 1;
        for(j = 0; j < n1; j++) {
            if(set2[i] == set1[j]) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            set3[k++] = set2[i];
        }
    }
    for(i = 0; i < k; i++) {
        printf("%d\t", set3[i]);
    }
    printf("\n");

    // Calculate intersection
    k = 0;
    printf("\nThe intersection is:\n");
    for(i = 0; i < n2; i++) {
        flag = 1;
        for(j = 0; j < n1; j++) {
            if(set2[i] == set1[j]) {
                flag = 0;
                break;
            }
        }
        if(flag == 0) {
            set3[k++] = set2[i];
        }
    }
    for(i = 0; i < k; i++) {
        printf("%d\t", set3[i]);
    }
    printf("\n");

    return 0;
}

