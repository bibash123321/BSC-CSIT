#include<iostream>
#include<iostream>

int main(){
	float num1;
	float num2;
	
	printf("enter the first number between 0 and 1 :");
	scanf("%f",&num1);
	printf("enter the second number between 0 and 1 :");
	scanf("%f",&num1);
	
if(num1>num2){
	printf("first number is union\n");
	printf("second number is intersection\n");
}else if(num1==num2){
	printf("%f is union and intersection\n");
	
}
else{
	printf("second nmuber is union\n");
	printf("first number is intersection\n");
	
}
printf("the complement of first number is %0.3f\n",1-num1);
printf("the complement of second number is %0.3f\n",1-num2);

return 0;

}
