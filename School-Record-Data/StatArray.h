#ifndef STATARRAY_H
#define STATARRAY_H

#define MAX_ARR 65

#include "Course.h"

class StatArray
{
  public:
    StatArray();
    ~StatArray();
    void add(Course*);
    void print();
    bool find(int,Course**);

  private:
    Course* elements[MAX_ARR];
    int   size;
};

#endif
