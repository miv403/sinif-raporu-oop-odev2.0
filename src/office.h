#ifndef OFFICE_H
#define OFFICE_H

#include "studentType.h"
#include <cstddef>
#include <string>

class TokenContainer {
    public:
        string* tokens;
        size_t size;
    string at(size_t i) {
        if(i < size)
            return tokens[i];
        return "";
    }
};

class Office {

    
    public:

    Office(ifstream&);

    void print();

    private:
    
    TokenContainer parseLine(string&);

    size_t numberOfStudents;
    int price;

    StudentType* students;

};


#endif