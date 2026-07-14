#include<iostream>
using namespace std;

  class counter{
public:
	int count;
	counter(int c){
		count = c;
	}
	counter operator ++(){
		++ count;
	return counter(count);	
	}
	  };

int main(){
	counter c(5);
     ++c; 
  cout << c.count;
  return 0;
}


