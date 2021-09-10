#ifndef TOOL_H
#define TOOL_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;
	
class Tool {
  friend ostream& operator<<(ostream&, const Tool&);
public:
	Tool(int=0, string="", int=0, double=0);

	int getEntry() const;
  void setEntry(int);

  string getName() const;
  void setName(string);

  int getQuantity() const;
  void setQuantity(int);

  double getPrice() const;
  void setPrice(double);

private:
	int entry;
  string name;
  int quantity;
  double price;
};

#endif