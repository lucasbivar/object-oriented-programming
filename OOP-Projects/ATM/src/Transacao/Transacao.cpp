#include "../../include/Transacao/Transacao.h"

#include <string>
using std::string;
using std::to_string;

#include <time.h>


Transacao::Transacao(double valor, string descricao, string conta, string data){

  if(data == ""){
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    string dia = to_string(aTime->tm_mday);
    dia = string(2 - dia.size(), '0') + dia;
    string mes = to_string(aTime->tm_mon + 1);
    mes = string(2 - mes.size(), '0') + mes;
    string ano = to_string(aTime->tm_year + 1900);
    data = dia + "-" + mes + "-" + ano;
  }
  
  this->valorDaTransacao = valor;
  this->data = data;
  this->descricao = descricao;
  this->conta = conta;
}

string Transacao::getData() const {
  return data;
}

double Transacao::getValorDaTransacao() const {
  return valorDaTransacao;
}

string Transacao::getDescricao() const {
  return descricao;
}

