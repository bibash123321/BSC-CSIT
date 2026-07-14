#include<iostream>
using namespace std;

   class book{
public:
	string title;
	string author;
 book(string title, string author){
 	this->title = title;
 	this->author = author;
 }
 friend ostream& operator << (ostream& o,book& b);
   };
   ostream& operator << (ostream&o, book&b){
   	o << "title="<<b.title << endl;
   	o << "author="<<b.author << endl;
return o ;
   }
   int main(){
   	book b("c++","bajarne");
   	
   	cout << b << "hello" << endl;
return 0;
   }
