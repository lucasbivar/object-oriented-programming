#ifndef TOOL_H
#define TOOL_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;
	
class Tool {
  friend ostream& operator<<(ostream&, const Tool&);
public:
	Tool(int=0, const char* ="", int=0, double=0);

	int getEntry() const;
  void setEntry(int);

  const char* getName() const;
  void setName(const char*);

  int getQuantity() const;
  void setQuantity(int);

  double getPrice() const;
  void setPrice(double);

private:
	int entry;
  char name[70];
  int quantity;
  double price;
};

#endif