#include<iostream>
using namespace std;

class employee{
public:
	string name;
	int age;

void setname(stringname){
	this.name = name;
}
void setage(int age){
	this.age = age;
}
string getname(){
	return this.name;
}
int getage(){
	return this.age;
}
void displaydetails(string name, int age){
	cout << "name =" << name << "\n age=" << age;
}

};
int main(){
	employee e;
	e.setname(sandeep);
	e.setageage(23);
	
	string n = e.getname();
	int a = e.getage();
	
	e.displaydetails(n,a);
	return 0;
}


