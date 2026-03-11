#include <iostream>
#include "Database.h"

using namespace std;

int main()
{
    int choice;

    while(true)
    {
        cout<<"\n================================\n";
        cout<<"   STUDENT MANAGEMENT SYSTEM\n";
        cout<<"================================\n";

        cout<<"1 Add Student\n";
        cout<<"2 Display Students\n";
        cout<<"3 Search Student\n";
        cout<<"4 Update Student\n";
        cout<<"5 Delete Student\n";
        cout<<"6 Count Students\n";
        cout<<"7 Show Topper\n";
        cout<<"8 Sort by CGPA\n";
        cout<<"9 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: countStudents(); break;
            case 7: showTopper(); break;
            case 8: sortStudents(); break;
            case 9: return 0;
            default: cout<<"Invalid choice\n";
        }
    }
}