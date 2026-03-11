#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
private:
    int roll;
    char name[50];
    int age;
    char branch[50];
    char email[50];
    float cgpa;

public:
    void input();
    void display();
    int getRoll();
    float getCGPA();
};

#endif