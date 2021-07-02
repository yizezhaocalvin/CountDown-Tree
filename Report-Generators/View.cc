#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice) {
    cout << endl << endl;
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

void View::readInt(int& n) {
  cin >> n;
}

void View::printLine(string& s) {
  cout << s << endl;
}
