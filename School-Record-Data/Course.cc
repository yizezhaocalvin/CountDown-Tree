#include <iostream>
using namespace std;
#include <string>
#include "Course.h"

//takes an identifier, a course subject, code, section, term, and instructor as parameters, and initializes all the data members
Course::Course(int id1, string sub1, int code1, char sec1, string term1, string ins1)
  : id(id1), subject(sub1), code(code1), section(sec1), term(term1), instructor(ins1)
{
  // cout<<"-- Course ctor:  "<< subject << id << section <<endl;
}

int Course::getId() { return id; }

//concatenates the course subject and code, and returns this value; for example, the value returned for this course would be “COMP2404”
string Course::getCourseCode()
{
  char s[99];
  sprintf(s,"%d",code);
  return subject+s;
}

//compares the course on the left-hand side (the this course) with the course passed in as the parameter; a course is considered “less than” another according to
//the following rules, applied sequentially
bool Course::lessThan(Course* c)
{
  if(this->subject<c->subject){
    return true;
  }else if (this->subject==c->subject){
    if(this->code<c->code){
      return true;
    }else if(this->code==c->code){
      if(this->term<c->term){
        return true;
      }else if(this->term==c->term){
        if(this->section<c->section){
          return true;
        }else if(this->section==c->section){
          return true;

        }return false;
      }return false;
    }return false;
  }return false;

}

void Course::print()
{
  cout<<"Course: "<<id<<" "<<subject<<" "<<code <<" "<<section <<" "<<"Term : "<<term<<" "<<"Instr: "<< instructor<<endl;
}
