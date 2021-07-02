#ifndef RECORD_H
#define RECORD_H

/*
  a class to hold each record read in from the data file
  a class to contain the information for each individual record
*/

class Record
{
  public:
    Record(int=0, string="Null", string="Null", string="Null", int=0, int=0);
    ~Record();
    int    getYear()   const;
    string getRegion() const;
    string getDegree() const;
    string getGender() const;
    int    getNumGrads()    const;
    int    getNumEmployed() const;

  private:
    int    year;
    string region;
    string degree;
    string gender;
    int    numGrads;
    int    numEmployed;
};

#endif
