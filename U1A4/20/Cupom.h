#ifndef CUPOM_H
#define CUPOM_H

#include <string>
using std::string;

class Cupom{
public:
  Cupom(string id, string descricao, int quantidade, float preco);

  string getId();
  void setId(string novoId);

  string getDescricao();
  void setDescricao(string novaDescricao);

  int getQuantidade();
  void setQuantidade(int novaQuantidade);

  float getPreco();
  void setPreco(float novoPreco);

  float calculaCupom();

private:
  string id, descricao;
  int quantidade;
  float preco;
};

#endif