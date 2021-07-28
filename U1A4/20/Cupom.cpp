#include "Cupom.h"

#include <string>
using std::string;

Cupom::Cupom(string id, string descricao, int quantidade, float preco){
  setId(id);
  setDescricao(descricao);
  setQuantidade(quantidade);
  setPreco(preco);
}

string Cupom::getId(){
  return id;
}

void Cupom::setId(string novoId){
  id = novoId;
}

string Cupom::getDescricao(){
  return descricao;
}

void Cupom::setDescricao(string novaDescricao){
  descricao = novaDescricao;
}

int Cupom::getQuantidade(){
  return quantidade;
}

void Cupom::setQuantidade(int novaQuantidade){
  quantidade = novaQuantidade < 0 ? 0 : novaQuantidade;
}

float Cupom::getPreco(){
  return preco;
}

void Cupom::setPreco(float novoPreco){
  preco = novoPreco < 0 ? 0 : novoPreco;
}

float Cupom::calculaCupom(){
  float valorTotal = getPreco() * getQuantidade();

  return valorTotal;
}