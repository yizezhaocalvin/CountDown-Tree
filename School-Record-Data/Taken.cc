#include <iostream>
#include <iomanip>
using namespace std;
#include "Taken.h"
#include "Student.h"
#include "Course.h"

//takes a student pointer, a course pointer, and a grade as parameters, and initializes all the data members
Taken::Taken(Student* stu,Course* cors, string g)
  : stuTaknCors(stu), corsTaknStu(cors), grade(g)
{}

//a getter function for the Student pointer
Student* Taken::getStuPointer()
{
  return stuTaknCors;
}

//a getter function for the Course pointer
Course* Taken::getCosePointer()
{
  return corsTaknStu;
}

//prints to the screen the corresponding student’s name, the concatenated course code (subject and code), and the grade earned
void Taken::print()
{
  cout<<stuTaknCors->getName()<<setw(20)<<corsTaknStu->getCourseCode()<<setw(5)<<grade<<endl;
}
