#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H
#include "personType.h"
#include "courseType.h"
#include <cstddef>

class StudentType : public PersonType {

    public:

    StudentType(string = "",
                string = "",              // ad soyad
                string = "",                // öğrenci numarası
                char = '*',               // isTuitionPaid
                size_t = 0);            // numberOfCourses

    void setInfo(string,
                string,              // ad soyad
                string,                // öğrenci numarası
                char,               // isTuitionPaid
                size_t);

    void setName();
    string getName();



    void setCourse(string,
                    string,
                    int, 
                    char,
                    size_t i);

    void print(int);

    private:

    int billingAmount();     // 5. fatura tutarının hesaplanması
    void sortCourses();
    double getGPA();            // not ortalama hesaplama
    double totalCredits();        // toplam kredi saat hesaplama


    string sID;
    size_t numberOfCourses;
    bool isTuitionPaid;
    CourseType* coursesEnrolled;

};



#endif
