#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Student.h"


Student::Student(string s1, string s2, string s3, float g)
  : number(s1), name(s2), majorPgm(s3), gpa(g)
{
  //cout<<"-- Student ctor:  "<< s2 <<endl;
}

Student::~Student()
{
  // cout<<"-- Student dtor:  "<< name <<endl;
}

string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }
string Student::getStuNumber() const {return number;}

//This function compares the student on the left-hand side (the this student) with the student passed in as the parameter; a student is considered “less than” another if their name comes first in alphabetical order;
//using the string class less-than operator for this
bool Student::lessThan(Student* stu)
{
  if(this->name < stu->getName()){
    return true;
  }else{
    return false;
  }
}

void Student::print() const
{
  cout<<"Student:  " << number << "  " << left << setw(10) << name << " "
                     << setw(15) << majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << gpa << endl;
}
