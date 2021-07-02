#include <sstream>
#include <iomanip>

#include "ReportGenerator.h"

YearReportGenerator::YearReportGenerator(int inId, string strName) {
  id=inId;
  name=strName;
}

//the employment proportion for each region, by year, for all degrees and all genders
void YearReportGenerator::execute(string& outStr) {
  stringstream ss;
  ss << "Year Report" << endl;
  int year;

  for (int d = 0; d < allYears.size(); ++d) {
    year = allYears[d]->getValue();
    ss << std::setw(17) << year;
  }
  ss << endl;

  for (int i = 0; i < allRegions.size(); ++i) {
    Property<string>* property = allRegions[i];
    ss << std::fixed << std::setw(3) << property->getValue() << "";
    for (int k = 0; k < allYears.size(); ++k) {
      year = allYears[k]->getValue();

      int totalEmployed = 0;
      int totalEmployedInCanada = 0;
      for (int j = 0; j < property->getRecordSize(); ++j) {
        Record* record = (*property)[j];
        if (record->getGender() == "All" && record->getYear() == year) {
          totalEmployed += record->getNumEmployed();
          totalEmployedInCanada += record->getNumGrads();

        }
      }
      float rate = (float) totalEmployed / totalEmployedInCanada;
      ss << std::fixed << std::setw(15) << setprecision(2) << rate*100.00 << "%" << "";
    }

    ss << endl;
  }
  outStr = ss.str();
}
