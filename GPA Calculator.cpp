#include <iostream>
#include"clsCourse.h"
#include"clsStudent.h"
using namespace std;


int main()
{
	
	clsStudent Student1("Baraa Elgendy", 2);
	
	Student1.AddCourse("IT Fundmentals", 3, 100);
	Student1.AddCourse("Physics 2", 3, 100);
	Student1.AddCourse("Math 1", 3, 100);
	Student1.AddCourse("Electronics", 3, 100);
	Student1.AddCourse("English", 2, 100);
	Student1.AddCourse("Computer Law", 2, 100);
	Student1.AddCourse("History", 2, 100);

	Student1.CalculateGPA();

	Student1.PrintStudentCard();



}
