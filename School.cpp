#pragma once
#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
#include "Instructor.cpp"
#include "Student.cpp"
#include "Course.cpp"
#include "SchoolDAO.cpp"
using namespace std;

enum {
    FINDNUM = 1, FINDNAME
};
enum {
    SORTNUM = 1, SORTNAME
};

class School : public SchoolDAO {
private:

    vector<Student*> students;
    vector<Instructor*> instructors;
    vector<Course*> courses;

public:
    // Implement methods for student management

    void addStudent(Student* student, Course* course) override {
        auto it = find(course->getStudents().begin(), course->getStudents().end(), student);
        if (it != course->getStudents().end()) {
            cout << "Student is already enrolled in this course." << endl;
            return;
        }
        course->enrollStudent(student);
        cout << "Student added to the course successfully." << endl;
    }
    void viewStudents(Course* course) const override {
         vector<Student*> enrolledStudents = course->getStudents();
         if (enrolledStudents.empty()) {
             cout << "No students enrolled in this course." << endl;
         }
         else {
             cout << "Students enrolled in " << course->getName() << ":\n";
             for (const auto& student : enrolledStudents) {
                 student->output();
             }
         }
     }
    void updateStudent(Student* student, Course* course) override{

    cout << "==========UPDATE STUDENT==========" << endl;
    cout << "1. Update by ID" << endl;
    cout << "2. Update by Name" << endl;
    cout << "Enter choice(1-2): ";
    int choice;
    cin >> choice;

    switch (choice) {
    case FINDNUM: {
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        auto it = find_if(course->getStudents().begin(), course->getStudents().end(),
            [id](const Student* s) { return s->getId() == id; });
        if (it != course->getStudents().end()) {
            (*it)->output();
            updateStudentDetails(*(*it));
        }
        else {
            cout << "Student not found." << endl;
        }
        break;
    }
    case FINDNAME: {
        string name;
        cout << "Enter student Name: ";
        cin >> name;

        auto it = find_if(course->getStudents().begin(), course->getStudents().end(),
            [name](const Student* s) { return s->getName() == name; });
        if (it != course->getStudents().end()) {
              (*it)->output();
            updateStudentDetails(*(*it));
        }
        else {
            cout << "Student not found." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}
    void updateStudentDetails(Student& student) {
        int choice;
        do {
            cout << "==========UPDATE STUDENT DETAILS==========" << endl;
            cout << "1. Update ID" << endl;
            cout << "2. Update Name" << endl;
            cout << "3. Update Age" << endl;
            cout << "4. Update GPA" << endl;
            cout << "5. Back to main menu" << endl;
            cout << "Enter choice(1-5): ";

            cin >> choice;

            switch (choice) {

            case 1: {
                int newId;
                cout << "Enter new ID: ";
                cin >> newId;
                student.setId(newId);
                cout << "ID updated successfully." << endl;
                break;
            }
            case 2: {
                string newName;
                cout << "Enter new Name: ";
                cin >> newName;
                student.setName(newName);
                cout << "Name updated successfully." << endl;
                break;
            }
            case 3: { 

                int newAge;
                cout << "Enter new Age: ";
                cin >> newAge;
                student.setAge(newAge);
                cout << "Age updated successfully." << endl;
                break;
            }
            case 4: {
                float newGPA;
                cout << "Enter new GPA: ";
                cin >> newGPA;
                student.setGpa(newGPA);
                cout << "GPA updated successfully." << endl;
                break;
            }
            case 5: // Back
                cout << "Exiting update student details menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 5);
    }
    void deleteStudent(Student* student, Course* course) override {
        int choice;
        cout << "==========DELETE STUDENT==========" << endl;
        cout << "1. Delete by ID" << endl;
        cout << "2. Delete by Name" << endl;
        cout << "3. Cancel" << endl;
        cout << "Enter choice(1-3) : ";
        cin >> choice;

        switch (choice) {
        case FINDNUM: {
            int findID;
            cout << "Enter ID: ";
            cin >> findID;
            auto it = find_if(course->getStudents().begin(), course->getStudents().end(), [findID](const Student* s) {
                return s->getId() == findID;
                });
            if (it != course->getStudents().end()) {
                cout << "Student found:" << endl;
                (*it)->output();
                cout << "Are you sure you want to delete this student? (Y/N): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    course->getStudents().erase(it);
                    cout << "Student deleted successfully." << endl;
                }
                else {
                    cout << "Deletion canceled." << endl;
                }
            }
            else {
                cout << "Student with ID " << findID << " not found." << endl;
            }
            break;
        }
        case FINDNAME: {
            string findName;
            cout << "Enter Name: ";
            cin >> findName;
            auto it = find_if(course->getStudents().begin(), course->getStudents().end(), [findName](const Student* s) {
                return s->getName() == findName;
                });
            if (it != course->getStudents().end()) {
                cout << "Student found:" << endl;
                (*it)->output();
                cout << "Are you sure you want to delete this student? (Y/N): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    course->getStudents().erase(it);
                    cout << "Student deleted successfully." << endl;
                }
                else {
                    cout << "Deletion canceled." << endl;
                }
            }
            else {
                cout << "Student with Name " << findName << " not found." << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        // Save updated student data back to the file
        saveStudentsData();
    }

    // Implement methods for instructor management
    void addInstructor(Instructor* instructor, Course* course) override {
        // Assign the instructor to the course
        course->assignInstructor(instructor);
        cout << "Instructor added to the course successfully." << endl;
    }
    void viewInstructors(Course* course) const override {
        // Display the instructor assigned to the course
        if (course->getInstructor() != nullptr) {
            cout << "Instructor assigned to " << course->getName() << ":\n";
            course->getInstructor()->output();
        }
        else {
            cout << "No instructor assigned to this course." << endl;
        }
    }
    void updateInstructor(Instructor* instructor, Course* course) override {
        course->assignInstructor(instructor);
        cout << "Instructor updated successfully." << endl;
    }
    void deleteInstructor(Instructor* instructor, Course* course) override {
        // Unassign the instructor from the course
        course->assignInstructor(nullptr);
        cout << "Instructor removed from the course successfully." << endl;
    }

    // Implement methods for course management

    void addCourse(Course* course) override {
        courses.push_back(course);
        cout << "Course added successfully." << endl;
    }
    void viewCourseDetails(Course* course) const override {
        cout << "Course Details:" << endl;
        cout << "Name: " << course->getName() << endl;
        cout << "Assigned Instructor: ";
        if (course->getInstructor() != nullptr) {
            cout << course->getInstructor()->getName() << endl;
        }
        else {
            cout << "None" << endl;
        }
        cout << "Enrolled Students:" << endl;
        course->displayStudents();
    }
    void updateCourse(Course* course) override {
        string newName;
        cout << "Enter the new name for the course: ";
        cin >> newName;
        course->setName(newName);

        cout << "Do you want to update the instructor for this course? (Y/N): ";
        char choice;
        cin >> choice;

        if (toupper(choice) == 'Y') {
            // Display available instructors
            cout << "Available Instructors:" << endl;
            for (const auto& instructor : instructors) {
                cout << instructor->getName() << endl;
            }

            cout << "Enter the name of the new instructor: ";
            string newInstructorName;
            cin >> newInstructorName;

            // Find the instructor by name
            auto it = find_if(instructors.begin(), instructors.end(), [newInstructorName](const Instructor* instructor) {
                return instructor->getName() == newInstructorName;
                });

            if (it != instructors.end()) {
                // Assign the new instructor to the course
                course->assignInstructor(*it);
                cout << "Instructor updated successfully." << endl;
            }
            else {
                cout << "Instructor not found." << endl;
            }
        }
    }
    void deleteCourse(Course* course) override {
        auto it = find(courses.begin(), courses.end(), course);
        if (it != courses.end()) {
            courses.erase(it);
            delete course;
            cout << "Course deleted successfully." << endl;
        }
        else {
            cout << "Course not found." << endl;
        }
    }

    // Implement data persistence methods

    void saveStudentsData() const override {
        ofstream outputFile("Students.dat", ios::out | ios::binary);

        if (!outputFile.is_open()) {
            cout << "Error in creating file...\n";
            exit(1);
        }

        for (const auto& student : students) {
            outputFile << student->getId() << ' ' << student->getName() << ' ' << student->getAge() << ' ' << student->getGpa() << endl;
        }

        cout << "Student data saved successfully" << endl;
        outputFile.close();
    }
    void loadStudentsData() override {
        ifstream inputFile("Students.dat", ios::in);

        if (!inputFile.is_open()) {
            cout << "Error in opening file...\n";
            exit(1);
        }

        int id, age;
        float gpa;
        string name;

        while (inputFile >> id >> name >> age >> gpa) {
            Student* student = new Student(id, name, age, gpa);
            students.push_back(student);
        }

        cout << "Student data loaded successfully" << endl;
        inputFile.close();
    }
    void saveCoursesData() const override {
        ofstream outputFile("Courses.dat", ios::out | ios::binary);
        if (!outputFile.is_open()) {
            cout << "Error in creating file...\n";
            exit(1);
        }
        for (const auto& course : courses) {
            outputFile << course->getName() << endl;
        }
        cout << "Course data saved successfully." << endl;
        outputFile.close();
    }
    void loadCoursesData() override {
        ifstream inputFile("Courses.dat", ios::in);
        if (!inputFile.is_open()) {
            cout << "Error in opening file...\n";
            exit(1);
        }
        string name;
        while (getline(inputFile, name)) {
            Course* course = new Course(name);
            courses.push_back(course);
        }
        cout << "Course data loaded successfully." << endl;
        inputFile.close();
    }

    // Implement search and sorting methods
    void searchStudent(const string& keyword) const override {
        bool found = false;
        cout << "Searching for students with keyword '" << keyword << "'..." << endl;
        for (const auto& student : students) {
            if (student->getName().find(keyword) != string::npos) {
                cout << "Found matching student:" << endl;
                student->output();
                found = true;
            }
        }
        if (!found) {
            cout << "No students found with keyword '" << keyword << "'" << endl;
        }
    }
    void sortStudents() override {
        int choice;
        cout << "==========SELECT MENU==========" << endl;
        cout << "1. Sort by ID" << endl;
        cout << "2. Sort by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case SORTNUM: {
            int choice;
            cout << "==========SORT MENU==========" << endl;
            cout << "1. Sort by Ascending" << endl;
            cout << "2. Sort by Descending" << endl;
            cout << "3. Back to main menu" << endl;
            cout << "Enter choice(1-3) -> ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                sort(students.begin(), students.end(), [](const Student* a, const Student* b) {
                    return a->getId() < b->getId();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                sort(students.begin(), students.end(), [](const Student* a, const Student* b) {
                    return a->getId() > b->getId();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

        }
                    break;
        case SORTNAME: {
            int choice;
            cout << "==========SORT MENU==========" << endl;
            cout << "1. Sort by Ascending" << endl;
            cout << "2. Sort by Descending" << endl;
            cout << "3. Back to main menu" << endl;
            cout << "Enter choice(1-3) -> ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                sort(students.begin(), students.end(), [](const Student* a, const Student* b) {
                    return a->getName() < b->getName();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                sort(students.begin(), students.end(), [](const Student* a, const Student* b) {
                    return a->getName() > b->getName();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }

    // Additional helper methods
    void DotDotDot();

    ~School() {
        // Delete dynamically allocated memory
        for (auto& student : students) {
            delete student;
        }
        for (auto& instructor : instructors) {
            delete instructor;
        }
        for (auto& course : courses) {
            delete course;
        }
    }
};

