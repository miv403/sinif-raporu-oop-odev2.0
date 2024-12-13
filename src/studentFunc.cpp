#include "courseTypeFunc.cpp"
#include "studentType.h"
#include "personFunc.cpp"
#include <iostream>
#include <cstddef>

StudentType::StudentType(string firstName,
                            string lastName,
                            string sID,
                            char isPaid,
                            size_t numberOfCourses)
    : PersonType(firstName, lastName),
    sID(sID), numberOfCourses(numberOfCourses){

}

void StudentType::setCourse(string courseName,
                            string courseNo,
                            char courseGrade,
                            int courseCredits,
                            size_t i) {

    coursesEnrolled[i].setCourseInfo(courseName,
                                        courseNo,
                                        courseGrade,
                                        courseCredits);
}

/*
StudentType::StudentType(string first, string last)
    : PersonType(first, last){

}
*/

void StudentType::setInfo(string first, string last, string no, char paid, size_t  j){
    firstName=first;
    lastName=last;
    sID=no;
    isTuitionPaid = (paid == 'Y');
    numberOfCourses=j;

    coursesEnrolled = new CourseType[numberOfCourses];
}

double StudentType::getGPA() {

    double totalPoints = 0;
    for(size_t i = 0; i < numberOfCourses; ++i) {
        totalPoints += 
                coursesEnrolled[i].getCredits() * 
                coursesEnrolled[i].getGrade();
    }

    return (totalPoints / totalCredits());

}

double StudentType::totalCredits() {

    double total= 0;

    for(size_t i = 0; i < numberOfCourses; ++i) {
        total += coursesEnrolled[i].getCredits();
    }

    return total;

}

int StudentType::billingAmount(){
    return 0;
}

void StudentType::print(int price){
    cout <<"Student Name: " <<firstName << " " << lastName << endl; 
    cout << "Student ID: " << sID << endl;
    cout<< "Number of courses enrolled: " << numberOfCourses << endl;
    cout<< "Course No Course Name Credits Grade" << endl;
    for(int i=0; i< numberOfCourses; ++i){
        coursesEnrolled[i].print();
    }
    cout << "Total number of credits: " << totalCredits() << endl; 
    cout << "Mid-Semester GPA: " << getGPA() << endl;

}