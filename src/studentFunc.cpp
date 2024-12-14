#include "courseTypeFunc.cpp"
#include "studentType.h"
#include "personFunc.cpp"
#include <iostream>
#include <fstream>
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
                            int courseCredits,
                            char courseGrade,
                            size_t i) {

    coursesEnrolled[i].setCourseInfo(courseName,
                                    courseNo,
                                    courseCredits,
                                    courseGrade);

}

/*
StudentType::StudentType(string first, string last)
    : PersonType(first, last){

}
*/

void StudentType::setInfo(string first, string last, string no, char paid, size_t j){
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

int StudentType::billingAmount(int price){
    int bill=0;
    bill=price*totalCredits();
    return bill;
}

void StudentType::print(int price){

    // TODO sortCourses()
    // TODO DOSYAYA YAZMA
    // TODO if(isPaid) ... else { billigAmount}

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
    }

    else{
        cout <<firstName << " "<<lastName<< " need to pay the tuition to see the courses and the grades. Total fee: " << billingAmount(price)  << "₺"<< endl;
    }
}
 void StudentType::print(ofstream& file, int price){
    if(isTuitionPaid){  
    file <<"Student Name: " <<firstName << " " << lastName << endl; 
    file << "Student ID: " << sID << endl;
    file << "Number of courses enrolled: " << numberOfCourses << endl;
    file << "Course No Course Name Credits Grade" << endl;
    for(int i=0; i< numberOfCourses; ++i){
        coursesEnrolled[i].print(file);
    }
    file << "Total number of credits: " << totalCredits() << endl; 
    file << "Mid-Semester GPA: " << getGPA() << endl;
    }

    else{
        file <<firstName << " "<<lastName<< " need to pay the tuition to see the courses and the grades. Total fee: " << billingAmount(price)  << "₺"<< endl;
    }
 }
