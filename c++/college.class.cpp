#include<iostream>
using namespace std;

class college{

private:
    string college_name;
    string college_address;
    int established_year;
public:
	college (string ca, string cn, int ey){
		college_name = cn;
		college_address = ca;
		established_year = ey;
	}
	void displaydetails(){
		cout << "college name=" << college_name << endl;
		cout << "college address=" << college_address << endl;
		cout << "established=" << established_year << endl;
	}
};
int main(){
	college c("NSC","shantinagar",1995);
	c.displaydetails();
	return 0;
}

