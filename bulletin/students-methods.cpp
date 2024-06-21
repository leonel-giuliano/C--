#include <iostream>
#include <stdint.h>
using namespace std;

#include "students.h"

void Student::scanName(uint8_t num) {
    cout << "Name of the " << num << "° student: ";
    cin >> name;    
}

string Student::getName(void) {
    return name;   
}