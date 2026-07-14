#include <stdio.h>


int binary_search(int arr[], int left, int right, int target) {
    
    if (left > right) {
        return -1;
    }

  
    int mid = left + (right - left) / 2;

    
    if (arr[mid] == target) {
        return mid;
    }
 
    else if (arr[mid] > target) {
        return binary_search(arr, left, mid - 1, target);
    }
  
    else {
        return binary_search(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};  
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binary_search(arr, 0, size - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
}
    return 0;
}




