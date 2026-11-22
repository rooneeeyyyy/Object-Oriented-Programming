#include<iostream>
using namespace std;

class ExamMember{
protected:
    string name,id,department;

public:
    ExamMember(string n,string i,string d){
        name=n;
        id=i;
        department=d;
    }

    void displayMemberInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Department: "<<department<<endl;
    }
};

class UndergraduateStudent:public ExamMember{
    int semester;
    double CGPA;
    string major;

public:
    UndergraduateStudent(string n,string i,string d,int s,double c,string m):ExamMember(n,i,d){
        semester=s;
        CGPA=c;
        major=m;
    }

    void displayUndergradInfo(){
        displayMemberInfo();
        cout<<"Semester: "<<semester<<endl;
        cout<<"CGPA: "<<CGPA<<endl;
        cout<<"Major: "<<major<<endl;
    }
};

class GraduateStudent:public ExamMember{
    string researchTopic,supervisor,thesisStatus;

public:
    GraduateStudent(string n,string i,string d,string r,string s,string t):ExamMember(n,i,d){
        researchTopic=r;
        supervisor=s;
        thesisStatus=t;
    }

    void displayGraduateInfo(){
        displayMemberInfo();
        cout<<"Research Topic: "<<researchTopic<<endl;
        cout<<"Supervisor: "<<supervisor<<endl;
        cout<<"Thesis Status: "<<thesisStatus<<endl;
    }
};

class ExamOfficer:public ExamMember{
    string officeLocation;
    int yearsOfService,assignedExams;

public:
    ExamOfficer(string n,string i,string d,string o,int y,int a):ExamMember(n,i,d){
        officeLocation=o;
        yearsOfService=y;
        assignedExams=a;
    }

    void displayOfficerInfo(){
        displayMemberInfo();
        cout<<"Office Location: "<<officeLocation<<endl;
        cout<<"Years of Service: "<<yearsOfService<<endl;
        cout<<"Assigned Exams: "<<assignedExams<<endl;
    }
};

int main(){

    UndergraduateStudent u1("Ali","U101","Computer Science",2,3.65,"Computer Science");
    UndergraduateStudent u2("Ahmed","U102","Electrical Engineering",4,3.80,"Electrical Engineering");

    GraduateStudent g1("Sara","G101","Computer Science","Artificial Intelligence","Dr. Khan","In Progress");
    GraduateStudent g2("Ayesha","G102","Software Engineering","Machine Learning","Dr. Ahmed","Completed");

    ExamOfficer o1("Usman","O101","Examination Department","Block A",5,12);
    ExamOfficer o2("Fatima","O102","Examination Department","Block B",8,20);

    cout<<"===== UNDERGRADUATE STUDENTS ====="<<endl;
    u1.displayUndergradInfo();
    cout<<endl;
    u2.displayUndergradInfo();

    cout<<"\n===== GRADUATE STUDENTS ====="<<endl;
    g1.displayGraduateInfo();
    cout<<endl;
    g2.displayGraduateInfo();

    cout<<"\n===== EXAM OFFICERS ====="<<endl;
    o1.displayOfficerInfo();
    cout<<endl;
    o2.displayOfficerInfo();

    return 0;
}