#pragma once
#include<iostream>
#include<string>

using namespace std;

class DataInputValidation {
private:

	//For Student/Instructor
	bool validate_id(int id) {
		if (id <= 0) {
			return false;
		}
		string idString = to_string(id);
		if (idString.length() != 6) {
			return false;
		}
		for (char c : idString) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}

	bool validate_name(const string& name) {
		if (name.length() > 25) {
			return false;
		}
		for (char c : name) {
			if (!isalpha(c) && c != ' ') {
				return false;
			}
		}
		return true;
	}
	bool validate_age(int age) {
		if (cin.fail() || age < 2 || age >150) {
			return false;
		}
		return true;
	}

	bool validate_session(int session) {
		if (cin.fail() || session < 0) {
			return false;
		}
		return true;
	}

	bool validate_gpa(double gpa) {
		if (cin.fail() || gpa < 0.0 || gpa > 4.0) {
			return false;
		}
		return true;
	}

	//For Course
	bool validate_code(string code) {
		if (code.length() != 4) {
			return false;
		}
		for (char c : code) {
			if (!isdigit(c)) {
				return false;
			}
		}
		return true;
	}

public:

	int input_id() {
		int id;
		while (true) {
			cout << "Enter Id: ";
			cin >> id;
			if (!cin || !validate_id(id)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error: Invalid data input" << endl;
				cout << "ID must be a six-digit number and cannot be less than zero." << endl;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		return id;
	}
	string input_name() {
		string name;
		while (true) {
			cout << "Enter name: ";
			getline(cin, name);
			if (!validate_name(name)) {
				cout << "Error: Invalid data types or maximum length exceeded." << endl;
				cout << "Tip: Name must be 25 characters or less, and only contain letters or spaces." << endl;
				cout << "More ASCII codes: www.asciitable.com" << endl;
			}
			else {
				return name;
			}
		}
	}
	int input_age() {
		int age;
		while (true) {
			cout << "Enter age:	";
			cin >> age;
			if (!validate_age(age)) {
				cin.clear();
				cin.ignore(150, '\n');
				cout << "Error: Invalid data input" << endl;
				cout << "Tip: Age should not below 02 years old nor exceed 150 years old" << endl;
			}
			else {
				return age;
			}
		}
	}

	int input_session() {
		int session;
		while (true) {
			cout << "Enter session:		";
			cin >> session;
			if (!validate_session(session)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error: Invalid input, session can not below zero" << endl;
			}
			else {
				return session;
			}
		}
	}


	double input_gpa() {
		double gpa;
		while (true) {
			cout << "Enter GPA: ";
			cin >> gpa;
			if (!validate_gpa(gpa)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error: Invalid input. GPA must be a non-negative number between 0.0 and 4.0" << endl;
			}
			else {
				break;
			}
		}
		return gpa;
	}
	//For Course
	string input_code() {
		string code;
		while (true) {
			cout << "Enter Code: ";
			cin >> code;
			if (!validate_code(code))
			{
				cin.clear();
				cin.ignore(9999999, '\n');
				cout << "Error: Invalid data input" << endl;
				cout << "Code must be a four digit number." << endl;
			}
			else {
				break;
			}
		}
		return code;
	}

};