#include "Tool.hpp"  

#include <string>
using std::string;

#include <iostream>
using std::endl;
using std::cout;
using std::left;
using std::fixed;
using std::defaultfloat;

#include <iomanip>
using std::setw;

Tool::Tool(int entry, string name, int quantity, double price){
	this->setEntry(entry);
  this->setName(name);
  this->setQuantity(quantity);
  this->setPrice(price);
}

int Tool::getEntry() const {
  return entry; 
}

void Tool::setEntry(int entry){
  this->entry = entry;
}

string Tool::getName() const {
  return name;
}

void Tool::setName(string name){
  this->name = name;
}

int Tool::getQuantity() const {
  return quantity;
}

void Tool::setQuantity(int quantity){
  this->quantity = quantity < 0 ? 0 : quantity;
}

double Tool::getPrice() const {
  return price;
}

void Tool::setPrice(double price) {
  this->price = price < 0 ? 0 : price;
}

ostream& operator<<(ostream& out, const Tool& tool) {
  out << left << fixed;
  out.precision(2);
  out << setw(5) << tool.getEntry() << " | " << setw(25) << tool.getName() << " | "
    << setw(8) << tool.getQuantity() << " | " << setw(8) << tool.getPrice() << endl;
    
  out << defaultfloat;

  return out;
}
