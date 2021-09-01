#ifndef AGENDA_H
#define AGENDA_H

#include "Pessoa.h"

#include <string>
using std::string;

class Agenda{
public:
  Agenda(int=10);
  ~Agenda();

  void buscarContato(const string) const;

  bool removerContato(const string);
  bool adicionarContato(Pessoa*);

private:
  int tamanhoDaAgenda;
  int quantidadeDeContatos;
  Pessoa **agenda;
};

#endif