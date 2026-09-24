#pragma once
#include"clsCalcGPAScreen.h"
class clsCalcCGPAScreen : protected clsCalcGPAScreen
{

public:


	static void ShowCalcCGPAScreen() {

		cout << "\nEnter Your Name: ";
		string StudentName = clsInputValidate::ReadString();

		cout << "\nEnter What Year Are You In: ";
		short Year = clsInputValidate::ReadNumberBetween<short>(1, 4);

		clsStudent Student(StudentName, Year);

		cout << "\nEnter Your CGPA: ";
		float CGPA = clsInputValidate::ReadNumberBetween<float>(0.00, 4.00);

		cout << "\nEnter Your Previous Hours: ";
		short PrevHours = clsInputValidate::ReadNumber<short>();

		Student.SetOldCGPA(CGPA);
		Student.SetPreviousCreditHours(PrevHours);


		char Choice = 'n';

		do {

			_EnterCourseInfo(Student);
			cout << "\nDo You Want To Add More Courses? (Y/N) ";
			cin >> Choice;


		} while (tolower(Choice) == 'y');

		Student.CalculateGPA();
		Student.CalculateCGPA();
		Student.PrintStudentCard();

	}


};

