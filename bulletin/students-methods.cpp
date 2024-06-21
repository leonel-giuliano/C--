#include <iostream>
#include <stdint.h>
using namespace std;

#include "students.h"

// SETTERS
void Student::setName(string str) {
    name = str;    
}

void Student::scanName(int num) {
    cout << "Name of the " << num << "° student: ";
    getline(cin, name);
    // Scan an entire line
}

// GETTERS
string Student::getName(void) {
    return name;
}