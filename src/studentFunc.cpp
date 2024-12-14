#include "studentType.h"
#include "courseFunc.cpp"
#include "personFunc.cpp"
#include <iostream>
#include <fstream>
#include <cstddef>

StudentType::StudentType(   const string& firstName,
                            const string& lastName,
                            const string& sID,
                            const char& isPaid,
                            const size_t& numberOfCourses)
    :   PersonType(firstName,
        lastName),
        sID(sID),
        numberOfCourses(numberOfCourses) { }

StudentType::~StudentType() {
    #ifdef DEBUG
    cout << "deleting: Student + coursesEnrolled" << endl;
    #endif
    delete [] coursesEnrolled;
}

void StudentType::setInfo(  const string& first,
                            const string& last,
                            const string&no,
                            const char& paid,
                            const size_t& j){ 
    firstName=first;
    lastName=last;
    sID=no;
    isTuitionPaid = (paid == 'Y');
    numberOfCourses=j;

    coursesEnrolled = new CourseType[numberOfCourses];
}

void StudentType::setCourse(const string& courseName,
                            const string& courseNo,
                            const int& courseCredits,
                            const char& courseGrade,
                            const size_t& i) {

    coursesEnrolled[i].setCourseInfo(courseName,
                                    courseNo,
                                    courseCredits,
                                    courseGrade);

}

void StudentType::print(const int& price){

    sortCourses();

    if(isTuitionPaid){  
        cout<<"Student Name: " <<firstName << " " << lastName << endl; 
        cout << "Student ID: " << sID << endl;
        cout << "Number of courses enrolled: " << numberOfCourses << endl;
        cout << "Course No Course Name Credits Grade" << endl;
        for(int i=0; i< numberOfCourses; ++i){
            coursesEnrolled[i].print();
        }
        cout << "Total number of credits: " << totalCredits() << endl; 
        cout << "Mid-Semester GPA: " << getGPA() << endl;

    }else {
        cout <<firstName << " "<<lastName<< " need to pay the tuition to see the courses and the grades. Total fee: " << billingAmount(price)  << "$"<< endl;
    }
}

void StudentType::print(ofstream& file, const int& price){

    sortCourses();
    // TODO hizalama
    if(isTuitionPaid){  
        file <<"Student Name: " <<firstName << " " << lastName << endl; 
        file << "Student ID: " << sID << endl;
        file << "Number of courses enrolled: " << numberOfCourses << endl;
        file << endl << "Course No Course Name Credits Grade" << endl << endl;
        // file << -----------;

        for(int i=0; i< numberOfCourses; ++i){
            coursesEnrolled[i].print(file);
        }
        file << "Total number of credits: " << totalCredits() << endl; 
        file << "Mid-Semester GPA: " << getGPA() << endl;

    }else {
        file << firstName << " "<<lastName<< " need to pay the tuition to see the courses and the grades. Total fee: " << billingAmount(price)  << "$"<< endl;
    }
}

void StudentType::sortCourses() {

    bool swapped;
    for (int i = 0; i < numberOfCourses - 1; i++) {
        swapped = false;
        for (int j = 0; j < numberOfCourses - i - 1; j++) {
            if (coursesEnrolled[j].getCourseNumber() > coursesEnrolled[j + 1].getCourseNumber()) {
                swap(coursesEnrolled[j], coursesEnrolled[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

double StudentType::totalCredits() const {
    double total= 0;

    for(size_t i = 0; i < numberOfCourses; ++i) {
        total += coursesEnrolled[i].getCredits();
    }

    return total;
}

double StudentType::getGPA() const {

    double totalPoints = 0;
    for(size_t i = 0; i < numberOfCourses; ++i) {
        totalPoints += 
                coursesEnrolled[i].getCredits() * 
                coursesEnrolled[i].getGrade();
    }

    return (totalPoints / totalCredits());
}

int StudentType::billingAmount(const int& price) const{
    int bill=0;
    bill=price*totalCredits();
    return bill;
}



