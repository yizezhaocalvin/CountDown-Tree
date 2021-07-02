#include <iostream>
#include <fstream>

#include "Control.h"

Control::Control() {}

void Control::loadRecords() {
  int    year, numEmployed, numGrads;
  string region, degree, gender;

  //readIn all the data from the file
  ifstream infile("grad.dat", ios::in);

  if (!infile) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }
  while ( infile >> year >> region >> degree >> gender >> numEmployed >> numGrads ) {
    Record* rec = new Record(year, region, degree, gender, numEmployed, numGrads);

    // add to all records
    ReportGenerator::addRecord(rec);

    // add to year property
    Property<int>* yearProperty = ReportGenerator::getYearProperty(year);
    if(yearProperty == NULL) {
      yearProperty = new Property<int>(year);
      ReportGenerator::addYearProperty(yearProperty);
    }
    *yearProperty += rec;

    // add to region property
    Property<string>* regionProperty = ReportGenerator::getRegionProperty(region);
    if(regionProperty == NULL) {
      regionProperty = new Property<string>(region);
      ReportGenerator::addRegionProperty(regionProperty);
    }
    *regionProperty += rec;

    //add to degree property
    Property<string>* degreeProperty = ReportGenerator::getDegreeProperty(degree);
    if(degreeProperty == NULL) {
      degreeProperty = new Property<string>(degree);
      ReportGenerator::addDegreeProperty(degreeProperty);
    }
    *degreeProperty += rec;
  }
}

//create the reports
void Control::initGenerators() {
  ReportGenerator* regionRG = new RegionReportGenerator(1, "Region Report: Employment percentage by degree, all years, all genders");
  ReportGenerator* femaleRG = new FemaleReportGenerator(2, "Female Grads Report: Top 3 and Bottom 3 regions, all years, all degrees");
  ReportGenerator* yearRG   = new YearReportGenerator(3,   "Year Report: Employment percentage for regions for all genders, all years");
  ReportGenerator* unemploymentMaleRG  = new UnemploymentReportGenerator(4, "Unemployment MalesFemales and All Report: Unemployment percentage by MalesFemales, All, all years, all regions");
  ReportGenerator* gradsRG   = new GradsReportGenerator(5, "numGrads Report: for each year, by region, all genders, all degrees");

  generators.push_back(regionRG);
  generators.push_back(femaleRG);
  generators.push_back(yearRG);
  generators.push_back(unemploymentMaleRG);
  generators.push_back(gradsRG);

}

ReportGenerator* Control::getGenerator(int id) {
  return generators[id-1];
}

void Control::cleanup() {
  // clean up records and properties
  ReportGenerator::cleanup();

  // clean up generators
  vector<ReportGenerator*>::iterator iter;
  for (iter = generators.begin(); iter != generators.end(); ++iter) {
    delete((*iter));
  }
}

void Control::run() {
  loadRecords();
  initGenerators();

  string report;
  string line;
  ReportGenerator* g;
  int choice;

  while (1) {
      line = "What would you like to do:";
      view.printLine(line);

      for (int i = 0; i < generators.size(); ++i) {           //using the id we created, not hard-coding 
        g = generators[i];
        line = "  (" + to_string(g->getId()) + ") - " + g->getName();
        view.printLine(line);
      }

      view.showMenu(choice);
      if (choice == 0) {
        break;
      }

      g = getGenerator(choice);
      g->execute(report);
      view.printLine(report);
  }
  cleanup();
}
