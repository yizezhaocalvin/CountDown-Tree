#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Record.h"

Record::Record(int i1, string s1, string s2, string s3, int i2, int i3)
    : year(i1), region(s1), degree(s2), gender(s3), numEmployed(i2), numGrads(i3){}

Record::~Record() {}

int Record::getYear() const {
  return year;
}

string Record::getRegion() const {
  return region;
}

string Record::getDegree() const {
  return degree;
}

string Record::getGender() const {
  return gender;
}

int Record::getNumGrads() const {
  return numGrads;
}

int Record::getNumEmployed() const {
  return numEmployed;
}
