#include<stdio.h>
int main(){
	int n,i;
	printf("enter the size of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	int smallest = arr[0];
	int largest = arr[0];
	for(i=0;i<n;i++){
		if (arr[i]<smallest){
			smallest = arr[i];
		}
		if (arr[i]>largest){
			largest = arr[i];
			
		}
	}
	printf("smallest element:%d\n",smallest);
	printf("largest element:%d\n",largest);

return 0;
}

