#include <sstream>
#include <iomanip>

#include "ReportGenerator.h"

UnemploymentReportGenerator::UnemploymentReportGenerator(int inId, string strName) {
  id=inId;
  name=strName;
}

//Unemployment percentage by MalesFemales, All, all years, all regions
void UnemploymentReportGenerator::execute(string& outStr) {
  stringstream ss;
  ss << "Unemployment Males, Females and All in Canada Report" << endl;
  string region;
  ss << std::setw(21) <<"Males" << std::setw(10) << "Females" << std::setw(4) << "All" << endl;
  for (int i = 0; i < allDegrees.size(); ++i) {
    Property<string>* property = allDegrees[i];
    ss << property->getValue() << ": ";

      int totalMaleEmployed = 0;
      int totalMaleGradsInCanada = 0;
      int totalFemaleEmployed = 0;
      int totalFemaleGradsInCanada = 0;
      int totalAllEmployed = 0;
      int totalAllGradsInCanada = 0;
      for (int j = 0; j < property->getRecordSize(); ++j) {
        Record* record = (*property)[j];

        if (record->getGender() == "Males") {
          totalMaleEmployed += record->getNumEmployed();
          totalMaleGradsInCanada += record->getNumGrads();
        }
        if (record->getGender() == "Females") {
          totalFemaleEmployed += record->getNumEmployed();
          totalFemaleGradsInCanada += record->getNumGrads();
        }
        if (record->getGender() == "All") {
          totalAllEmployed += record->getNumEmployed();
          totalAllGradsInCanada += record->getNumGrads();
        }
      }

      float rateMales = 1-((float) totalMaleEmployed / totalMaleGradsInCanada);
      float rateFemales = 1-((float) totalFemaleEmployed / totalFemaleGradsInCanada);
      float rateAll = 1-((float) totalAllEmployed / totalAllGradsInCanada);

      ss << "\t"  << setprecision(4) << rateMales*100 << "%";
      ss << "\t"  << setprecision(4) << rateFemales*100 << "%";
      ss << "\t"  << setprecision(4) << rateAll*100 << "%" << endl;
  }
  outStr = ss.str();
}
