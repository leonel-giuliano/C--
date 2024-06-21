#include <iostream>
#include <stdint.h>
using namespace std;

#include "students.h"

void Student::scanName(int num) {
    cout << "Name of the " << num << "° student: ";
    getline(cin, name);
    // Scan an entire line
}

string Student::getName(void) {
    return name;
}