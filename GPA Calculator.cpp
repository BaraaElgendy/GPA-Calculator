#include <iostream>
#include"clsCourse.h"
#include"clsStudent.h"
using namespace std;


int main()
{
	
	clsStudent Student1("Baraa", 2);
	
	Student1.AddCourse("IT Fundmentals", 3, 88);
	Student1.AddCourse("Physics 2", 3, 92);
	Student1.AddCourse("Math 1", 3, 79);
	Student1.AddCourse("Electronics", 3, 96);
	Student1.AddCourse("English", 2, 89);
	Student1.AddCourse("Computer Law", 2, 95);
	Student1.AddCourse("History", 2, 89);

	Student1.CalculateGPA();

	cout << "GPA: " << Student1.GPA() << endl;



}
