#pragma once
#include <iostream>
#include <string>
#include "BaseEntity.cpp"
#include "DataInputValidation.cpp"
#include"Course.cpp"

using namespace std;

class Student : public Person {
private:
    double gpa;
    bool hasGpa;
public:

    Student() : Person(), gpa(-1.0), hasGpa(false) {}
    Student(int id, const string& name, int age) : Person(id, name, age), gpa(-1.0), hasGpa(false) {}

    void setGpa(double gpa) {
        if (gpa >= 0.0 && gpa <= 4.0) {
            this->gpa = gpa;
            hasGpa = true;
        }
        else {
            throw invalid_argument("GPA must be between 0.0 and 4.0");
        }
    }
    double getGpa() const {
        if (hasGpa) {
            return gpa;
        }
        else {
            throw logic_error("GPA has not been assigned yet");
        }
    }

    // Method to enroll in a course
    void enrollInCourse(Course& course) {
        course.enrollStudent(this);
    }

    void output() const override {
        Person::output();
        if (hasGpa) {
            cout << "GPA: " << getGpa() << endl;
        }
        else {
            cout << "GPA: Not assigned" << endl;
        }
    }
    void input() override {
        Person::input();
        gpa = -1.0;
        hasGpa = false; // GPA has not been assigned yet
    }
};
