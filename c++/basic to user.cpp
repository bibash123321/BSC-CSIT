#include<iostream>
using namespace std;

class time{
private:
	int year;
	int month;
	
public:
	time(int y, int m){
		year = y;
		month = m;
	}
	time(float t){
		year = int(t);
		month = 12*(t - year);
		
	}
	
	void displaydetails(){
		cout << "the information is given below:" << endl;
		cout << "year:" << year << endl;
	}
};

int main(){
	float d;
	cout <<"enter date:";
	cin >> d;
	time t=d;
	t.displaydetails();
	return 0;
}
