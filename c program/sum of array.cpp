#include<stdio.h>
 int main() { 
int size; 
printf("Enter the size of the array: "); 
scanf("%d", &size); 
int array[size]; 
printf("Enter the elements of the array:\n"); 
for (int i = 0; i < size; i++) { 
printf("Element %d: ", i + 1); 
scanf("%d", &array[i]); 
} 
int sum = 0; 
for (int i = 0; i < size; i++) { 
sum += array[i]; 
} 
printf("Sum of array elements: %d\n", sum); 
return 0; 
}
