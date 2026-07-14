#include<iostream>
using namespace std;

class vehicle{
public:
	virtual void start()=0;
};

class car : public vehicle{
	void start(){
		cout << "car is starting" << endl;
	}
};

class motorcycle : public vehicle{
	void start(){
		cout << "motorcycle is starting" << endl;
	}
};
int main(){
	vehicle*v1=new(car);
	vehicle*v2=new(motorcycle);
	v1->start();
	v2->start();
	
	
}
