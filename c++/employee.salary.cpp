#include<iostream>
using namespace std;
class employee{
private:
int emp_id;
string emp_name;
int emp_salary;
public:
employee(int i,string n,int s){
emp_id=i;
emp_name=n;
emp_salary=s;
}
void displaydetails(){
    cout<<"The information is given below: "<<endl;
    cout<<"Employee ID: "<<emp_id<<endl;
     cout<<"Employee Name: "<<emp_name<<endl;
      cout<<"Employee Salary: "<<emp_salary<<endl;
}
};
int main(){
    employee E(19,"harry",32000);
    E.displaydetails();
    return 0;
}
