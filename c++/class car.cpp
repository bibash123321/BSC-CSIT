#include<iostream>
using namespace std;
class car{
public:
int speed;
string CC;
string color;
void start(){
    cout<<"Car is starting."<<endl;
}
void accelerate(){
    cout<<"Car is accelerating."<<endl;
}
void stop(){
    cout<<"Car has been stoppped."<<endl;

}
};
int main(){
    car C;
    C.start();
    C.accelerate();
    C.stop();
  return 0;
}
