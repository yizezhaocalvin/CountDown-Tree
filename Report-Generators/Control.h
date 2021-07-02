#ifndef CONTROL_H
#define CONTROL_H

#include <vector>
#include "View.h"
#include "ReportGenerator.h"
#include "Property.h"
#include "Record.h"

/*
  This class is used to control everything in order to make them together
  loadRecords() is used to loadRecord from file
  initGenerators() create the id and name of the Report
  getGenerator() get the generators
*/

class Control
{
  public:
    Control();
    void run();

  private:
    vector<ReportGenerator*> generators;
    void loadRecords();
    void initGenerators();
    void cleanup();
    ReportGenerator* getGenerator(int);
    View view;

};

#endif
