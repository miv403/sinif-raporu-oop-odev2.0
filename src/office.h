#ifndef OFFICE_H
#define OFFICE_H

#include "studentType.h"
#include <cstddef>

class LineContainer {
    string* tokens;
    size_t size;
};

class Office {

    

    Office(ifstream&);

    LineContainer* parseLine();


    private:

    size_t numberOfStudents;
    int price;

    StudentType* students;

};


#endif