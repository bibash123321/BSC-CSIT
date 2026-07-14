#include<stdio.h>
int main() { 
    int n, i, searchElement; 
    int found = 0; 
    printf("Enter the size of the array: "); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter %d elements:\n", n); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
    printf("Enter the element to search for: "); 
    scanf("%d", &searchElement); 
    for (i = 0; i < n; i++) { 
        if (arr[i] == searchElement) { 
            found = 1;  
            break; 
        } 
    } 
    if (found) { 
        printf("Element %d is found at index %d.\n", searchElement, i); 
    } else { 
        printf("Element %d is not found in the array.\n", searchElement); 
    } 
     
    return 0;   
} 
      

