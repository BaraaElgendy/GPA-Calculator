#pragma once
#include <iostream>
#include<vector>
#include"clsCourse.h"
#include<string>
#include <iomanip>
using namespace std;

class clsStudent
{
private:

	
	string _StudentName;
	short _Year = 0;
	
	float _GPA = 0;

	float _NewCGPA = 0;
	float _OldCGPA = 0;
	
	float _TotalPoints = 0;
	float _CurrentSemesterPoints = 0;
	
	
	float _CurrentSemesterCreditHours = 0;
	float _PreviousCreditHours = 0;
	

	vector<clsCourse> _Courses;

public:

	clsStudent(const string &Name, short Year) {
		_StudentName = Name;
		_Year = Year;
	}

	clsStudent(){}

	string Name() {
		return _StudentName;
	}

	string Year() {
		switch (_Year) {
		case 1:
			return "First Year";

		case 2:
			return "Second Year";

		case 3:
			return "Third Year";

		case 4:
			return "Fourth Year";

		default: return "Unknown Year";
		}
	}



	void SetOldCGPA(float OldCGPA) {
		_OldCGPA = OldCGPA;
	}

	void SetPreviousCreditHours(float Hours) {
		_PreviousCreditHours = Hours;
	}



	clsCourse GetHighestCourse() {
		
		
		if (!_Courses.empty()) {

			float Max = INT32_MIN;

			clsCourse MaxCourse;

			for (clsCourse& Course : _Courses) {

				if (Max < Course.GetMarks()) {
					Max = Course.GetMarks();
					MaxCourse = Course;
				}
			}

			return MaxCourse;
		}
		else return{};
	}

	void AddCourse(const string &CourseName, short CreditHours, float Marks) {
		
		clsCourse Course(CourseName, CreditHours, Marks);
		
		_CurrentSemesterPoints += Course.GetPoints();
		_CurrentSemesterCreditHours += Course.GetCreditHours();

		_Courses.push_back(Course);

	}

	void CalculateGPA() {

		if (_CurrentSemesterCreditHours > 0) {
			_GPA = _CurrentSemesterPoints / _CurrentSemesterCreditHours;
		}
		else {
			_GPA = 0;
		}

	}

	void CalculateCGPA() {

		float TotalCreditHours = 0;
		float PreviousPoints = 0;

		PreviousPoints = _PreviousCreditHours * _OldCGPA;

		TotalCreditHours = _PreviousCreditHours + _CurrentSemesterCreditHours;

		_TotalPoints = PreviousPoints + _CurrentSemesterPoints;


		if (TotalCreditHours > 0) {
			_NewCGPA = _TotalPoints / TotalCreditHours;
		}
		else {
			_NewCGPA = 0;
		}
	}


	float GPA() {
		return _GPA;
	}

	float CGPA() {
		return _NewCGPA;
	}

	void PrintStudentCard() {
		// خط فاصل موحد بعرض 52 حرف
		string Separator = "\t\t\t+-------------------+--------+--------+--------+\n";
		string SolidLine = "\t\t\t=================================================\n";

		cout << "\n";
		cout << SolidLine;
		cout << "\t\t\t\t  STUDENT ACADEMIC REPORT CARD\n";
		cout << SolidLine;
		cout << "\t\t\t  Student Name : " << Name() << "\n";
		cout << "\t\t\t  Student Year : " << Year() << "\n";
		cout << SolidLine;

		// Header
		cout << "\t\t\t| " << left << setw(18) << "Course Name"
			<< "| " << setw(7) << "Hours"
			<< "| " << setw(7) << "Marks"
			<< "| " << setw(7) << "Grade"
			<< "|\n";

		cout << Separator;

		// Data Rows
		for (clsCourse& Course : _Courses) {
			cout << "\t\t\t| " << left << setw(18) << Course.GetCourseName()
				<< "| " << setw(7) << Course.GetCreditHours()
				<< "| " << setw(7) << Course.GetMarks()
				<< "| " << setw(7) << Course.GetGrade()
				<< "|\n";
		}

		cout << Separator;

		// Summary Row (Total Hours & Courses Count)
		cout << "\t\t\t| " << left << setw(18) << ("Total: " + to_string(_Courses.size()) + " Courses")
			<< "| " << setw(7) << _CurrentSemesterCreditHours
			<< "| " << setw(7) << "-"
			<< "| " << setw(7) << "-"
			<< "|\n";

		cout << Separator;

		// Footer Card
		cout << "\n\t\t\t----------------- ACADEMIC SUMMARY -----------------\n\n";
		if (!_Courses.empty()) {
			cout << "\t\t\t  Highest Mark : " << GetHighestCourse().GetCourseName()
				<< " (" << GetHighestCourse().GetMarks() << " -> " << GetHighestCourse().GetGrade() << ")\n";
		}
		cout << "\t\t\t  Semester GPA : " << fixed << setprecision(2) << GPA() << " / 4.00\n";
		cout << "\t\t\t  Cumulative CGPA : " << fixed << setprecision(2) << CGPA() << " / 4.00\n";
		cout << "\n\t\t\t----------------------------------------------------\n\n";
	}


};

