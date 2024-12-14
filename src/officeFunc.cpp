#include "office.h"
#include "studentType.h"
#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>

Office::Office(ifstream& file) {
    readFile(file);
}

Office::~Office() {
    #ifdef DEBUG
    cout << "deleting: office and students." << endl;
    #endif
    delete [] students;

}

void Office::readFile(ifstream& file) {

    string line;

    getline(file, line);

    TokenContainer* tokens = parseLine(line); 

    numberOfStudents = stoi(tokens->at(0));
    price = stoi(tokens->at(1));

    delete tokens;

    students = new StudentType[numberOfStudents];

    for(size_t i = 0; i < numberOfStudents; ++i) {
        
        getline(file,line);
        
        tokens = parseLine(line);


            #ifdef DEBUG
            for(int i = 0 ; i < tokens->size(); ++i) { 
                cout << tokens->at(i) << endl;
            }
            #endif

        int courseCount = stoi(tokens->at(4));

        students[i].setInfo(tokens->at(0),           //name
                            tokens->at(1),           //lastname
                            tokens->at(2),           //id
                            tokens->at(3).at(0), //isPaid
                            courseCount);               //numberOfCourse

        delete tokens;
    
        for(size_t j = 0; j < courseCount; ++j) {

            getline(file, line);

            tokens = parseLine(line);

            #ifdef DEBUG
            for(int i = 0 ; i < tokens.size; ++i) { 
                cout << tokens->at(i) << endl;
            }
            #endif
            students[i].setCourse(tokens->at(0),
                                    tokens->at(1),
                                    stoi(tokens->at(2)),
                                    tokens->at(3).at(0),
                                    j);
            
            delete tokens;
        }
        getline(file, line); // --- atlamak için
    }
}

TokenContainer* Office::parseLine(string& line) {

    string lineCopy = line;

    size_t tokenCount{};
    size_t pos = 0;
    string token;
    string delimiter = " ";

    while((pos = lineCopy.find(delimiter)) != string::npos) {
        tokenCount++;
        lineCopy.erase(0, pos + delimiter.length());
    }
    tokenCount++;

    string* tokens = new string[tokenCount];

    pos = 0;
    size_t i{};
    for(i = 0;
        ((pos = line.find(delimiter)) != string::npos);
        ++i) {
        token = line.substr(0, pos);
        tokens[i] = token;
        line.erase(0, pos + delimiter.length());
    }
    tokens[i] = line; 

    TokenContainer* ret = new TokenContainer(tokens, tokenCount);

    return ret;
}

void Office::print() const{
    for(int i=0; i < numberOfStudents; ++i){
        students[i].print(price);
        cout << endl;
    }
}

void Office::print(ofstream& file) const{
    for(int i=0; i< numberOfStudents; ++i){
        students[i].print(file, price);
        file << endl;
    }
}