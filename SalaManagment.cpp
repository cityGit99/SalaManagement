#pragma once
#include <iostream>
#include <string>
#include<iomanip>
#include"DataInputValidation.cpp"
#include"BaseEntity.cpp"
#include"Student.cpp"
#include"School.cpp"
#include"SchoolDAO.cpp"
#include "SchoolApplication.cpp"

using namespace std;

int main()
{
    
    SchoolApplication App;

    App.run();

    return 0;
}

