#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control()
{
  initStudents(&s);
  initCourses(&s);
}
void Control::launch()
{
  int choice;
  while (1) {
    view.showMenu(choice);
    if (choice == 0)
      break;

//  Print students
    if (choice == 1) {
      s.printStudents();
    }
//  Print courses
    if (choice == 2) {
      s.printCourses();
    }
//  Print courses taken
    if (choice == 3) {
      cout<<"Carleton U. School of Computer Science === TAKEN:"<<endl;
      s.printTaken();
    }
//  Print courses taken by student
    if (choice == 4) {
      string stuId;
      cout<<"please enter student id: ";
      view.readStr(stuId);
      cout<<endl;
      s.printTakenByStu(stuId);
    }
//  Add course taken by student
    if (choice == 5) {
      string stuId;
      int CourseId;
      string grade;
      cout<<"please enter student id: ";
      view.readStr(stuId);
      cout<<"please enter course id: ";
      view.readInt(CourseId);
      cout<<"please enter grade: ";
      view.readStr(grade);
      s.addTaken(stuId,CourseId,grade);
    }
  }
}

void Control::initStudents(School* sch)
{
  sch->addStu(new Student("100567888", "Matilda", "CS", 9.0f));
  sch->addStu(new Student("100333444", "Harold", "Geography", 7.5f));
  sch->addStu(new Student("100444555", "Joe", "Physics", 8.3f));
  sch->addStu(new Student("100775588", "Timmy", "CS", 11.5f));
  sch->addStu(new Student("100111222", "Amy", "Math", 10.8f));
  sch->addStu(new Student("100222333", "Stanley", "Art History", 6.7f));
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course(65001, "COMP", 3004, 'B', "W20", "Baysal"));
  sch->addCourse(new Course(65002, "COMP", 3004, 'A', "W20", "Radonjic"));
  sch->addCourse(new Course(65003, "COMP", 2404, 'B', "W20", "Laurendeau"));
  sch->addCourse(new Course(65004, "COMP", 2404, 'A', "W20", "Laurendeau"));
  sch->addCourse(new Course(65005, "MATH", 1104, 'A', "F19", "Fodden"));
  sch->addCourse(new Course(65006, "MATH", 1104, 'B', "F19", "Fodden"));

  sch->addCourse(new Course(65007, "COMP", 2404, 'A', "F20", "Laurendeau"));

  sch->addCourse(new Course(65008, "COMP", 1405, 'B', "W20", "Runka"));
  sch->addCourse(new Course(65009, "COMP", 1406, 'B', "W20", "McKenney"));
  sch->addCourse(new Course(65010, "COMP", 1406, 'C', "W20", "McKenney"));
  sch->addCourse(new Course(65011, "COMP", 1406, 'A', "W20", "McKenney"));

  sch->addCourse(new Course(65012, "MATH", 1104, 'C', "W20", "Abdulrahman"));
  sch->addCourse(new Course(65013, "MATH", 1104, 'D', "W20", "Lemire"));

  sch->addCourse(new Course(65014, "COMP", 1406, 'A', "F19", "Hill"));

  sch->addCourse(new Course(65015, "COMP", 1405, 'B', "F19", "McKenney"));
  sch->addCourse(new Course(65016, "COMP", 1405, 'A', "F19", "Collier"));
  sch->addCourse(new Course(65017, "COMP", 1405, 'D', "F19", "Runka"));
  sch->addCourse(new Course(65018, "COMP", 1405, 'C', "F19", "Runka"));

  sch->addCourse(new Course(65019, "COMP", 2404, 'B', "F19", "Nel"));
}
