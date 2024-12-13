#ifndef OFFICE_H
#define OFFICE_H

#include "studentType.h"
#include <cstddef>
#include <string>

class TokenContainer {
    public:
        string* tokens;
        size_t size;
};

class Office {

    
    public:

    Office(ifstream&);
    ~Office();
    void removeFront();
    void addBack(StudentType*);
    bool empty() const;


    private:
    
    TokenContainer parseLine(string&);

    size_t numberOfStudents;
    int price;

    StudentType* studentsHead;

};


#endif