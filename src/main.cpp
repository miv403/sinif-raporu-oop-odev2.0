#include "officeFunc.cpp"
#include "studentFunc.cpp"
#include <fstream>

#define DOSYA "./data/input.txt"

using namespace std;

int main() {
    
    ifstream inputFile;
    inputFile.open(DOSYA);

    Office office(inputFile);
    office.print();

    return 0;
}