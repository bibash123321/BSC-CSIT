#include<iostream>
using namespace std;

   class counter{
public:
	int count;
	counter(int c){
		count = c;
}
	friend counter operator ++(counter c){
	
	c.count ++;
	return counter(c.count);
}
   };
   int main(){
   	counter c(4);
   	
   	counter final = ++c;
   	cout << final.count;
   }
   
