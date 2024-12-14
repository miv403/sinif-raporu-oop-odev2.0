#include "officeFunc.cpp"
#include <fstream>
#include <iomanip>

#define DOSYA "./data/input.txt"
#define CIKTI "./data/output.txt"

using namespace std;

void print();
int main() {
    
    print();
    
    ifstream inputFile;
    inputFile.open(DOSYA);

    Office office(inputFile);

    ofstream outputFile(CIKTI);

    office.print(outputFile);
    office.print();
    return 0;
}

void print() {
    cout << endl << MAGENTA << setw(8) << setfill('-') 
    << "" << "  Class Report Program  " << setw(8) << "" << RESET << setfill(' ') << endl;
}

//   Class Report Program  