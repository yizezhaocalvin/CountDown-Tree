#include <iostream>
using namespace std;

#include "School.h"

//default constructor that takes a school name as parameter, and initializes all the data members
School::School(string schoolName)
  :name(schoolName)
{
  numTaken=0;
}

// destructor that deallocates the required dynamically allocated objects
School::~School()
{
  for(int i=0;i<numTaken;++i){
    delete (collStuCors[i]);
  }
}

//adds the given student to the student collection
void School::addStu(Student* stu)
{
  collectStu.add(stu);
}

// adds the given course to the course collection
void School::addCourse(Course* c)
{
  collectCors.add(c);
}

//find the student object with the given student number and the course object with the given course id
//create a new Taken object with the found student and course objects, and with the given grade
//add the new object to the back of the Taken collection
void School::addTaken(string stuNum,int courseId,string grade)
{

  if(numTaken<MAX_ARR){
    Student* s1;
    Course* c1;
    if(collectStu.find(stuNum,&s1)){
      if(collectCors.find(courseId,&c1)){
        Taken* t1= new Taken(s1,c1,grade);
           collStuCors[numTaken]=t1;
           ++numTaken;
      }else
      {cout<<"Course is not find"<<endl;}

    }else{cout<<"Student is not find"<<endl;}

    // if(collectStu.find(stuNum,&s1) && collectCors.find(courseId,&c1)){
    //   Taken* t1= new Taken(s1,c1,grade);
    //   collStuCors[numTaken]=t1;
    //   ++numTaken;
    //   //delete t1;
    // }else if (collectStu.find(stuNum,&s1)==false){
    //   cout<<"Student is not find"<<endl;
    //  }else if (collectCors.find(courseId,&c1)==false){
    //    cout<<"Course is not find"<<endl;
    //  }
  }else{
  cout<<"Over MAX_ARR"<<endl;
  }
}

//prints all the students in the student collection
void School::printStudents()
{
  cout<<endl;
  collectStu.print();
  cout<<endl;
}

//prints all the courses in the course collection
void School::printCourses()
{
  cout<<endl;
  collectCors.print();
  cout<<endl;
}

//prints all the Taken objects in the collection
void School::printTaken()
{
  if(numTaken==0){
    cout<<"No student be added"<<endl;
  }

  for(int i=0;i<numTaken;++i){
    cout<<"Taken: ";
    collStuCors[i]->print();
  }
}

// prints the full course information for every course taken by the
//given student, along with the grade earned by the student in that course
void School::printTakenByStu(string stuId)
{
  if(numTaken==0){
    cout<<"No student be added"<<endl;
  }

  for(int i=0;i<numTaken;++i){
    if(collStuCors[i]->getStuPointer()->getStuNumber()==stuId){
      cout<<"Carleton U. School of Computer Science === TAKEN BY:"<<collStuCors[i]->getStuPointer()->getName()<<endl;
      collStuCors[i]->getCosePointer()->print();
      cout<<"Taken: ";
      collStuCors[i]->print();
      cout<<endl;
    }else{
      cout<<"Student id is not found"<<endl;
    }
  }

}
