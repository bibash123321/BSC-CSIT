#include<iostream>
using namespace std;
#define pi 3.14
class shape{
    public:
    virtual float  area(int x , int y){
        return 0;
    }
};
class circle:public shape{
public:
float area(int r,int x){
    return pi*r*r;
}
};
class rectangle:public shape{
public:
float area(int l,int b){
    
    return l*b;
}
};
int main(){
    shape* shape1 = new circle; 
    shape* shape2 = new rectangle;
    
    cout<<"The area of circle is "<<shape1->area(5,0)<<" sq.units"<<endl;
     cout<<"The area of rectangle is "<<shape2->area(20,50)<<" sq.units"<<endl;
    delete shape1;
    delete shape2;
    
}
