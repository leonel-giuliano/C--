#ifndef __STUDENTS_H__
#define __STUDENTS_H__

#include <iostream>
using namespace std;

typedef struct _mark {
    int i;

    string name;
    int value;
    int percentage;

    struct _mark *next;
    // Make a dynamic list
}mark_t;

class Student {
    string name;
    mark_t *marks;

    public:
        void scanName(int _Num);
        
        string getName(void);
};

void writeStudents(Student *_StudentsArray, fstream *_Stream);

#endif