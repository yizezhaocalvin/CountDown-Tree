#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#include "Record.h"
#include "Property.h"

/*
In this class, it has four records, , allYears, allRegions, allDegrees to,
allRecords--> store all the data from file
allYears --> store all the year properties
allRegions---> store all the regions properties
allDegrees ---> store all the degrees properties

four add functions in order to add them into their own property

three get functions in order to check if this year, region, degree exit or not.

cleanup funciton in order to deallocte all the memery used

there five class inherit the base class ReportGenerator
*/

class ReportGenerator
{
  public:
    static vector<Record*> allRecords;
    static vector<Property<int>*> allYears;
    static vector<Property<string>*> allRegions;
    static vector<Property<string>*> allDegrees;

    static void addRecord(Record*);
    static void addYearProperty(Property<int>*);
    static void addRegionProperty(Property<string>*);
    static void addDegreeProperty(Property<string>*);

    static Property<int>* getYearProperty(int);
    static Property<string>* getRegionProperty(string&);
    static Property<string>* getDegreeProperty(string&);

    static void cleanup();

    string getName();
    int getId();

    virtual void execute(string& outStr) = 0;

  protected:
    int id;
    string name;
};

class RegionReportGenerator : public ReportGenerator
{
  public:
    RegionReportGenerator(int id, string name);
    virtual void execute(string& outStr);
};

class FemaleReportGenerator : public ReportGenerator
{
  public:
    FemaleReportGenerator(int id, string name);
    virtual void execute(string& outStr);
};

class YearReportGenerator : public ReportGenerator
{
  public:
    YearReportGenerator(int id, string name);
    virtual void execute(string& outStr);
};

class UnemploymentReportGenerator : public ReportGenerator
{
  public:
    UnemploymentReportGenerator(int id, string name);
    virtual void execute(string& outStr);
};

class GradsReportGenerator : public ReportGenerator
{
  public:
    GradsReportGenerator(int id, string name);
    virtual void execute(string& outStr);
};



#endif
