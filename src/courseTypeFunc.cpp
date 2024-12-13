#include <courseType.h>
#include <fstream>

CourseType::CourseType(string course, string no, char grade, int credit)
: courseName(course), courseNo(no), courseGrade(grade), courseCredits(credit) {}

string CourseType::getCourseNumber(){
    return courseNo;
}

int CourseType::getCredits(){
    return courseCredits;
}

char CourseType::getGrade(){
    return courseGrade;
}

void CourseType::setCourseInfo(string course, string no, char grade, int credit){
    courseName=course;
    courseNo=no;
    courseGrade=grade;
    courseCredits=credit;
}

void CourseType::print(ofstream& file){
    file << courseName << " " << courseNo << " " << courseGrade << " " << to_string(courseCredits)<<endl;
}

CourseType::~CourseType(){}

