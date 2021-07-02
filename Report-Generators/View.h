#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*
In this class, showMenu() just show a little work for menu, the main part is coded in the report generators.
readIn() read int
printLine() print string
*/

class View
{
  public:
    void showMenu(int&);
    void readInt(int&);
    void printLine(string&);
};

#endif
