#include <stdio.h>


int linear_search(int arr[], int size, int target, int index) {
    
    if (index >= size) {
        return -1;
    }

   
    if (arr[index] == target) {
        return index;
    }

    
    return linear_search(arr, size, target, index + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = linear_search(arr, size, target, 0);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
}

return 0;
}
