#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsCalcGPAScreen.h"
#include"clsCalcCGPAScreen.h"
#include"clsShowAllHistoryScreen.h"
#include"clsFindStudentResults.h"
using namespace std;

class clsMainMenuUI
{
private:

	enum enChoice { enCalcGPA = 1, enCalcCGPA, enFindResult, enShowHistory };
	

	static void _GoBackToMainMenu() {
		cout << "Press Any Button To Go Back To Main Menu....";
		system("pause>0");
		clsMainMenuUI::ShowMainMenuScreen();
	}

	static short _ReadMainMenuOption(string Message) {
		cout << Message;
		return clsInputValidate::ReadNumberBetween<short>(1, 4);
	}

	static void _PerformMainMenuOption(enChoice Choice) {

		system("cls");

		switch (Choice) {

		case enCalcGPA:
			clsCalcGPAScreen::ShowCalcGPAScreen();
			break;
			
		case enCalcCGPA:
			clsCalcCGPAScreen::ShowCalcCGPAScreen();
			break;
		case enFindResult:
			clsFindStudentResults::ShowFindStudentResultsScreen();
			break;
		case enShowHistory:
			clsShowAllHistoryScreen::ShowAllHistoryScreen();
			break;
		}

		_GoBackToMainMenu();
	}


public:

	static void ShowMainMenuScreen() {
		system("cls");
		cout << "\t\t\t\t======================================\n";
		cout << "\t\t\t\t\tGPA Calculator Project\n";
		cout << "\t\t\t\t======================================\n";
		cout << "\t\t\t\t  [1] Calculate GPA\n";
		cout << "\t\t\t\t  [2] Calculate CGPA\n";
		cout << "\t\t\t\t  [3] Find Student Result(s)\n";
		cout << "\t\t\t\t  [4] Show All Calculations History\n";
		cout << "\t\t\t\t======================================\n";
		_PerformMainMenuOption((enChoice)_ReadMainMenuOption("\t\t\t\tEnter Your Choice [1 to 4] "));

	}

};

