#include <iostream>
using namespace std;

class student {
private:
    string student_name;
    int student_age;
    int student_roll;

public:
    void setname(string student_name) {
        this->student_name = student_name;
    }

    void setage(int student_age) {
        this->student_age = student_age;
    }

    void setroll(int student_roll) {
        this->student_roll = student_roll;
    }

    string getname() {
        return student_name;
    }

int getage() {
        return student_age;
    }

    int getroll() {
        return student_roll;
    }
};

int main() {
 string name;
int  age;
int rollno;
student S;
    cout << "Enter the name of student: ";
    cin >> name;
    cout << "Enter the age of student: ";
    cin >> age;
    cout << "Enter the roll no of student: ";
    cin >> rollno;

    S.setname(name);
    S.setage(age);
    S.setroll(rollno);

    cout << "Student name: " << S.getname() << endl;
    cout << "Stuent age: " << S.getage() << endl;
    cout << "Student roll no: " << S.getroll() << endl;

    return 0;

}

