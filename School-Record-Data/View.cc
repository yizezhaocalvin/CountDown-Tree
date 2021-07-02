#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print students" << endl;
  cout << "  (2) Print courses" << endl;
  cout << "  (3) Print all courses taken" << endl;
  cout << "  (4) Print courses taken by student" << endl;
  cout << "  (5) Add course taken by student" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 5) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}
