#include<iostream>
using namespace std;

class college{
	
private :
	string college_name;
	string college_address;
	
public:
	static string affiliation;
	friend void displaydetails(college c);
	

};

string college :: affiliation = "TU";
void displaydetails(college c){
	c.college_name = "NSC";
	c.college_address = "shantinagar";
	
	cout << "college name=" << c.college_name << endl;
	cout << "college address=" << c.college_address << endl;
	cout << "college affiliation=" << c.affiliation << endl;
	
	
}
//  };
int main(){
	college c;
	displaydetails(c);
	
}
