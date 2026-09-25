#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsStudent.h"
#include "clsDate.h"

using namespace std;

class clsShowAllHistoryScreen
{
private:

    static void _PrintHistoryRecordLine(clsStudent& Student) {

        cout << "\t| " << left << setw(20) << Student.DateTime();
        cout << "| " << left << setw(18) << Student.Name();
        cout << "| " << left << setw(13) << Student.Year();
        cout << "| " << left << setw(6) << fixed << setprecision(2) << Student.GPA();
        cout << "| " << left << setw(6) << fixed << setprecision(2) << Student.CGPA();
        cout << "| " << left << setw(18) << Student.GetHighestCourse().GetCourseName();
        cout << "| " << left << setw(8) << Student.GetHighestCourse().GetGrade() << "|\n";
    }

public:

    static void ShowAllHistoryScreen() {

        vector<clsStudent> vStudents = clsStudent::_LoadStudentDataFromFile();

        string TitleLine = "\t======================================================================================================\n";
        string Separator = "\t+---------------------+-------------------+--------------+-------+-------+-------------------+---------+\n";

        cout << "\n" << TitleLine;
        cout << "\t\t\t\t\t  STUDENT CALCULATIONS HISTORY\n";
        cout << "\t\t\t\t\t      Total Records: (" << vStudents.size() << ")\n";
        cout << TitleLine << "\n";

        cout << Separator;
        cout << "\t| " << left << setw(20) << "Date/Time"
            << "| " << left << setw(18) << "Name"
            << "| " << left << setw(13) << "Year"
            << "| " << left << setw(6) << "GPA"
            << "| " << left << setw(6) << "CGPA"
            << "| " << left << setw(18) << "Highest Course"
            << "| " << left << setw(8) << "Grade"
            << "|\n";
        cout << Separator;

        if (vStudents.empty()) {
            cout << "\t| " << left << setw(100) << "No Student Records Available In System!" << "|\n";
        }
        else {
            for (clsStudent& Student : vStudents) {
                _PrintHistoryRecordLine(Student);
            }
        }

        cout << Separator << "\n";
    }
};