#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <vector>
using namespace std;

#include "Record.h"

/*
This class is a collection of Property object pointers, where Property is declared as a class template that is specialized for the
data type of that property.

operator += that adds a new element to the back of the record collection
operator [] that returns the record pointer at the given index
*/

template <typename T>
class Property
{
  public:
    Property(T);
    T getValue();

    void operator+=(Record*);
    Record* operator[](int);

    int getRecordSize();

  private:
    T value;
    vector<Record*> records;

};

template <typename T>
Property<T>::Property(T v) {
  value = v;
}

template <typename T>
T Property<T>::getValue() {
  return value;
}

template <typename T>
int Property<T>::getRecordSize() {
  return records.size();
}

template <typename T>
Record* Property<T>::operator[](int index) {
  if (index < 0 || index >= records.size()) {
    cout << "ERROR:  invalid index: " << index << endl;
    return NULL;
  }

  return records[index];
}

template <typename T>
void Property<T>::operator+=(Record* record) {
  records.push_back(record);
}
#endif
