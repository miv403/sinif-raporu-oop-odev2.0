#include "courseType.h"
#include <fstream>
#include <iostream>
#include <iomanip>

CourseType::CourseType( const string& course,
                        const string& no,
                        const char& grade,
                        const int& credit)
    :   courseName(course),
        courseNo(no),
        courseGrade(grade),
        courseCredit(credit) {}

CourseType::~CourseType(){
    #ifdef DEBUG
    cout << "Deleting: CourseType" << endl;
    #endif
}

void CourseType::setCourseInfo( const string& name,
                                const string& no,
                                const int& credit,
                                const char& grade){
    courseName = name;
    courseNo = no ;
    courseCredit = credit;
    courseGrade = grade;
}

void CourseType::print(ofstream& file) const {
    file    << setw(11) << courseNo
            << setw(13) << courseName                
            << setw(9)  << courseCredit              
            << setw(7)  << courseGrade << endl;        
}

void CourseType::print() const {
    cout    << setw(11) << courseNo
            << setw(13) << courseName                
            << setw(9)  << courseCredit              
            << setw(7)  << courseGrade << endl;        
}

int CourseType::getCredits() const{
    return courseCredit;
}

int CourseType::getGrade() const{
    switch (courseGrade) {
        case 'A':
            return 4;
            break;
        case 'B':
            return 3;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 1;
            break;
        case 'F':
            return 0;
            break;
        default:
            cerr << "default???" << __LINE__ << endl;
            return 0;
            break;
    }
}

string CourseType::getCourseNumber() const{
    return courseNo;
}
