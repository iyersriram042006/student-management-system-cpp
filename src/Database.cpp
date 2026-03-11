#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

#include "Student.h"
#include "Database.h"

using namespace std;

bool rollExists(int roll)
{
    Student s;
    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.getRoll()==roll)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void addStudent()
{
    Student s;

    cout<<"\nEnter Student Details\n";
    s.input();

    if(rollExists(s.getRoll()))
    {
        cout<<"Roll Number already Exists\n";
        return;
    }

    ofstream file("students.dat", ios::binary | ios::app);
    file.write((char*)&s,sizeof(s));
    file.close();

    cout<<"Student Added Successfully\n";
}

void displayStudents()
{
    Student s;

    ifstream file("students.dat", ios::binary);

    if(!file)
    {
        cout<<"No Records Found\n";
        return;
    }

    while(file.read((char*)&s,sizeof(s)))
    {
        s.display();
    }

    file.close();
}

void searchStudent()
{
    int roll;
    Student s;

    cout<<"Enter Roll Number to Search: ";
    cin>>roll;

    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.getRoll()==roll)
        {
            cout<<"Student Found\n";
            s.display();
            file.close();
            return;
        }
    }

    cout<<"Student Not Found\n";
    file.close();
}

void updateStudent()
{
    int roll;
    Student s;

    cout<<"Enter Roll No to Update: ";
    cin>>roll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.getRoll()==roll)
        {
            cout<<"Enter New Details -->\n";
            s.input();

            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s,sizeof(s));

            cout<<"Record Updated\n";
            file.close();
            return;
        }
    }

    cout<<"Student Not Found\n";
    file.close();
}

void deleteStudent()
{
    int roll;
    Student s;

    cout<<"Enter Roll No to Delete: ";
    cin>>roll;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    bool found=false;

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.getRoll()!=roll)
        {
            temp.write((char*)&s,sizeof(s));
        }
        else
        {
            found=true;
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat","students.dat");

    if(found)
        cout<<"Student Deleted\n";
    else
        cout<<"Student Not Found\n";
}

void countStudents()
{
    Student s;
    int count=0;

    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        count++;
    }

    file.close();

    cout<<"Total Students: "<<count<<endl;
}

void showTopper()
{
    Student s;
    Student topper;
    float maxCGPA=-1;

    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.getCGPA()>maxCGPA)
        {
            maxCGPA=s.getCGPA();
            topper=s;
        }
    }

    file.close();

    if(maxCGPA==-1)
    {
        cout<<"No Students Available\n";
        return;
    }

    cout<<"\nTop Student:\n";
    topper.display();
}

void sortStudents()
{
    vector<Student> students;
    Student s;

    ifstream file("students.dat", ios::binary);

    while(file.read((char*)&s,sizeof(s)))
    {
        students.push_back(s);
    }

    file.close();

    sort(students.begin(), students.end(),
        [](Student a, Student b)
        {
            return a.getCGPA() > b.getCGPA();
        });

    for(auto &st : students)
        st.display();
}