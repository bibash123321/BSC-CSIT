#include<iostream>
using namespace std;

class bank{
	
private:
	string account_name;
	string account_number;
	double account_balance;
	
public:
	bank(string ac, string an, double ab)
	{
		this->account_name = ac;
		this->account_number = an;
		this->account_balance = ab;
		
	}
	void depositAmount(int amount){
		cout << "enter amount to deposit\n";
		cin >> amount;
		cout << "depositing amount Rs" << amount << endl;
		account_balance += amount;
		checkbalance();
		
	}
	void checkbalance()
	{
		cout << "current balance:" << account_balance << endl;
	}
	void withdrawAmount(int amount){
	    cout << "enter amount to withdraw\n";
	    cin >> amount;
	    
	    if(amount > account_balance){
	    	cout << "insufficient fund" << endl;
	    	}else{
	    		account_balance -= amount;
			}
	}
};

int main(){
	bank b("Ram","A109099",500);
	b.checkbalance();
	b.depositAmount(4000);
	b.checkbalance();
	b.withdrawAmount(3000);
	b.checkbalance() ;
	
	return 0;
}


















