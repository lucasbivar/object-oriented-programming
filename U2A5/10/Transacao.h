#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
using std::string;

class Transacao {
public:
  Transacao(double=0, string="");

  string getData() const;
  double getValorDaTransacao() const;
  string getDescricao() const;

private:
  string data; //DD-MM-AAAA
  double valorDaTransacao;
  string descricao;
};

#endif