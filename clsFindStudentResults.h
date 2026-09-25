#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsStudent.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include"clsStudent.h"

using namespace std;

class clsFindStudentResults
{
private:

    static vector<clsStudent> _GetStudentsByName(vector<clsStudent> vAllStudents, const string& Name) {

        vector<clsStudent> vMatched;
        string TargetName = clsString::LowerAllString(Name);

        for (clsStudent& Student : vAllStudents) {

            if (TargetName == clsString::LowerAllString(Student.Name())) {
                vMatched.push_back(Student);
            }

        }
        return vMatched;
    
    }

public:

    static void ShowFindStudentResultsScreen() {

        string TitleLine = "\t======================================================================================================\n";
        string Separator = "\t------------------------------------------------------------------------------------------------------\n";

        cout << "\nEnter Student Name To Find: ";
        string Name = clsInputValidate::ReadString();

        vector<clsStudent> vAllStudents = clsStudent::_LoadStudentDataFromFile();
        vector<clsStudent> vMatchedStudents = _GetStudentsByName(vAllStudents, Name);

        cout << "\n" << TitleLine;

        if (vMatchedStudents.empty()) {

            cout << "\t\t\t\t\t  STUDENT \"" << Name << "\" NOT FOUND IN RECORDS!\n";
            cout << TitleLine << "\n";
            return;
        }

        cout << "\t\t\t\t\t  STUDENT RECENT RESULT HISTORY\n";
        cout << "\t\t\t\t\t      Total Records Found: (" << vMatchedStudents.size() << ")\n";
        cout << TitleLine << "\n";

        for (clsStudent& Student : vMatchedStudents) {

            Student.PrintStudentCard();
            cout << "\n" << Separator << "\n";
        
        }
    }
};