#include "Retangulo.h"

Retangulo::Retangulo(double novaAltura, double novaLargura){
  setAltura(novaAltura);
  setLargura(novaLargura);
}

void Retangulo::setAltura(double novaAltura){
  altura = (novaAltura > 0 && novaAltura < 20) ? novaAltura: 1.0;
}

void Retangulo::setLargura(double novaLargura){
  largura = (novaLargura > 0 && novaLargura < 20) ? novaLargura : 1.0;
}

double Retangulo::getAltura(){
  return altura;
}

double Retangulo::getLargura(){
  return largura;
}

double Retangulo::perimetro(){
  return 2*getAltura() + 2*getLargura();
}

double Retangulo::area(){
  return getAltura()*getLargura();
}