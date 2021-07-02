#ifndef DYNARRAY_H
#define DYNARRAY_H

#define MAX_ARR 65
#include "Student.h"

class DynArray
{
  public:
    DynArray();
    ~DynArray();
    void add(Student*);
    void print();
    bool find(string,Student**);

  private:
    Student** elements;
    int   size;
};

#endif
