#include<stdio.h>
int main(){
   int num,reverse=0,remainder;
 printf("enter the number for its reverse:");
 scanf("%d",&num);
 while(num!=0){
   remainder = num%10;
   reverse = reverse*10 + remainder;
    num= 10;
  }  
    printf("the reverse of the number is %d\n",reverse);
    printf("thank you");
    return 0;

}   
