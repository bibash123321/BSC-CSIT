#include<stdio.h>
int main(){
	int n,i,searchElement;
	int found = 0;
	printf("enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		}
printf("enter elements to search for:");
scanf("%d", &searchElement);
for(i=0;i<n;i++){
	if (arr[i]==searchElement);
	found = 1;
	break;
   } 
}
if (found){

	printf("enter %d elements is found at index %d.\n",searchElenent,i);
}else{
	printf("enter %d is not found in the array.\n",search element);
	}

return 0;
}

