#pragma once
#include <iostream>
#include "Student.cpp"
#include "Login.cpp"
#include "SchoolDAO.cpp"
#include "School.cpp"

using namespace std;

enum {
    ADD_STUDENT = 1,
    DISPLAY_STUDENTS,
    UPDATE_STUDENT,
    DELETE_STUDENT,
    SEARCH_STUDENTS,
    SORT_STUDENTS,
    ADD_COURSE,
    VIEW_COURSES,
    UPDATE_COURSE,
    DELETE_COURSE,
    ADD_INSTRUCTOR,
    VIEW_INSTRUCTORS,
    UPDATE_INSTRUCTOR,
    DELETE_INSTRUCTOR,
    LOGOUT_SCHOOL
};

class SchoolApplication {
private:
    School s;
    Student* student{};

    void schoolMenu() {
        cout << "========== School Management Menu ==========" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Search Students" << endl;
        cout << "6. Sort Students" << endl;
        cout << "7. Add Course" << endl;
        cout << "8. View Courses" << endl;
        cout << "9. Update Course" << endl;
        cout << "10. Delete Course" << endl;
        cout << "11. Add Instructor" << endl;
        cout << "12. View Instructors" << endl;
        cout << "13. Update Instructor" << endl;
        cout << "14. Delete Instructor" << endl;
        cout << "15. Logout" << endl;
    }

    void authenticationMenu() {
        cout << "========== School Management System ==========" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
    }

    int getChoice() {
        int choice;
        cout << "Enter your choice (1-15): ";
        cin >> choice;
        return choice;
    }

public:
    void schoolManagement() {
        s.loadStudentsData();
        s.loadCoursesData();

        int choice = 0;

        do {
            schoolMenu();
            choice = getChoice();

            switch (choice) {
            case ADD_STUDENT: {

                char choice;
                do {
                    auto student = make_unique<Student>();
                    student->input();
                    s.addStudent(student.release());
                    cout << "Student added successfully." << endl;

                    cout << "Do you want to add another student? (y/n): ";
                    cin >> choice;
                } while (choice == 'y' || choice == 'Y');
                s.saveStudentsData();

                break;
            }

            case DISPLAY_STUDENTS:
                s.viewStudents();
                break;

            case UPDATE_STUDENT:
                s.updateStudent(student);
                break;

            case DELETE_STUDENT:
                s.deleteStudent(student);
                break;
            case ADD_COURSE:
                Course* course = new Course();
                course->input(); 
                s.addCourse(course);
                cout << "Course added successfully." << endl;
                s.saveCoursesData();
                break;
            case VIEW_COURSES: 
                s.viewCourseDetails();
                break;

            case UPDATE_COURSE:
                s.updateCourse();
                s.saveCoursesData();
                break;

            case DELETE_COURSE:
                s.deleteCourse();
                s.saveCoursesData();
                break;
           
            case ADD_INSTRUCTOR:
                Instructor* instructor = new Instructor();
                instructor->input();
                s.addInstructor(instructor);
                cout << "Instructor added successfully." << endl;
                s.saveCoursesData();
                break;
            case VIEW_INSTRUCTORS:
                s.viewInstructors();
                break;
            case UPDATE_INSTRUCTOR: 
                s.updateInstructor();
                s.saveCoursesData();
                break;
            case DELETE_INSTRUCTOR: 
                s.deleteInstructor();
                s.saveCoursesData();
                break;
    
            case LOGOUT_SCHOOL:
                break;

            default:
                cout << "Invalid Choice, Try again" << endl;
                break;
            }

        } while (choice != LOGOUT_SCHOOL);
    }

    void run() {
        int choice = 0;
        Login log;

        do {
            authenticationMenu();
            choice = getChoice();

            switch (choice) {
            case 1:
                if (log.userLogin()) {
                    system("cls");
                    schoolManagement();
                }
                else {
                    cout << "Login failed. Please try again." << endl;
                }
                break;

            case 2:
                log.userRegister();
                break;

            case 3:
                exit(1);

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }

        } while (choice != 0);
    }
};
