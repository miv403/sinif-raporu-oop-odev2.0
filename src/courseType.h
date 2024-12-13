#ifndef COURSE_TYPE_H
#define COURSE_TYPE_H

#include <string>

using namespace std;

class CourseType {

    public:

    CourseType(string courseName = " ",
                string courseNo = " ",
                char courseGrade = '*',
                int courseCredits = 0);
    ~CourseType();

    void setCourseInfo(string, string, int, char);
    void print(ofstream&); // one parameter
    void print();    //void print(int, int); // two parameter (int geçici)
    int getCredits();
    string getCourseNumber();
    int getGrade();

    private:
                        // examples;
    string courseName;  // ComputerSci
    string courseNo;    // CSC478
    char courseGrade;   // A
    int courseCredits;  // 3

};

#endif