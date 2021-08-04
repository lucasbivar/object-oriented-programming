#include "HugeInteger.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring>
using std::memset;

void HugeInteger::input(const string num){
  memset(number, '0', sizeof(number));

  size = num.size();
  for(int i = num.size()-1; i >= 0; i--){
    if(!isdigit(num[i])){
      memset(number, '0', sizeof(number));
      size = 1;
      break;
    }
    number[i] = num[num.size()-1-i];
  }
}

void HugeInteger::output(){
  for(int i = size-1; i >= 0; i--){
    cout << number[i];
  }
  cout << endl;
}

void HugeInteger::add(const HugeInteger& other){
  int greaterSize = size > other.size ? size : other.size;
  int currentSum, carry = 0;

  for(int i = 0; i < greaterSize; i++){
    currentSum = (number[i]-'0') + (other.number[i]-'0') + carry;

    if(i >= size){
      size++;
    }

    if(currentSum > 9){
      number[i] = '0' + (currentSum % 10);
      currentSum /= 10;
      carry = currentSum;
    }else{
      number[i] = '0' + currentSum;
      carry = 0;
    }
  }
  if(carry != 0){
    number[size++] = '0' + carry;
  }
}

bool HugeInteger::isEqualTo(const HugeInteger& other){
  if(size != (int) other.size) return false;

  for(int i = size-1; i > 0; i--){
    if(number[i] != other.number[i]) return false;
  }

  return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& other){
  return !isEqualTo(other);
}

bool HugeInteger::isGreaterThan(const HugeInteger& other){
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

bool HugeInteger::isLessThan(const HugeInteger& other){
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

bool HugeInteger::isGreaterThanOriqual(const HugeInteger& other){
  return (isEqualTo(other) || isGreaterThan(other)) ? true : false;
}

bool HugeInteger::isLessThanOriqual(const HugeInteger& other){
  return (isEqualTo(other) || isLessThan(other)) ? true : false;
}