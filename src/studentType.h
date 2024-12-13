#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H
#include "personType.h"
#include "courseType.h"
#include <cstddef>

class StudentType : public PersonType {

    public:

    StudentType(string, string,     // ad soyad
                int,                // öğrenci numarası
                char,               // isTuitionPaid
                size_t);            // numberOfCourses

    void setName();
    string getName();

    int billingAmount(int); // 5. fatura tutarının hesaplanması


    private:

    void sortCourses();
    int sID;
    size_t numberOfCourses;
    bool isTuitionPaid;
    CourseType* coursesEnrolled;

};

#endif
