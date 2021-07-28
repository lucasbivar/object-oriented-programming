#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

bool hasUppercase(const string&);

int main(){
  string phrase = "Engenharia de Computacao";
  cout << phrase << " - tem letra maiuscula? " << (hasUppercase(phrase) ? "sim" : "nao") << endl;

  phrase = "instituto federal da paraiba";
  cout << phrase << " - tem letra maiuscula? " << (hasUppercase(phrase) ? "sim" : "nao") << endl;

  return 0;
}

bool hasUppercase(const string &str){
  for(const auto &c: str){
    if(isupper(c)) return true;
  }

  return false;
}