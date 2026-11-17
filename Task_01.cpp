#include <iostream>
#include <string>
using namespace std;

class Student {

    private:
        string name;
        int rollNumber;
        float marks;

    public:
        int semester;

        void getData() {
            cout << "Enter Student Name: ";
            getline(cin >> ws, name);

            cout << "Enter Roll Number: ";
            cin >> rollNumber;

            cout << "Enter Semester: ";
            cin >> semester;

            cout << "Enter Obtained Marks: ";
            cin >> marks;
        }

        void displayData();

        void calculateGrade();
};

void Student::displayData() {
    cout << "\n----- Student Record -----" << endl;
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Semester: " << semester << endl;
    cout << "Marks: " << marks << endl;
}

void Student::calculateGrade() {
    if (marks >= 90) {
        cout << "Grade: A+" << endl;
    }
    else if (marks >= 80) {
        cout << "Grade: A" << endl;
    }
    else if (marks >= 70) {
        cout << "Grade: B" << endl;
    }
    else if (marks >= 60) {
        cout << "Grade: C" << endl;
    }
    else if (marks >= 50) {
        cout << "Grade: D" << endl;
    }
    else {
        cout << "Grade: F" << endl;
    }
}

int main() {

    Student s1, s2;

    cout << "Enter Details of First Student" << endl;
    s1.getData();

    cout << "\nEnter Details of Second Student" << endl;
    s2.getData();

    cout << "\n\nFirst Student Details";
    s1.displayData();
    s1.calculateGrade();

    cout << "\n\nSecond Student Details";
    s2.displayData();
    s2.calculateGrade();

    return 0;
}