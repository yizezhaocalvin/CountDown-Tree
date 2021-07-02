#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "View.h"

class Control
{
  public:
    Control();
    void initStudents(School*);
    void initCourses(School*);
    void launch();

  private:
    School s;
    View view;

};

#endif
