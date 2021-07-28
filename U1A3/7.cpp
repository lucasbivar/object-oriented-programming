#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

void toLowercase(string&);

int main(){

  string phrase = "ENGENHARIA DE COMPUTACAO";
  cout << "NORMAL : " << phrase << endl;

  toLowercase(phrase);
  cout << "MINUSCULA : " << phrase << endl;

  return 0;
}

void toLowercase(string& str){
  for(auto &c: str){
    c = tolower(c);
  }
}