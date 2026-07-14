#include<iostream>
using namespace std;
class account{
    public:
    int amount;
    int inter;
    virtual void deposite(int x){
    }
    virtual void withdraw(int x){
    }
    virtual void interest( int x){
    }
};
class savingaccount: public account{
    public:
    savingaccount(int a,int i){
        amount=a;
        inter=i;
    }
    void deposite(int depo){
        cout<<"The current balance is "<< amount<< endl;
        amount=amount+depo;
        cout<<"The new balance is "<< amount<< endl;
    }
    void withdraw(int with){
        if (with>amount){
            cout<<"Insufficient balance."<< endl;
        }
        else {
            amount=amount-with;
            cout<<"withdrawing"<<with<<endl;
            cout<<"The remaining balance is "<<amount<<endl;
        }
    }
    void calinterest(){
            int intamount=inter/100*amount;
            cout<<"The obtained interest is "<<intamount<<endl;
    }
};
class checkingaccount :public account{
    public:
    checkingaccount(int a,int i){
        amount=a;
        inter=i;
    }
    void deposite(int depo){
        cout<<"The current balance is "<<amount<<endl;
        amount=amount+depo;
        cout<<"The new balance is "<<amount<<endl;
    }
    void withdraw(int with){
        if(with>amount){
            cout<<"Insufficient balance."<<endl;
        }
        else{
            amount=amount-with;
            cout<<"withdrawing"<<with<<endl;
            cout<<"The remaining balance is "<<amount<<endl;
        }
    }
    void calinterest(){
        int intamount=inter/100*amount;
        cout<<"The obtained interest is "<<intamount<<endl;
    }
};
int main(){
    account*A1=new savingaccount(10000,4);
    account*A2=new checkingaccount(5000,4);
    A1->deposite(50000);
    A2->deposite(450000);
}





