#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H
#include "personType.h"
#include "courseType.h"
#include <cstddef>

class StudentType : public PersonType {

    public:

    StudentType(const string& = "",    // ad soyad
                const string& = "",    // öğrenci numarası           
                const string& = "",    // isTuitionPaid                
                const char& = '*',     // numberOfCourses                
                const size_t& = 0);            

    ~StudentType();

    void setInfo(   const string&,      // ad soyad
                    const string&,      // öğrenci numarası
                    const string&,      // isTuitionPaid
                    const char&,
                    const size_t&);

    void setCourse( const string&,
                    const string&,
                    const int&,
                    const char&,
                    const size_t&);      // index number

    void setName();     // FIXME kullanılmıyor setName()
    string getName();   // FIXME kullanılmıyor getName()

    void print(const int&);
    void print(ofstream&, const int&);

    private:

    void sortCourses();
    double totalCredits() const;        // toplam kredi saat hesaplama
    int billingAmount(const int&) const;     // 5. fatura tutarının hesaplanması
    double getGPA() const;            // not ortalama hesaplama

    string sID;
    size_t numberOfCourses;
    bool isTuitionPaid;
    CourseType* coursesEnrolled;

};



#endif
