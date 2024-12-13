#include "office.h"
#include "studentType.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

Office::Office(ifstream& file) {

    studentsHead = nullptr;

    string line;

    getline(file, line);

    TokenContainer tokens = parseLine(line);

    numberOfStudents = stoi(tokens.tokens[0]);
    price = stoi(tokens.tokens[1]);

    for(size_t i = 0; i < numberOfStudents; ++i) {
        
        getline(file,line);
        
        tokens = parseLine(line);

        int courseCount = stoi(tokens.tokens[4]);

        StudentType* student = 
        new StudentType(tokens.tokens[0],
                        tokens.tokens[1],
                        stoi(tokens.tokens[2]),
                        tokens.tokens[3].at(0),
                        stoi(tokens.tokens[4]));


        for(size_t j = 0; j < courseCount; ++j) {

            getline(file, line);
            tokens = parseLine(line);



            
        }

        // getline() // --- atlamak için
    }
}

TokenContainer Office::parseLine(string& line) {

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

    // alınan satırın boşluk ile ayrılarak vektöre eklenmesi
    pos = 0;

    size_t i = 0;

    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        tokens[i] = token;
        line.erase(0, pos + delimiter.length());
        i++;
    }
    tokens[i] = line; 

    return {tokens, tokenCount};

}


void Office::removeFront()			// remove front item
{
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    StudentType* temp = studentsHead;	// save current studentsHead
    studentsHead = studentsHead->next;	// skip over old studentsHead
    delete temp;						// delete the old studentsHead
}

void Office::addBack(StudentType* v)
{
    v->next			= NULL;

    if (studentsHead == NULL) studentsHead = v;
    else
    {
        StudentType* first = studentsHead;
        while (first->next != NULL) first = first->next;
        first->next = v;
    }
}

bool Office::empty() const							// is list empty?
{
    return studentsHead == NULL;
}

Office::~Office()							// destructor
{
    while (!empty()) removeFront();
}