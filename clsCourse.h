#pragma once
#include <iostream>
using namespace std;

class clsCourse
{

private:
	string _CourseName;
	short _CreditHours = 0;
	float _Marks = 0;
	string _Grade;
	float _Points = 0;

	void _CalculateCreditPoints() {

		if (_Marks >= 96 && _Marks < 100) {
			_Points = 4;
			_Grade = "A+";
		}
		else if (_Marks < 96 && _Marks >= 92) {
			_Points = 3.7;
			_Grade = "A";
		}
		else if (_Marks < 92 && _Marks >= 88) {
			_Points = 3.4;
			_Grade = "A-";
		}
		else if (_Marks < 88 && _Marks >= 84) {
			_Points = 3.2;
			_Grade = "B+";
		}
		else if (_Marks < 84 && _Marks >= 80) {
			_Points = 3;
			_Grade = "B";
		}
		else if (_Marks < 80 && _Marks >= 76) {
			_Points = 2.8;
			_Grade = "B-";
		}
		else if (_Marks < 76 && _Marks >= 72) {
			_Points = 2.6;
			_Grade = "C+";
		}
		else if (_Marks < 72 && _Marks >= 68) {
			_Points = 2.4;
			_Grade = "C";
		}
		else if (_Marks < 68 && _Marks >= 64) {
			_Points = 2.2;
			_Grade = "C-";
		}
		else if (_Marks < 64 && _Marks >= 60) {
			_Points = 2;
			_Grade = "D+";
		}
		else if (_Marks < 60 && _Marks >= 55) {
			_Points = 1.5;
			_Grade = "D";
		}
		else if (_Marks < 55 && _Marks >= 50) {
			_Points = 1;
			_Grade = "D-";
		}
		else if (_Marks < 50 && _Marks > 0) {
			_Points = 0;
			_Grade = "F";
		}


	}


public:


	clsCourse(string CourseName, short CreditHours, float Marks) {

		_CourseName = CourseName;
		_CreditHours = CreditHours;
		_Marks = Marks;
		this->_CalculateCreditPoints();

	}


	void CourseName(string Name) {
		_CourseName = Name;
	}

	string GetCourseName() {
		return _CourseName;
	}


	void CreditHours(short Hours) {
		_CreditHours = Hours;
	}

	short GetCreditHours() {
		return _CreditHours;
	}


	void Marks(float Points) {
		_Marks = Points;
	}

	float GetMarks() {
		return _Marks;
	}



	void Grade(string grade) {
		_Grade = grade;
	}

	string GetGrade() {
		return _Grade;
	}


	float GetPoints() {
		return _Points * _CreditHours;
	}

};

