#include "officeFunc.cpp"
#include "studentFunc.cpp"
#include <fstream>

#define DOSYA "./data/input.txt"
#define CIKTI "./data/output.txt"

using namespace std;

int main() {
    
    ifstream inputFile;
    inputFile.open(DOSYA);

    Office office(inputFile);

    ofstream outputFile(CIKTI);

    office.print(outputFile);

    return 0;
}