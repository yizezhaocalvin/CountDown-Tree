#include <sstream>
#include <iomanip>

#include "ReportGenerator.h"

RegionReportGenerator::RegionReportGenerator(int inId, string strName) {
  id=inId;
  name=strName;
}

//the employment percentage for each region, by degree, for all years and all genders
void RegionReportGenerator::execute(string& outStr) {
  stringstream ss;
  ss << "Region Report" << endl;
  string degree;
  ss << "\t";
  for (int d = 0; d < allDegrees.size(); ++d) {
    degree = allDegrees[d]->getValue();
    ss << std::fixed << std::setw(15) << degree;
  }
  ss << endl;

  for (int i = 0; i < allRegions.size(); ++i) {
    Property<string>* property = allRegions[i];
    ss << std::fixed << std::setw(3) << property->getValue() << "";
    for (int k = 0; k < allDegrees.size(); ++k) {
      degree = allDegrees[k]->getValue();

      int totalEmployed = 0;
      int totalGrads = 0;
      for (int j = 0; j < property->getRecordSize(); ++j) {
        Record* record = (*property)[j];
        if (record->getGender() == "All" && record->getDegree() == degree) {
          totalEmployed += record->getNumEmployed();
          totalGrads += record->getNumGrads();
        }
      }
      float rate = (float) totalEmployed / totalGrads;
      ss << std::fixed << std::setw(15) << setprecision(2) << rate*100.00 << "%" << "";
    }

    ss << endl;
  }
  outStr = ss.str();
}
