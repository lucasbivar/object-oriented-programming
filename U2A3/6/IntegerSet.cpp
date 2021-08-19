#include "IntegerSet.h"

#include <cstring>
using std::memset;

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

IntegerSet::IntegerSet(){
  memset(set, 0, sizeof(set));
}

IntegerSet::IntegerSet(const int arr[], const int size){
  memset(set, 0, sizeof(set));

  for(int i = 0; i < size; i++){
    if(arr[i] >= 0 && arr[i] < 100){
      (*this)<<arr[i];
    }
  }
}

void IntegerSet::operator<<(int number){
  if(number >= 0 && number < 100){
    this->set[number] = true;
  }
}

void IntegerSet::operator>>(int number){
  if(number >= 0 && number < 100){
    this->set[number] = false;
  }
}

IntegerSet& IntegerSet::operator|(const IntegerSet &otherSet) const {
  IntegerSet *newSet = new IntegerSet();

  for(int i = 0; i < 100; i++){
    if(this->set[i] || otherSet.set[i]){
      newSet->set[i] = true;
    }
  }

  return *newSet;
}

IntegerSet& IntegerSet::operator&(const IntegerSet &otherSet) const{
  IntegerSet *newSet = new IntegerSet();

  for(int i = 0; i < 100; i++){
    if(this->set[i] && otherSet.set[i]){
      newSet->set[i] = true;
    }
  }

  return *newSet;
}


ostream& operator<<(ostream& out, const IntegerSet& integerSet){
  for(int i = 0; i < 100; i++){
    if(integerSet.set[i]){
      cout << i << " ";
    }
  }
  cout << endl;
  return out;
}