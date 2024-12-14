#ifndef COURSE_TYPE_H
#define COURSE_TYPE_H

#include <string>

using namespace std;

class CourseType {

    public:

    CourseType( const string& courseName = " ",
                const string& courseNo = " ",
                const char& courseGrade = '*',
                const int& courseCredit = 0);
    ~CourseType();

    void setCourseInfo( const string&,
                        const string&,
                        const int&,
                        const char&);

    void print(ofstream&) const; // one parameter
    void print() const;

    int getCredits() const;
    int getGrade() const;
    string getCourseNumber() const;

    private:
                        // examples;
    string courseName;  // ComputerSci
    string courseNo;    // CSC478
    int courseCredit;  // 3
    char courseGrade;   // A

};

#endif