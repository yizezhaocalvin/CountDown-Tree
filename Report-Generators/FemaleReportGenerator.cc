#include <sstream>
#include <iomanip>

#include "ReportGenerator.h"

FemaleReportGenerator::FemaleReportGenerator(int inId, string strName) {
  id=inId;
  name=strName;
}

//the top 3 and bottom 3 regions for percentage of female graduates, for all years and all degrees
void FemaleReportGenerator::execute(string& outStr) {
  stringstream ss;
  ss << "Female Graduates Report" << endl;
  ss << endl;
  string degree;
  string region;
  string top1Region = "";
  string top2Region = "";
  string top3Region = "";
  string bottom1Region = "";
  string bottom2Region = "";
  string bottom3Region = "";

  float top1Rate = 0.0f;
  float top2Rate = 0.0f;
  float top3Rate = 0.0f;
  float bottom1Rate = 1.0f;
  float bottom2Rate = 1.0f;
  float bottom3Rate = 1.0f;

  for (int i = 0; i < allRegions.size(); ++i) {
    Property<string>* property = allRegions[i];
    region = property->getValue();
    int totalFemalesGrades = 0;
    int totalGrads = 0;
    for (int j = 0; j < property->getRecordSize(); ++j) {
      Record* record = (*property)[j];
      if (record->getGender() == "Females") {
        totalFemalesGrades += record->getNumGrads();
      }
      if (record->getGender() == "All") {
        totalGrads += record->getNumGrads();
      }
    }
    float rate = (float) totalFemalesGrades / totalGrads;
    if (rate > top1Rate) {
      top3Rate = top2Rate;
      top3Region = top2Region;

      top2Rate = top1Rate;
      top2Region = top1Region;

      top1Rate = rate;
      top1Region = region;
    } else if (rate > top2Rate) {
      top3Rate = top2Rate;
      top3Region = top2Region;

      top2Rate = rate;
      top2Region = region;
    } else if (rate > top3Rate) {
      top3Rate = rate;
      top3Region = region;
    }
    
    if (rate < bottom1Rate) {
      bottom3Rate = bottom2Rate;
      bottom3Region = bottom2Region;

      bottom2Rate = bottom1Rate;
      bottom2Region = bottom1Region;

      bottom1Rate = rate;
      bottom1Region = region;
    } else if (rate < bottom2Rate) {
      bottom3Rate = bottom2Rate;
      bottom3Region = bottom2Region;

      bottom2Rate = rate;
      bottom2Region = region;
    } else if (rate < bottom3Rate) {
      bottom3Rate = rate;
      bottom3Region = region;
    }
  }

  ss << "Top 3: the proportion of female graduates, compared to the total number of graduates in specific region" << endl;
  ss << top1Region << "  " << "\t" << setprecision(4) << top1Rate*100 << "%" << "  " << endl;
  ss << top2Region << "  " << "\t" << setprecision(4) << top2Rate*100 << "%" << "  " << endl;
  ss << top3Region << "  " << "\t" << setprecision(4) << top3Rate*100 << "%" << "  " << endl;
  ss << endl;
  ss << "Bottom 3: the proportion of female graduates, compared to the total number of graduates in specific region" << endl;
  ss << bottom1Region << "  " << "\t" << setprecision(4) << bottom1Rate*100 << "%" << "  " << endl;
  ss << bottom2Region << "  " << "\t" << setprecision(4) << bottom2Rate*100 << "%" << "  " << endl;
  ss << bottom3Region << "  " << "\t" << setprecision(4) << bottom3Rate*100 << "%" << "  " << endl;

  outStr = ss.str();
}
