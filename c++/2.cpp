#include<iostream>
using namespace std;

class marks{
protected:
	float subject1, subject2, subject3;
		
public:
	void inputmarks(){
		cout << "enter marks for subject 1";
		cin >> subject1;
		
			cout << "enter marks for subject 2";
		cin >> subject2;
		
			cout << "enter marks for subject 3";
		cin >> subject3;
		
	}
};
class totalmarks : public marks{
protected:
	float total;
	
public:
	void calculatetotal(){
		total = subject1 + subject2 + subject3;
	}
	float gettotal(){
		return total;
	}
};

class percentage : public totalmarks{
public:
	void displaypercentage(){
		float percentage = (gettotal()/300)*100;
		
		cout << "total marks:" << gettotal() << endl;
		cout << "percentage:" << percentage << "%" << endl;
	}
};

int main(){
	percentage student;
	student.inputmarks();
	student.calculatetotal();
	student.displaypercentage();
	
	return 0;
}




















