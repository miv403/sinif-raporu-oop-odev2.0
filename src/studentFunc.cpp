#include "courseType.h"
#include "personType.h"
#include "studentType.h"
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
