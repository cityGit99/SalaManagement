#pragma once
#include <iostream>
#include <vector>
#include "Student.cpp"
#include "Instructor.cpp"
#include "Course.cpp"

class SchoolDAO {
public:
    // Student management
    virtual void addStudent(Student* student, Course* course) = 0;
    virtual void viewStudents(Course* course) const = 0;
    virtual void updateStudent(Student* student, Course* course) = 0;
    virtual void deleteStudent(Student* student, Course* course) = 0;

    // Instructor management
    virtual void addInstructor(Instructor* instructor, Course* course) = 0;
    virtual void viewInstructors(Course* course) const = 0;
    virtual void updateInstructor(Instructor* instructor, Course* course) = 0;
    virtual void deleteInstructor(Instructor* instructor, Course* course) = 0;

    // Course management
    virtual void addCourse(Course* course) = 0;
    virtual void viewCourseDetails(Course* course) const = 0;
    virtual void updateCourse(Course* course) = 0;
    virtual void deleteCourse(Course* course) = 0;

    // Data persistence
    virtual void saveStudentsData() const = 0;
    virtual void loadStudentsData() = 0;

    virtual void saveCoursesData() const = 0;
    virtual void loadCoursesData() = 0;

    // Search and sorting
    virtual void searchStudent(const std::string& keyword) const = 0;
    virtual void sortStudents() = 0;

    virtual ~SchoolDAO() {}
};
