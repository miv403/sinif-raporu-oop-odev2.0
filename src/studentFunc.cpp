#include "courseType.h"
#include "personType.h"
#include "studentType.h"
#include <cstddef>

StudentType::StudentType(string firstName,
                            string lastName,
                            int sID,
                            char isPaid,
                            size_t numberOfCourses)
    : PersonType(firstName, lastName),
    sID(sID), numberOfCourses(numberOfCourses){

    isTuitionPaid = (isPaid == 'Y');

    coursesEnrolled = new CourseType[numberOfCourses];

}

void StudentType::setCourse(string courseName,
                            string courseNo,
                            char courseGrade,
                            int courseCredits,
                            size_t i) {
    
    /*
    coursesEnrolled[i].setCourseInfo(courseName,
                                        courseNo,
                                        courseGrade,
                                        courseCredits);
    */
}

/*
StudentType::StudentType(string first, string last)
    : PersonType(first, last){

}
*/