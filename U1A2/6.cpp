#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

int main(){
  string texto, novoTexto;

  cout << "Digite uma frase:" << endl;
  getline(cin, texto);
  
  for(auto &c: texto){
    if(c != ' ' && c != '.' && c != ',' && c != '!' && c != '?' && c != ';' 
    && c != '-' && c != ':' && c != '(' && c != ')' && c != '\"'){
      novoTexto += c;
    }
  }

  cout << novoTexto << endl;
  return 0;
}
