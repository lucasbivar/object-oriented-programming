#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include "ExcecaoUm.h"
#include "ExcecaoDois.h"

void funcao(){

  throw ExcecaoDois();

  cout << "Não aconteceu erro..." << endl;
}

void funcaoDois(){

  throw ExcecaoUm();

  cout << "Não aconteceu erro..." << endl;
}


int main(){

  try{
    funcao();
  }catch(runtime_error &e){
    cout << "Capturando range_error por meio da classe básica direta runtime_error" << endl;
    cerr << e.what() << endl;
  }

  try{
    funcaoDois();
  }catch(runtime_error &e){
    cout << "Capturando range_error por meio da classe básica direta runtime_error" << endl;
    cerr << e.what() << endl;
  }

  return 0;
}