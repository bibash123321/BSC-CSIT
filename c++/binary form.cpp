#include<iostream>
using namespace std;

class student{
	
public:
	student(int age){
		this->age =age;
		
	}
	
	student operator+(student s){
		int totalage = age + s.age;
		return student(total age);
	}
};

int main(){
	student s1(29),s2(90),s3(33),s4(14);
	student total = s1 + s2 + s3 + s4;
	cout << "New age :"<< total.age << endl;
	
	return 0;
}
