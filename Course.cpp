#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Instructor.cpp" 
#include "Student.cpp"

using namespace std;

class Course {
private:
    string name;
    Instructor* instructor;
    vector<Student*> students; 
public:

    Course(const string& name) : name(name), instructor(nullptr) {}

    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void assignInstructor(Instructor* newInstructor) {
        instructor = newInstructor;
    }

    Instructor* getInstructor() const {
        return instructor;
    }

    void enrollStudent(Student* student) {
        students.push_back(student);
    }

    void input() {
        cout << " Enter Course name:";
        cin >> name;
    }

    void displayStudents() const {
        if (students.empty()) {
            cout << "No students enrolled in this course." << endl;
        }
        else {
            cout << "Students enrolled in " << name << ":\n";
            for (const auto& student : students) {
                student->output();
            }
        }
    }

    // Getter method for retrieving the list of enrolled students
    vector<Student*> getStudents() const {
        return students;
    }

};
