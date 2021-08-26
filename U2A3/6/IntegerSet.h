#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <iostream>
using std::ostream;

class IntegerSet{
friend ostream& operator<<(ostream&, const IntegerSet&);
public:
  IntegerSet();
  IntegerSet(const int [], const int);

  void operator<<(int);
  void operator>>(int);

  IntegerSet operator|(const IntegerSet &) const;
  IntegerSet operator&(const IntegerSet &) const;

private:
  bool set[100];
};

#endif