#include <sstream>

#include "ReportGenerator.h"

GradsReportGenerator::GradsReportGenerator(int inId, string strName) {
  id=inId;
  name=strName;
}

//numGrads for each year, by region, all genders, all degrees
void GradsReportGenerator::execute(string& outStr) {
  stringstream ss;
  ss << "Grads Report" << endl;
  string region;
  ss << "      ";
  for (int d = 0; d < allRegions.size(); ++d) {
    region = allRegions[d]->getValue();
    ss << "   " << region << "   ";
  }
  ss << endl;

  for (int i = 0; i < allYears.size(); ++i) {
    Property<int>* property = allYears[i];
    ss << property->getValue() << ":";
    for (int k = 0; k < allRegions.size(); ++k) {
      region = allRegions[k]->getValue();

      int totalGrads = 0;
      for (int j = 0; j < property->getRecordSize(); ++j) {
        Record* record = (*property)[j];
        if (record->getGender() == "All" && record->getRegion() == region) {
          totalGrads += record->getNumGrads();
        }
      }
      ss << "\t"<< totalGrads;
    }
    ss << endl;
  }
  outStr = ss.str();
}
