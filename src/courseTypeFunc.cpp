#include "courseType.h"
#include <fstream>
#include <iostream>

CourseType::CourseType(string course, string no, char grade, int credit)
: courseName(course), courseNo(no), courseGrade(grade), courseCredits(credit) {}

string CourseType::getCourseNumber(){
    return courseNo;
}

int CourseType::getCredits(){
    return courseCredits;
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

void CourseType::setCourseInfo(string course,
                                string no, int credit, char grade){
    courseName=course;
    courseNo=no;
    courseGrade=grade;
    courseCredits=credit;
}

void CourseType::print(ofstream& file){
    file << courseName << " " << courseNo << " " << courseGrade << " " << to_string(courseCredits)<<endl;
}

void CourseType::print(){
    cout << courseNo << " " << courseName << " " << courseCredits << " " << courseGrade<<endl;
}

CourseType::~CourseType(){}

