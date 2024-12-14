#include "studentType.h"
#include "courseFunc.cpp"
#include "personFunc.cpp"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <iomanip>

extern const string RED = "\033[31m";
extern const string GREEN = "\033[32m";
extern const string YELLOW = "\033[33m";
extern const string BLUE = "\033[34m";
extern const string MAGENTA = "\033[35m";
extern const string CYAN = "\033[36m";
extern const string BCYAN = "\033[96m";
extern const string BGREEN = "\033[92m";
extern const string RESET = "\033[0m";  // Resets to default color

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
        cout <<"Student Name: " << setw(26) 
            << firstName + " " + lastName << endl; 
        cout << "Student ID: " << setw(28) << sID << endl;
        cout << "Number of courses enrolled: " << setw(12) 
            << numberOfCourses << endl;
        cout << endl;
        cout << setw(11) << "Course No";
        cout << setw(13) << "Course Name";
        cout << setw(9) << "Credits";
        cout << setw(7) << "Grade" << endl;
        cout << setw(41) << setfill('-') << "" << endl << setfill(' ');

        for(int i=0; i< numberOfCourses; ++i){
            coursesEnrolled[i].print();
        }
        cout << endl << "Total number of credits: " << setw(15) << totalCredits() << endl; 
        cout << "Mid-Semester GPA: " << setw(22) <<getGPA() << endl;

    }else {
        cout << YELLOW << firstName << " " << lastName << RESET
        << " need to pay the tuition to see\nthe courses and the grades.\n"
        << "Total fee: " << setw(28) << BGREEN << billingAmount(price)  << GREEN << "$" << RESET << endl;
    }

}

void StudentType::print(ofstream& file, const int& price){

    sortCourses();
    if(isTuitionPaid){
        file <<"Student Name: " << setw(26) 
            << firstName + " " + lastName << endl; 
        file << "Student ID: " << setw(28) << sID << endl;
        file << "Number of courses enrolled: " << setw(12) 
            << numberOfCourses << endl;
        file << endl;
        file << setw(11) << "Course No";
        file << setw(13) << "Course Name";
        file << setw(9) << "Credits";
        file << setw(7) << "Grade" << endl;
        file << setw(41) << setfill('-') << "" << endl << setfill(' ');

        for(int i=0; i< numberOfCourses; ++i){
            coursesEnrolled[i].print(file);
        }
        file << endl << "Total number of credits: " << setw(15) << totalCredits() << endl; 
        file << "Mid-Semester GPA: " << setw(22) << getGPA() << endl;

    }else {
        file << firstName << " " << lastName
        << " need to pay the tuition to see\nthe courses and the grades.\n"
        << "Total fee: " << setw(28) << billingAmount(price) << "$"<< endl;
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



