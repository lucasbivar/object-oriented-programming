#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Agenda.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Agenda agendaDeContatos(5);
  
  Pessoa *pFisica1 = new PessoaFisica("Pedro", "Rua João Tavares", "pedro@gmail.com", 988331111,
                                       "11777716432", "16/06/2001", "Solteiro"), 
        *pFisica2 = new PessoaFisica("Isabel", "Avenida Rio Grande", "isabel@gmail.com", 987250000,
                                     "18728394834", "10/11/2002", "Casada");

  agendaDeContatos.adicionarContato(pFisica1);
  agendaDeContatos.adicionarContato(pFisica2);

  Pessoa *pJuridica1 = new PessoaJuridica("Coca Cola", "Avenida Monte Alto", "org@coca.com", 30303232,
                                       "5854561", "321231", "Coca Cola Industrias Ltda"), 
        *pJuridica2 = new PessoaJuridica("VTEX", "Avenida João Monteiro", "org@vtex.com", 40042200,
                                     "6842551", "123123", "VTEX BRASIL TECNOLOGIA PARA E-COMMERCE LTDA ");

  agendaDeContatos.adicionarContato(pJuridica1);
  agendaDeContatos.adicionarContato(pJuridica2);

  cout << "Listando todos os contatos..." << endl;
  agendaDeContatos.listarContatos();

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Buscando Isabel pelo nome..." << endl;

  agendaDeContatos.buscarContato("Isabel");

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Buscando Pedro pelo CPF..." << endl;

  agendaDeContatos.buscarContato("11777716432");

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Buscando VTEX pelo nome..." << endl;

  agendaDeContatos.buscarContato("VTEX");

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Buscando Coca Cola pelo CNPJ..." << endl;

  agendaDeContatos.buscarContato("5854561");

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Removendo Coca Cola pelo nome..." << endl;
  agendaDeContatos.removerContato("Coca Cola");

  cout << "Removendo Pedro pelo CPF..." << endl;
  agendaDeContatos.removerContato("11777716432");

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Listando todos os contatos..." << endl;
  agendaDeContatos.listarContatos();

  return 0;
}