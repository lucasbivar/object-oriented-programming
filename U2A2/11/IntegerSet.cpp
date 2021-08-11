#include "IntegerSet.h"

#include <cstring>
using std::memset;

#include <iostream>
using std::cout;
using std::endl;

IntegerSet::IntegerSet(){
  memset(set, 0, sizeof(set));
}

IntegerSet::IntegerSet(const int arr[], const int size){
  memset(set, 0, sizeof(set));

  for(int i = 0; i < size; i++){
    if(arr[i] >= 0 && arr[i] < 100){
      insertElement(arr[i]);
    }
  }
}

void IntegerSet::insertElement(const int k){
  if(k >= 0 && k < 100){
    set[k] = true;
  }
}
void IntegerSet::deleteElement(const int k){
  if(k >= 0 && k < 100){
    set[k] = false;
  }
}

void IntegerSet::print() const {
  for(int i = 0; i < 100; i++){
    if(set[i]){
      cout << i << " ";
    }
  }
  cout << endl;
};

IntegerSet& unionOfSets(const IntegerSet& set1, const IntegerSet& set2){
  IntegerSet *newSet = new IntegerSet();
  for(int i = 0; i < 100; i++){
    if(set1.set[i] || set2.set[i]){
      newSet->insertElement(i);
    }
  }
  return *newSet;
}

IntegerSet& intersectionOfSets(const IntegerSet& set1, const IntegerSet& set2){
  IntegerSet *newSet = new IntegerSet();
  for(int i = 0; i < 100; i++){
    if(set1.set[i] && set2.set[i]){
      newSet->insertElement(i);
    }
  }
  return *newSet;
}