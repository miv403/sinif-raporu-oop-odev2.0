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

    void setCourseInfo();
    void print(int); // one parameter
    void print(int, int); // two parameter (int geçici)
    int getCredits();
    int getCourseNumber();
    char getGrade();

    private:
                        // examples;
    string courseName;  // ComputerSci
    string courseNo;    // CSC478
    char courseGrade;   // A
    int courseCredits;  // 3

};

#endif