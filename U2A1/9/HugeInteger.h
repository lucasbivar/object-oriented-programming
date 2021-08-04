#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <string>
using std::string;

class HugeInteger{
public:
  void input(const string);
  void output();

  void add(const HugeInteger&);

  bool isEqualTo(const HugeInteger&);
  bool isNotEqualTo(const HugeInteger&);

  bool isGreaterThan(const HugeInteger&);
  bool isLessThan(const HugeInteger&);

  bool isGreaterThanOriqual(const HugeInteger&);
  bool isLessThanOriqual(const HugeInteger&);

private:
  char number[40];
  int size;
};

#endif
