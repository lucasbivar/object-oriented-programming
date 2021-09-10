#define QUANTITY_OF_ENTRIES 100

#include "Inventory.hpp"
#include "Tool.hpp"

using std::getline;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;


void menu();
void printLine();

int main(){
  Inventory inventory(QUANTITY_OF_ENTRIES);

  int op = 0;
  int entry_aux;
  char name_aux[70];
  double price_aux;
  int quantity_aux;

  while (true && op != 6){
    printLine();

    menu();
    cin >> op;

    printLine();

    switch (op){
    case 1:
      inventory.listAllTools();
      break;
    case 2:
      cout << "Digite o numero do registro (-1 cancela operacao): ";
      while (true){
        cin >> entry_aux;
        if(entry_aux == -1) break;
        if(!inventory.isValidEntry(entry_aux)){
          cout << endl;
          cout << "Registro nao disponivel!!" << endl; 
          cout << "Tente outro registro, ou -1 para cancelar operacao." << endl;
          cout << "Numero do Registro: ";
        }else{
          cout << "Nome da ferramenta: ";
          cin.ignore();
          cin.getline(name_aux, sizeof(name_aux));
          
          cout << "Quantidade: ";
          cin >> quantity_aux;

          cout << "Preco: ";
          cin >> price_aux;

          Tool tool(entry_aux, name_aux, quantity_aux, price_aux);
          inventory.createTool(tool);

          cout << "Ferramenta criada com sucesso!" << endl;
          
          break;
        }
      } 
      break;
    case 3:
      cout << "Digite o numero do registro (-1 cancela operacao): ";
      while (true){
        cin >> entry_aux;
        
        if(entry_aux == -1) break;
        if(!inventory.hasEntry(entry_aux)){
          cout << endl;
          cout << "Registro nao disponivel para atualizacao!!" << endl; 
          cout << "Tente outro registro, ou -1 para cancelar operacao." << endl;
          cout << "Numero do Registro: ";
          continue;
        }
        cout << "Nome da ferramenta: ";
        cin.ignore();
        cin.getline(name_aux, sizeof(name_aux));

        cout << "Quantidade: ";
        cin >> quantity_aux;

        cout << "Preco: ";
        cin >> price_aux;

        Tool tool(entry_aux, name_aux, quantity_aux, price_aux);

        if(!inventory.updateTool(tool)){
          cout << endl;
          cout << "Falha ao atualizar!!" << endl; 
          cout << "Tente outro registro, ou -1 para cancelar operacao." << endl;
          cout << "Numero do Registro: ";
        }else{
          cout << "Ferramenta atualizada com sucesso!" << endl;
          break;
        }
      }

      break;
    case 4:
      cout << "Digite o numero do registro (-1 cancela operacao): ";
      while (true){
        cin >> entry_aux;
        if(entry_aux == -1) break;
        if(!inventory.deleteTool(entry_aux)){
          cout << endl;
          cout << "Registro nao encontrador ou ainda tem estoque!!" << endl; 
          cout << "Tente outro registro, ou -1 para cancelar operacao." << endl;
          cout << "Registro: ";
        }else{
          cout << endl << "Ferramenta deletada com sucesso!" << endl;
          break;
        }
      } 

      break;
    case 5:
      cout << "Digite o numero do registro (-1 cancela operacao): ";
      while (true){
        cin >> entry_aux;
        if(entry_aux == -1) break;
        if(!inventory.showTool(entry_aux)){
          cout << endl;
          cout << "Registro nao encontrado!!" << endl; 
          cout << "Tente outro registro, ou -1 para cancelar operacao." << endl;
          cout << "Registro: ";
        }else{
          break;
        }
      } 
      
      break;
    default:
      break;
    }
  }
  
  return 0;
}


void menu(){
  cout.fill('-');
  cout << setw(53) << "-" << endl;

  cout.fill(' ');
  cout << setw(32) << "INVENTORY MENU" << endl;

  cout.fill('-');
  cout << setw(53) << "-" << endl;

  cout.fill(' ');

  cout << "1 - Listar todas ferramentas" << endl;
  cout << "2 - Adicionar ferramenta" << endl;
  cout << "3 - Editar ferramenta" << endl;
  cout << "4 - Deletar ferramenta" << endl;
  cout << "5 - Mostrar ferramenta" << endl;
  cout << "6 - Sair" << endl;

  cout.fill('-');
  cout << setw(53) << "-" << endl;

  cout.fill(' ');
  cout << "Op: ";
}


void printLine(){
  cout << endl;

  cout.fill('+');
  cout << setw(53) << "+" << endl;

  cout << endl;

  cout.fill(' ');
}