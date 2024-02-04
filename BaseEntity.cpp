#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"DataInputValidation.cpp"
#include"BadInputException.cpp"

using namespace std;


class Person {
protected:
    int id;
    string name;
    int age;
    DataInputValidation val;

public:

    Person() {
        id = 0;
        name = " unknown";
        age = 0;
    }

    Person(int id, string name, int age) {
        setId(id);
        setName(name);
        setAge(age);
    }

    void setId(int id) {
        if (id >= 0) {
            string idString = to_string(id);
            if (idString.length() <= 6) {
                this->id = id;
            }
            else {
                cout << "ID cannot exceed 6 characters." << endl;
            }
        }
        else {
            throw BadInputException();
        }
    }
    int  getId() const {
        return id;
    }

    void setName(const string name) {
        if (!name.empty()) {
            this->name = name;
        }
        else {
            throw BadInputException();
        }
    }
    string getName() const {
        return this->name;
    }

    void setAge(const int age) {
        if (age > 0) {
            this->age = age;
        }
        else {
            throw BadInputException();
        }
    }
    int getAge() const {
        return age;
    }

    virtual void output() const {
        cout << setw(6) << left << getId() << setw(25) << left << getName().substr(0, 25) <<  setw(3) << getAge() ;
    }

    virtual void input() {
        setId(val.input_id());
        setName(val.input_name());
        setAge(val.input_age());
    }

};