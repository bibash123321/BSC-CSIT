#include<iostream>
using namespace std;

class totalprofit{
	public:
		int profit;
		
	    totalprofit(int p){
	    profit=p;
		}
		totalprofit operator +(totalprofit p){
			int total=profit+p.profit;
			return totalprofit(total);
		}
		
};

int main(){
	totalprofit p1(1000),p2(1299);
	totalprofit p3=p1+p2;
	int total=p3.profit;
	cout<<"the total profit is:"<<total<<endl;
return 0;
}

