#include "office.h"
#include "studentType.h"
#include <cstddef>
#include <fstream>
#include <string>

Office::Office(ifstream& file) {

    string line;

    getline(file, line);

    TokenContainer tokens = parseLine(line);

    numberOfStudents = stoi(tokens.tokens[0]);
    price = stoi(tokens.tokens[1]);

    students = new StudentType[numberOfStudents];

    for(size_t i = 0; i < numberOfStudents; ++i) {
        
        getline(file,line);
        
        tokens = parseLine(line);

        int courseCount = stoi(tokens.tokens[4]);

        students[i].setInfo(tokens.at(0),           //name
                            tokens.at(1),           //lastname
                            tokens.at(2),           //id
                            tokens.at(3).at(0), //isPaid
                            courseCount);               //numberOfCourse
    
        for(size_t j = 0; j < courseCount; ++j) {

            getline(file, line);
            tokens = parseLine(line);
            
            students[i].setCourse(tokens.at(0),
                                    tokens.at(1),
                                    stoi(tokens.at(2)),
                                    tokens.at(3).at(0),
                                    j);

        }

        getline(file, line); // --- atlamak için
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

