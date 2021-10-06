#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
using std::string;

class Transacao {
public:
  Transacao(double=0, string ="", string ="", string ="");

  string getData() const;
  double getValorDaTransacao() const;
  string getDescricao() const;
  string getTransacoes() const;

private:
  string data; //DD-MM-AAAA
  double valorDaTransacao;
  string descricao;
  string conta;
};

#endif