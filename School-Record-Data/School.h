#ifndef SCHOOL_H
#define SCHOOL_H
#define MAX_ARR 65

#include "Taken.h"
#include "DynArray.h"
#include "StatArray.h"
#include "Student.h"

class Control;

class School
{
  public:
    School(string="My University");
    ~School();
    void addStu(Student*);
    void addCourse(Course*);
    void addTaken(string,int,string);
    void printStudents();
    void printCourses();
    void printTaken();
    void printTakenByStu(string);

  private:
    string name;
    DynArray collectStu;
    StatArray collectCors;
    Taken*  collStuCors[MAX_ARR];
    int numTaken;

};

#endif
