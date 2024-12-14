#ifndef OFFICE_H
#define OFFICE_H

#include "studentType.h"
#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>

class TokenContainer {
    public:
    TokenContainer(string* tokens, size_t size)
        : tokens(tokens), _size(size) {
    }
    ~TokenContainer() {
        #ifdef DEBUG
        cout << "deleting: " << at(0) << " ... "
            << at(_size - 1) << endl;
        #endif
        delete [] tokens;
    }
    string at(size_t i) const {
        if(i < _size)
            return tokens[i];
        return "0";
    }
    size_t size() const {
        return _size;
    }
    void clear() {
        delete [] tokens;
        _size = 0;
    }
    private:
        size_t _size;
        string* tokens;
};

class Office {

    // TODO destructor!
    public:

    Office(ifstream&);
    ~Office();

    void print();
    void print(ofstream&);

    private:
    
    TokenContainer* parseLine(string&);
    void readFile(ifstream&);

    size_t numberOfStudents;
    int price;

    StudentType* students;

};


#endif