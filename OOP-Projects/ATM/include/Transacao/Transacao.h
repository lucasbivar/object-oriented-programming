#ifndef TRANSACAO_H
#define TRANSACAO_H

class Transacao {
public:
  Transacao(double=0, const char* ="", const char* ="");

  const char* getData() const;
  double getValorDaTransacao() const;
  const char* getDescricao() const;
  const char* getTransacoes() const;

private:
  char data[15]; //DD-MM-AAAA
  double valorDaTransacao;
  char descricao[50];
  char conta[15];
};

#endif