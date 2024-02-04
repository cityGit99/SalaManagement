#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"BaseEntity.cpp"
#include "Student.cpp"
#include"Course.cpp"

using namespace std;

class Instructor : public Person {
private:
    string department;
public:
    Instructor() : Person() {
        department = "Unknown";
    }

    Instructor(int id, string name, int age, string department) : Person(id, name, age) {
        setDepartment(department);
    }

    void setDepartment(const string& department) {
        this->department = department;
    }

    string getDepartment() const {
        return department;
    }

    void assignToCourse(Course& course) {
        course.assignInstructor(this);
    }

    void input() override {
        Person::input();
        cout << "Enter department: ";
        getline(cin, department);
    }

    void output() const override {
        Person::output();
        cout << "Department: " << department << endl;
    }
};
