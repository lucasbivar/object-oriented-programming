#include "Agenda.h"

#include "Pessoa.h"


Agenda::Agenda(int tamanho){
  this->quantidadeDeContatos = 0;
  this->tamanhoDaAgenda = tamanho > 0 ? tamanho : 10;
  this->agenda = new Pessoa*[tamanhoDaAgenda];
}

Agenda::~Agenda(){
  for(int i = 0; i < quantidadeDeContatos; i++){
    delete agenda[i];
  }
  delete [] agenda;
}

void Agenda::buscarContato(const string termoDeBusca) const {
  for(int i = 0; i < quantidadeDeContatos; i++){
    if(agenda[i]->getNome() == termoDeBusca || 
    agenda[i]->getCpfOrCnpj() == termoDeBusca){
      agenda[i]->exibirPessoa();
      break;
    } 
  }
}

bool Agenda::removerContato(const string termoDeBusca){
  int posicaoPessoa = -1;
  for(int i = 0; i < quantidadeDeContatos; i++){
    if(agenda[i]->getNome() == termoDeBusca || 
    agenda[i]->getCpfOrCnpj() == termoDeBusca){
      posicaoPessoa = i;
    } 
  }
  if(posicaoPessoa == -1) return false;

  delete agenda[posicaoPessoa];

  for(int i = posicaoPessoa+1; i < quantidadeDeContatos; i++){
    agenda[i-1] = agenda[i];
  }
  
  quantidadeDeContatos--;

  return true;
}

bool Agenda::adicionarContato(Pessoa* pessoa) {
  if(quantidadeDeContatos < tamanhoDaAgenda){
    agenda[quantidadeDeContatos++] = pessoa;
    return true;
  }
  return false;
}