#pragma once
#include <string>
using namespace std;

class User {
private:
   string username;
   string password;

public:
    User() : username(""), password("") {}

    User(const string& username, const string& password)
        : username(username), password(password) {}

  string getUsername() const {
        return username;
    }
  string getPassword() const {
        return password;
    }
};
