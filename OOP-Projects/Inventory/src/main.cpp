#define QUANTITY_OF_ENTRIES 100

#include "../include/Inventory.hpp" 

#include "../include/Tool.hpp"

using std::getline;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <chrono>
#include <thread>

#include <stdlib.h>

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
    
    if(op != 0){
      std::this_thread::sleep_for(std::chrono::milliseconds(3000));
      system("clear");
    }

    menu();
    cin >> op;

    printLine();

    switch (op){
    case 1:
      inventory.showAllTools();
      break;
    case 2:
      cout << "Type the entry number (-1 cancel the operation): ";
      while (true){
        cin >> entry_aux;
        if(entry_aux == -1) break;

        if(!inventory.isValidEntry(entry_aux)){
          cout << endl;
          cout << "Entry not available!!" << endl; 
          cout << "Try again other entry, or -1 to cancel the opeartion." << endl << endl;
          cout << "Entry number: ";
        }else{
          cout << "Tool name: ";
          cin.ignore();
          cin.getline(name_aux, sizeof(name_aux));
          
          cout << "Quantity: ";
          cin >> quantity_aux;

          cout << "Price: ";
          cin >> price_aux;

          Tool tool(entry_aux, name_aux, quantity_aux, price_aux);
          inventory.addTool(tool);

          cout << "Tool created successfully!" << endl;
          break;
        }
      } 
      break;
    case 3:
      cout << "Type the entry number (-1 cancel the operation): ";
      while (true){
        cin >> entry_aux;
        
        if(entry_aux == -1) break;
        if(!inventory.hasEntry(entry_aux)){
          cout << endl;
          cout << "Entry not available to updates!" << endl; 
          cout << "Try again other entry, or -1 to cancel the operation." << endl << endl;
          cout << "Entry number: ";
          continue;
        }
        cout << "Tool name: ";
        cin.ignore();
        cin.getline(name_aux, sizeof(name_aux));

        cout << "Quantity: ";
        cin >> quantity_aux;

        cout << "Price: ";
        cin >> price_aux;

        Tool tool(entry_aux, name_aux, quantity_aux, price_aux);

        if(!inventory.updateTool(tool)){
          cout << endl;
          cout << "Failed during update!!" << endl; 
          cout << "Try again other entry, or -1 to cancel the operation." << endl << endl;
          cout << "Entry number: ";
        }else{
          cout << "Tool successfully updated!" << endl;
          break;
        }
      }

      break;
    case 4:
      cout << "Type the entry number (-1 cancel the operation): ";
      while (true){
        cin >> entry_aux;
        if(entry_aux == -1) break;
        if(!inventory.deleteTool(entry_aux)){
          cout << endl;
          cout << "Entry not found or still have stock!!" << endl; 
          cout << "Try again other entry, or -1 to cancel the operation." << endl << endl;
          cout << "Entry number: ";
        }else{
          cout << endl << "Tool successfully deleted!" << endl;
          break;
        }
      } 

      break;
    case 5:
      cout << "Type the entry number (-1 cancel the operation): ";
      while (true){
        cin >> entry_aux;
        if(entry_aux == -1) break;
        if(!inventory.showTool(entry_aux)){
          cout << endl;
          cout << "Entry not found!!" << endl; 
          cout << "Try again other entry, or -1 to cancel the operation." << endl << endl;
          cout << "Entry number: ";
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

  cout << "1 - Show all tools" << endl;
  cout << "2 - Add tool" << endl;
  cout << "3 - Edit tool" << endl;
  cout << "4 - Delete tool" << endl;
  cout << "5 - Show tool" << endl;
  cout << "6 - Exit" << endl;

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
