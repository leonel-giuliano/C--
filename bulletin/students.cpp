#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

#include "students.h"
#include "error.h"

void writeStudents(Student *students, fstream *fp) {
    int studentsAmount;

    *fp << "Students" << endl;
    // Prints the column name

    cout << "Amount of students: ";
    cin >> studentsAmount;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Make sure to empty the cin

    students = new Student[studentsAmount];
    if(!students) {
        fp->close();

        errorHandler(ERROR_MEMORY);
    }
    // Allocate the list of students

    for(auto i = 0; i < studentsAmount; i++) {
        students[i].scanName(i + 1);
        // Scan the name of every student

        *fp << students[i].getName() << endl;
        fp->flush();
    }
}

void readData(Student *students, fstream *fp) {
    auto studentsAmount = -1;
    // To ignore the column names

    char ch;
    while((ch = fp->get()) != EOF)
        if(ch == '\n') studentsAmount++;
        // Count the amount of lines to know the students

    students = new Student[studentsAmount];
    if(!students) {
        fp->close();

        errorHandler(ERROR_MEMORY);
    }

    string columnNames;
    fp->seekg(0, fstream::beg);
    getline(*fp, columnNames);
    // Skips the column names to start reading the data
}