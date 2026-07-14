#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int cc;

    Car(string b, int c) : brand(b), cc(c) {}
};

class Person {
public:
    string name;
    int age;
    Car car;

    Person(string n, int a, Car c) : name(n), age(a), car(c) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Car Brand: " << car.brand << endl;
        cout << "Car CC: " << car.cc << endl;
    }
};

int main() {
    Car car("hilux",2500);
    Person person("Hari",19,car);
    person.display();
    return 0;
}



