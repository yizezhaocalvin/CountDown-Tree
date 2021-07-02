#include <iostream>
using namespace std;

#include "DynArray.h"


//a dynamically allocated array of Student pointers
DynArray::DynArray()
{
  size = 0;
  elements = new Student*[MAX_ARR];
}

DynArray::~DynArray()
{
  for (int i=0; i<size; ++i)
    delete (elements[i]);
  delete elements;
}

// add the given student to the array in its correct place, in ascending (increasing) order
void DynArray::add(Student* stu)
{
  if (size == MAX_ARR){
    cout<<"Over the MAX_ARR"<<endl;
    return;
  }
  if(size<MAX_ARR){
      ++size;
      elements[size-1]=stu;
      for(int i = 0; i<size-1; ++i){
        if(elements[i]->lessThan(stu)){
          continue;
        }else{
          for(int j=size-1;j>i;--j){
            elements[j]=elements[j-1];
          }
          elements[i]=stu;
          break;
          }
      }
  }
  if(size>MAX_ARR){
    cout<<"Over the MAX_ARR"<<endl;
  }
}

//searches the array to find the student with the number indicated in the num parameter, and returns the corresponding student in the stu parameter;
bool DynArray::find(string num, Student** stu)
{

  for(int i=0; i<size;++i){
    if(elements[i]->getStuNumber()==num){
      *stu=elements[i];
       return true;
    }
  }
  *stu=NULL;
  return false;
}


void DynArray::print()
{
  for(int i=0;i<size;++i){
    elements[i]->print();
  }
}
