#include<iostream>
using namespace std;

class animal{
	public:
	virtual void speak() = 0;
};

class dog : public animal{
	void speak(){
		cout << "dog is speaking" << endl;
		
	}
};

class cat : public animal{
	void speak(){
		cout << "cat is speaking" << endl;
		
	}
};

int main(){
	animal* A[2];
	A[0]=new dog;
	A[1]= new cat;
	for (int i=0;i<2;i++){
	A[i]->speak();
	}
	
	
}
