#include<iostream>
using namespace std;
	
	class  centimeter{
public:
	int length;
	centimeter(int l){
		length = l;
	}
	};
   
   class meter{
public:
	int length;
	meter(int l){
		length = l;
	}
	operator centimeter(){
		return centimeter(length);
	}
};
 int main(){
 	meter m(20);
 	centimeter c = m;
 	cout <<"length="<<c.length<<endl;
 	return 0;
 }
