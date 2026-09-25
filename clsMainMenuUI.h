#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsCalcGPAScreen.h"
#include"clsCalcCGPAScreen.h"
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

	static short ReadMainMenuOption(string Message) {
		cout << Message;
		return clsInputValidate::ReadNumberBetween<short>(1, 4);
	}

	static void PerformMainMenuOption(enChoice Choice) {

		system("cls");

		switch (Choice) {

		case enCalcGPA:
			clsCalcGPAScreen::ShowCalcGPAScreen();
			break;
			
		case enCalcCGPA:
			clsCalcCGPAScreen::ShowCalcCGPAScreen();
			break;
		case enFindResult:
			cout<<"find result func";
			break;
		case enShowHistory:
			cout << "show history func";
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
		cout << "\t\t\t\t  [3] Find Student Result\n";
		cout << "\t\t\t\t  [4] Show Calculations History\n";
		cout << "\t\t\t\t======================================\n";
		PerformMainMenuOption((enChoice)ReadMainMenuOption("\t\t\t\tEnter Your Choice [1 to 4] "));

	}

};

