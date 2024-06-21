#ifndef __STUDENTS_H__
#define __STUDENTS_H__

#include <iostream>
#include <stdint.h>
using namespace std;

typedef struct _mark {
    uint8_t i;

    string name;
    uint8_t value;
    uint8_t percentage;

    struct _mark *next;
    // Make a dynamic list
}mark_t;

class Student {
    string name;
    mark_t *marks;
};

#endif