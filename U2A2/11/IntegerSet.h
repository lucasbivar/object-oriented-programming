#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet{
  friend IntegerSet& unionOfSets(const IntegerSet& , const IntegerSet&);
  friend IntegerSet& intersectionOfSets(const IntegerSet& , const IntegerSet&);
public:
  IntegerSet();
  IntegerSet(const int [], const int);
  
  void insertElement(int);
  void deleteElement(int);

  void print() const;
private:
  bool set[100];
};

#endif