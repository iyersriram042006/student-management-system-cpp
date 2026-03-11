# Student Management System (C++)

A console-based application built using **C++**, **Object-Oriented Programming**, and **file handling** to manage student records.  
The system supports common CRUD operations and stores data persistently using binary files.

---

## Features

- Add new student records
- Display all students
- Search student by roll number
- Update student details
- Delete student records
- Persistent storage using binary files
- Prevent duplicate roll numbers
- Count total students
- Identify top-performing student (highest CGPA)
- Sort students by CGPA

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- STL (vector, sort)

---

## Project Structure


StudentManagementSystem
│
├── main.cpp
├── Student.h
├── Student.cpp
├── Database.h
├── Database.cpp
├── students.dat
└── README.md


---

## How to Run

### Compile

```bash
g++ main.cpp Student.cpp Database.cpp -o sms
Run
./sms
Example Menu
================================
   STUDENT MANAGEMENT SYSTEM
================================

1 Add Student
2 Display Students
3 Search Student
4 Update Student
5 Delete Student
6 Count Students
7 Show Topper
8 Sort by CGPA
9 Exit
Learning Outcomes

This project demonstrates:

Implementation of Object-Oriented Programming concepts

File handling for persistent storage

CRUD operations (Create, Read, Update, Delete)

Data validation (duplicate roll prevention)

Use of STL algorithms for sorting

Author

Sriram Iyer
Computer Science Engineering Student