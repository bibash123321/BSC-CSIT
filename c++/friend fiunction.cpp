#include<iostream>
using namespace std;

class employee{
	
private:
	string name;
	int age;
public:
	friend void displaydetails(employee e);
	employee (string n, int a){
		name = n;
		age = a;
		
	}
};
void displaydetails(employee e){
    cout << "name=" << e.name << endl;
    cout << "age=" << e.age << endl;
}
int main(){
	employee e("ram",32);
	displaydetails(e);
}

