#include "HugeInteger.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring>
using std::memset;

HugeInteger::HugeInteger(string number){
  this->setNumber(number);
}

const HugeInteger& HugeInteger::operator=(const string& number){
  this->setNumber(number);
  return (*this);
}

void HugeInteger::setNumber(const string num){
  memset(number, '0', sizeof(number));

  size = num.size();
  if(size == 0){
    size = 1;
  }

  for(int i = num.size()-1; i >= 0; i--){
    if(!isdigit(num[i])){
      memset(number, '0', sizeof(number));
      size = 1;
      break;
    }
    number[i] = num[num.size()-1-i];
  }
}

ostream& operator<<(ostream& out, const HugeInteger& number){
  for(int i = number.size-1; i >= 0; i--){
    cout << number.number[i];
  }
  cout << endl;
  return out;
}

const HugeInteger HugeInteger::operator+(const HugeInteger& other) const {
  int greaterSize = this->size > other.size ? this->size : other.size;
  int currentSum, carry = 0;

  HugeInteger newHugeInteger = HugeInteger();
  newHugeInteger.size = greaterSize;
 
  for(int i = 0; i < greaterSize; i++){
    currentSum = (this->number[i]-'0') + (other.number[i]-'0') + carry;

    if(currentSum > 9){
      newHugeInteger.number[i] = '0' + (currentSum % 10);
      currentSum /= 10;
      carry = currentSum;
    }else{
      newHugeInteger.number[i] = '0' + currentSum;
      carry = 0;
    }
  }
  if(carry != 0){
    newHugeInteger.number[newHugeInteger.size++] = '0' + carry;
  }

  return newHugeInteger;
}

const HugeInteger& HugeInteger::operator+=(const HugeInteger& other){
  *this = *this + other;
  return *this;
}

bool HugeInteger::operator==(const HugeInteger& other) const{
  if(size != (int) other.size) return false;

  for(int i = size-1; i > 0; i--){
    if(number[i] != other.number[i]) return false;
  }

  return true;
}

bool HugeInteger::operator!=(const HugeInteger& other) const {
  return !(*this == other);
}

bool HugeInteger::operator>(const HugeInteger& other) const {
  if(size > other.size) return true;
  if(size < other.size) return false;

  for(int i = size-1; i >= 0; i--){
    if(static_cast<int>(number[i]) > static_cast<int>(other.number[i])){
      return true;
    }else if(static_cast<int>(number[i]) < static_cast<int>(other.number[i])){
      return false;
    }
  }

  return false;
}

bool HugeInteger::operator<(const HugeInteger& other) const {
  if(size > other.size) return false;
  if(size < other.size) return true;

  for(int i = size-1; i >= 0; i--){
    if(static_cast<int>(number[i]) > static_cast<int>(other.number[i])){
      return false;
    }else if(static_cast<int>(number[i]) < static_cast<int>(other.number[i])){
      return true;
    }
  }

  return false;
}

bool HugeInteger::operator>=(const HugeInteger& other) const {
  return ((*this == other) || (*this > other)) ? true : false;
}

bool HugeInteger::operator<=(const HugeInteger& other) const {
  return ((*this == other) || (*this < other)) ? true : false;
}