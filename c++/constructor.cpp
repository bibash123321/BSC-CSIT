#include<iostream>
using namespace std;

class student{

private:
	string name;
public:
	student(){
	    cout << "default constructor called" << endl;
	}
	student(string name){
		cout << "parameterized constructor called" << endl;
	}
	
	~student(){
		cout << "destructor called" << endl;
	}
	
};

int main(){
	student s1;
	student s2("ram");
	
	
	return 0;
}

