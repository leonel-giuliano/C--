#include <iostream>
#include <fstream>
using namespace std;

#include "main.h"
#include "students.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if(argc > ARGC_FILE) errorHandler(ERROR_ARG);

    string filePath;
    Student *students = NULL;
    // Dynamic list with all the students

    if(argc == ARGC_FILE) filePath = argv[ARGV_FILE];
    else filePath = PRED_PATH;
    // Select path depending on the arguments


    fstream fpBulletin(filePath);
    // Opens in "r+"
    if(!fpBulletin) {
        fpBulletin.open(filePath, ios::out);
        if(!fpBulletin) errorHandler(ERROR_FILE);
        // Opens in "w+"

        writeStudents(students, &fpBulletin);
        // Writes the students in case the
        // file wasn't created
    } else readData(students, &fpBulletin);

    fpBulletin.close();
    delete[] students;

    return 0;
}