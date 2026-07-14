#include<iostream>
using namespace std;

class bank{
	
private:
	string depositor_name;
	string account_no;
	string account_type;
	double account_balance;
public:
	void set initial values(string name, string an, string at,double balance){
		this.depositor_name = name;
		this.account_no = an;
		this.account_type = at;
		this.account_balance = balance;
		
   void deposit amount(double amount){
   	this.account_balance += amount;
   }
   void check balance(){
   	cout << "available balance=" << account balance << endl;
   }
   void withdraw(double amount){
   	this.account_balance -= amount;
   }
   void display account details(){
   	cout << "account name=" << depositor_name << endl;
   	cout << "account no=" << account_no << endl;
   	cout << "current balance=" << account_balance << endl;
   }
	
};
int main(){
	bank b;
b.set initial values("ram","A10000000","saving",5000);
b.depositamount (4000);
b.checkbalance();
b.withdraw amount(3000);
b.checkbalance;
b.display account details();

}



