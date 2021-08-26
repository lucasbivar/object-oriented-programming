#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class HugeInteger{
  friend ostream& operator<<(ostream&, const HugeInteger&);
public:
  HugeInteger(string="");

  const HugeInteger& operator=(const string&);

  const HugeInteger operator+(const HugeInteger&) const;
  const HugeInteger& operator+=(const HugeInteger&);

  bool operator==(const HugeInteger&) const;
  bool operator!=(const HugeInteger&) const;

  bool operator>(const HugeInteger&) const;
  bool operator<(const HugeInteger&) const;

  bool operator>=(const HugeInteger&) const;
  bool operator<=(const HugeInteger&) const;

private:
  void setNumber(const string);
  char number[40];
  int size;
};

#endif
