#pragma once
#include<iostream>
#include"clsInputValidate.h"
using namespace std;

class clsMainMenuUI
{
private:

	enum enChoice { enCalcGPA = 1, enCalcCGPA, enFindResult, enShowHistory };
	
	static short ReadMainMenuOption(string Message) {
		cout << Message;
		return clsInputValidate::ReadNumberBetween<short>(1, 4);
	}

	static void PerformMainMenuOption(enChoice Choice) {
		switch (Choice) {

		case enCalcGPA:
			cout << "calculate gpa func";
			break;
		case enCalcCGPA:
			cout << "calculate cgpa func";
			break;
		case enFindResult:
			cout<<"find result func";
			break;
		case enShowHistory:
			cout << "show history func";
			break;
		}
	}


public:

	static void ShowMainMenuScreen() {

		cout << "\t\t\t\t======================================\n";
		cout << "\t\t\t\t\tGPA Calculator Project\n";
		cout << "\t\t\t\t======================================\n";
		cout << "\t\t\t\t  [1] Calculate GPA\n";
		cout << "\t\t\t\t  [2] Calculate CGPA\n";
		cout << "\t\t\t\t  [3] Find Student Result\n";
		cout << "\t\t\t\t  [4] Show Calculations History\n";
		cout << "\t\t\t\t======================================\n";
		PerformMainMenuOption((enChoice)ReadMainMenuOption("\t\t\t\tEnter Your Choice [1 to 4] "));

	}

};

