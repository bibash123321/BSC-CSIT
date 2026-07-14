#include<iostream>
using namespace std;

class parent{
  public:
  	void show(){
  		cout << "parent showing\n";
  		
	  }
};

class base1 : public parent {
	
};

class base2 : public parent{
	
};
class Derived : public base1, public base2 {
	
};

int main(){
	Derived d;
	d.show(); 
	return 0;
}
