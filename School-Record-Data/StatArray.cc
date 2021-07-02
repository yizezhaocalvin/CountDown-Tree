#include <iostream>
using namespace std;
#include<string>
#include "StatArray.h"


//statically allocated array of Course pointers
StatArray::StatArray()
{
  size = 0;
}

StatArray::~StatArray()
{
  for (int i=0; i<size; ++i)
    delete (elements[i]);
}

//add the given course to the array in its correct place, in ascending (increasing) order
void StatArray::add(Course* c)
{
  if (size == MAX_ARR){
    cout<<"Over the MAX_ARR"<<endl;
    return;
  }
  if(size<MAX_ARR){
      ++size;
      elements[size-1]=c;
      for(int i = 0; i<size-1; ++i){
        if(elements[i]->lessThan(c)){
          continue;
        }else{
          for(int j=size-1;j>i;--j){
            elements[j]=elements[j-1];
          }
          elements[i]=c;
          break;
          }
      }
  }
  if(size>MAX_ARR){
    cout<<"Over the MAX_ARR"<<endl;
  }
}

//searches the array to find the course with the identifier indicated in the id parameter, and returns the corresponding course in the c parameter
bool StatArray::find(int id, Course** c)
{

  for(int i=0; i<size;++i){
    if(elements[i]->getId()==id){
      *c=elements[i];
       return true;
    }
  }
  *c=NULL;
  return false;
}

void StatArray::print()
{
  for(int i=0;i<size;++i){
    elements[i]->print();
  }
}
