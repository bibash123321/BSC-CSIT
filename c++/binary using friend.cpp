#include<iostream>
using namespace std;

   class student{
   	
private:
	int age = age;
   
public:    
	student(int a){
		age = a;
	}
	friend bool operator<(student s1, student s2);
};
 bool operator<(student s1,student s2){
 	if(s1.age<s2.age){
 		return true;
 		 }else{
 		 	return false;
		  }
 }
 int main(){
 	student ram(20),shyam(30);
if (ram < shyam){
	cout << "ram is younger"<< endl;
}else{
	cout<<"shyam is younger"<<endl;
}
}
