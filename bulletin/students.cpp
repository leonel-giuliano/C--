#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

#include "students.h"
#include "main.h"
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

int countStudents(Student *students, fstream *fp) {
    auto studentsAmount = -1;
    // To ignore the column names

    char ch;
    while((ch = fp->get()) != EOF)
        if(ch == '\n') studentsAmount++;
        // Count the amount of lines to know the students

    return studentsAmount;
}

void readData(Student *students, fstream *fp) {
    auto studentsAmount = countStudents(students, fp);

    students = new Student[studentsAmount];
    if(!students) {
        fp->close();

        errorHandler(ERROR_MEMORY);
    }
    // Allocate the array of students

    string columnNames;
    fp->clear();
    // Needed to clear the EOF state

    fp->seekg(0, fstream::beg);
    getline(*fp, columnNames);
    // Skips the column names to start reading the data

    for(auto i = 0; i < studentsAmount; i++) {
        string name;
        char ch;
        while((ch = fp->get()) != SEPARATOR && ch != '\n' && ch != EOF)
            name += ch;
        // Reads char by char to have 2 delimiters

        students[i].setName(name);
        // Save the name

        cout << "Student: " << students[i].getName() << endl;
    }
}