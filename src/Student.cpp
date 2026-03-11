#include "Student.h"
#include <iostream>
using namespace std;

void Student::input()
{
    cout<<"Enter Roll Number: ";
    cin>>roll;

    cin.ignore();

    cout<<"Enter Name: ";
    cin.getline(name,50);

    cout<<"Enter Age: ";
    cin>>age;

    cin.ignore();

    cout<<"Enter Branch: ";
    cin.getline(branch,50);

    cout<<"Enter Email: ";
    cin.getline(email,50);

    cout<<"Enter CGPA: ";
    cin>>cgpa;
}

void Student::display()
{
    cout<<"\n--------------------------\n";
    cout<<"Roll: "<<roll<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Branch: "<<branch<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"CGPA: "<<cgpa<<endl;
}

int Student::getRoll()
{
    return roll;
}

float Student::getCGPA()
{
    return cgpa;
}