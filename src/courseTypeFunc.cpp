#include "courseType.h"
#include <fstream>
#include <iostream>

CourseType::CourseType(string course, string no, char grade, int credit)
: courseName(course), courseNo(no), courseGrade(grade), courseCredit(credit) {}

string CourseType::getCourseNumber(){
    return courseNo;
}

int CourseType::getCredits(){
    return courseCredit;
}

int CourseType::getGrade(){
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

void CourseType::setCourseInfo(string name,
                                string no,
                                int credit,
                                char grade){
    courseName = name;
    courseNo = no ;
    courseCredit = credit;
    courseGrade = grade;

}

void CourseType::print(ofstream& file){
    file << courseName << " " << courseNo << " " << courseGrade << " " << courseCredit<<endl;
}

void CourseType::print(){
    // TODO HİZLAMA
    cout << courseNo << " " << courseName << " " << courseCredit << " " << courseGrade<<endl;
}

CourseType::~CourseType(){}

