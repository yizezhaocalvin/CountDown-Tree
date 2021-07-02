#ifndef TAKEN_H
#define TAKEN_H
class Student;
class Course;
class Taken
{
  public:
    Taken(Student*,Course*,string grade);
    Student* getStuPointer();
    Course* getCosePointer();
    void print();

  private:
    Student* stuTaknCors;
    Course* corsTaknStu;
    string grade;
};

#endif
