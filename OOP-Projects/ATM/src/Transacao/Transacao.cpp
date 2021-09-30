#include "../../include/Transacao/Transacao.h"

#include <string>
using std::string;
using std::to_string;
 
#include <string.h>

#include <time.h>


Transacao::Transacao(double valor, const char* descricao, const char* conta){

  time_t theTime = time(NULL);
  struct tm *aTime = localtime(&theTime);

  string dia = to_string(aTime->tm_mday);
  dia = string(2 - dia.size(), '0') + dia;
  string mes = to_string(aTime->tm_mon + 1);
  mes = string(2 - mes.size(), '0') + mes;
  string ano = to_string(aTime->tm_year + 1900);
  string data = dia + "-" + mes + "-" + ano;
  
  this->valorDaTransacao = valor;
  strcpy(this->descricao, descricao);
  strcpy(this->data, data.c_str());
  strcpy(this->conta, conta);
}

const char* Transacao::getData() const {
  return data;
}

double Transacao::getValorDaTransacao() const {
  return valorDaTransacao;
}

const char* Transacao::getDescricao() const {
  return descricao;
}

