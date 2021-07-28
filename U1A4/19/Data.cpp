#include "Data.h"

#include <iostream>
using std::cout;
using std::endl;

Data::Data(int novoDia, int novoMes, int novoAno){
  setDia(novoDia);
  setMes(novoMes);
  setAno(novoAno);
}

void Data::setDia(int novoDia){
  dia = novoDia;
}

int Data::getDia(){
  return dia;
}

void Data::setMes(int novoMes){
  mes = (novoMes <= 12 && novoMes >= 1) ? novoMes : 1;
}

int Data::getMes(){
  return mes;
}

void Data::setAno(int novoAno){
  ano = novoAno;
}

int Data::getAno(){
  return ano;
}

void Data::mostrarData(){
  cout << getDia() << "/" << getMes() << "/" << getAno() << endl;
}