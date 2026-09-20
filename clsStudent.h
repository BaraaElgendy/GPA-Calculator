#pragma once
#include <iostream>
#include<vector>
#include"clsCourse.h"
using namespace std;

class clsStudent
{
private:

	
	string _StudentName;
	short _Year = 0;
	float _GPA = 0;
	float _TotalPoints = 0;
	float _TotalCreditHours = 0;
	

	vector<clsCourse> _Courses;

public:

	


	clsStudent(string Name, short Year) {
		_StudentName = Name;
		_Year = Year;
	}

	void AddCourse(string CourseName, short CreditHours, float Marks) {
		
		clsCourse Course(CourseName, CreditHours, Marks);
		
		_TotalPoints += Course.GetPoints();
		_TotalCreditHours += Course.GetCreditHours();

		_Courses.push_back(Course);

	}

	void CalculateGPA() {

		_GPA = _TotalPoints / _TotalCreditHours;

	}

	float GPA() {
		return _GPA;
	}


};

