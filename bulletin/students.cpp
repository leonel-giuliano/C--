#include <iostream>
#include <fstream>
using namespace std;

#include "students.h"
#include "error.h"

void writeStudents(Student *students, fstream *fp) {
    uint8_t studentsAmount;

    *fp << "Students" << endl;
    // Prints the column name

    cout << "Amount of students: ";
    cin >> studentsAmount;

    students = new Student[studentsAmount];
    if(!students) errorHandler(ERROR_MEMORY);
    // Allocate the list of students

    for(auto i = 0; i < studentsAmount; i++) {
        students[i].scanName(i + 1);
        // Scan the name of every student

        *fp << students[i].getName() << endl;
    }
}