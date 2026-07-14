#include<iostream>
using namespace std;

   class book{
public:
	string title;
	string author;
  friend istream& operator >> (istream& i, book& b);
   };
istream& operator >> (istream& i, book& b){
	cout <<"enter book title"<< endl;
	i >> b.title;
	cout << "enter book author"<< endl;
	i >> b.author;
 return i;
}
int main(){
	book b;
	cin >> b;
  
  cout << "book title=" << b.title << endl;
  cout << "book author=" <<b.author << endl;
  
  return 0;
}
