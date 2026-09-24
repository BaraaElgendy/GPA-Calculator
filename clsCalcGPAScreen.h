#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsStudent.h"
#include<string>

using namespace std;
class clsCalcGPAScreen
{

private:

	static void _EnterCourseInfo(clsStudent& Student) {

		cout << "\t\n**Adding A New Course**\n";

		cout << "\nEnter Course Name: ";
		string CourseName = clsInputValidate::ReadString();

		cout << "Enter Course Credit Hours: ";
		short CreditHours = clsInputValidate::ReadNumberBetween<short>(0, 3);

		cout << "Enter Your Mark: ";
		float Marks = clsInputValidate::ReadNumberBetween<float>(0, 100);

		Student.AddCourse(CourseName, CreditHours, Marks);

	}


public:


	static void ShowCalcGPAScreen() {

		cout << "\nEnter Your Name: ";
		string StudentName = clsInputValidate::ReadString();

		cout << "\nEnter What Year Are You In: ";
		short Year = clsInputValidate::ReadNumber<short>();

		clsStudent Student(StudentName, Year);


		char Choice = 'n';

		do {

			_EnterCourseInfo(Student);
			cout << "\nDo You Want To Add More Courses? (Y/N) ";
			cin >> Choice;
			

		} while (tolower(Choice) == 'y');

		Student.CalculateGPA();
		Student.PrintStudentCard();

	}


};

