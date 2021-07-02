#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course
{
  public:
    Course(int, string, int, char, string, string);
    int getId();
    string getCourseCode();
    bool lessThan(Course*);
    void print();

  private:
    int id;
    string subject;
    int code;
    char section;
    string term;
    string instructor;
};
#endif
