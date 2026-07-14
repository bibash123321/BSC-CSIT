#include<iostream>
using namespace std;

class car{
public:
	string color;
	string model;
	
void startengine(){
	cout << "Engine started." <<end1;	
}
void accelerate(){
	cout << "car is accelerating." << end1;
}
void brake(){
	cout << "car is braking." << end1;
}
};
int main(){
	car mycar;
	
mycar.color = "red";
mycar.model = "sedan";

mycar.startengine();
mycar.acceleration();
mycar.brake();

return 0;
}
