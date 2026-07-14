#include<iostream>
using namespace std;

  class meter{
public:
	int length;
	meter(int l){
		length = l;
	}
  };
  
  class centimeter{
public:
	int length;
	centimeter(meter m){
		length = m.length;
	}
  };
  
int main(){
	meter m(20);
	centimeter c = m;
	cout<<"length="<< c.length<<endl;
}
