#ifndef STUDENT_H
#define STUDENT_H
class Taken;
class DynArray;

class Student
{
  public:
    Student(string="000000000", string="Hey you!", string="basket-weaving", float=0.0f);
    ~Student();
    string getName() const;
    string getStuNumber()const;
    void setName(string);
    void print() const;
    bool lessThan(Student*);

  private:
    const string number;
    string name;
    string majorPgm;
    float  gpa;
};

#endif
