#include <iterator>

#include "ReportGenerator.h"

vector<Record*> ReportGenerator::allRecords;
vector<Property<int>*> ReportGenerator::allYears;
vector<Property<string>*> ReportGenerator::allRegions;
vector<Property<string>*> ReportGenerator::allDegrees;

void ReportGenerator::cleanup() {
  vector<Property<string>*>::iterator iter;
  // clean up degree properties
  for (iter = allDegrees.begin(); iter != allDegrees.end(); ++iter) {
    delete((*iter));
  }

  // clean up region properties
  for (iter = allRegions.begin(); iter != allRegions.end(); ++iter) {
    delete((*iter));
  }

  // clean up year properties
  vector<Property<int>*>::iterator iterInt;
  for (iterInt = allYears.begin(); iterInt != allYears.end(); ++iterInt) {
    delete((*iterInt));
  }

  // clean up records
  vector<Record*>::iterator iterRecord;
  for (iterRecord = allRecords.begin(); iterRecord != allRecords.end(); ++iterRecord) {
    delete((*iterRecord));
  }
}

string ReportGenerator::getName() {
  return name;
}

int ReportGenerator::getId() {
  return id;
}

//add into allRecords
void ReportGenerator::addRecord(Record* r) {
  allRecords.push_back(r);
}

//add into year properties
void ReportGenerator::addYearProperty(Property<int>*p) {
  allYears.push_back(p);
}

//check if year is exist, if not return NULL, if exist return it
Property<int>* ReportGenerator::getYearProperty(int year) {
  vector<Property<int>*>::iterator iter;
  for (iter = allYears.begin(); iter != allYears.end(); ++iter) {
    if((*iter)->getValue() == year) {
      return (*iter);
    }
  }
  return NULL;
}

//add into region properties
void ReportGenerator::addRegionProperty(Property<string>*p) {
  allRegions.push_back(p);
}

//check if region is exist, if not return NULL, if exist return it
Property<string>* ReportGenerator::getRegionProperty(string& region) {
  vector<Property<string>*>::iterator iter;
  for (iter = allRegions.begin(); iter != allRegions.end(); ++iter) {
    if((*iter)->getValue() == region) {
      return (*iter);
    }
  }
  return NULL;
}

//add into degrees properties
void ReportGenerator::addDegreeProperty(Property<string>*p) {
  allDegrees.push_back(p);
}

//check if degree is exist, if not return NULL, if exist return it
Property<string>* ReportGenerator::getDegreeProperty(string& degree) {
  vector<Property<string>*>::iterator iter;
  for (iter = allDegrees.begin(); iter != allDegrees.end(); ++iter) {
    if((*iter)->getValue() == degree) {
      return (*iter);
    }
  }
  return NULL;
}
