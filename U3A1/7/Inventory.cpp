#include "Inventory.hpp" 

#include "Tool.hpp"

using std::ios;

#include <iostream>
using std::cout;
using std::endl;
using std::left;

#include <iomanip>
using std::setw;

#include <string.h>

Tool initializer[8] = {
    {3, "Lixadeira", 7, 57.98},
    {17, "Martelo", 76, 11.99},
    {24, "Serra tico-tico", 21, 11.00},
    {39, "Cortador de grama", 3, 79.50},
    {56, "Serra eletrica", 18, 99.99},
    {68, "Chave de fenda", 106, 6.99},
    {77, "Marreta", 11, 21.50},
    {83, "Chave inglesa", 34, 7.50},
                      };

Inventory::Inventory(int quantityOfItems){
  this->dataBase.open("hardware.dat", ios::out | ios::in);

  if(!this->dataBase){
    this->dataBase.close();
    this->dataBaseEntries = quantityOfItems;
    this->dataBase.open("hardware.dat", ios::out);

    this->dataBase.seekp(0);
    Tool tmp;
    

    for(int i = 1; i <= quantityOfItems; i++){
      tmp.setEntry(i);
      this->dataBase.write(reinterpret_cast<char *>(&tmp), sizeof(Tool));
    }

    this->dataBase.flush();


    this->dataBase.close();
    this->dataBase.open("hardware.dat", ios::out | ios::in);

    for(int i = 0; i < 8; i++){
      this->createTool(initializer[i]);
    }

  }else{
    this->dataBaseEntries = this->countEntries();
  }
  
}
	
Inventory::~Inventory(){
	this->dataBase.close();
}


int Inventory::countEntries(){
  this->dataBase.clear();
  this->dataBase.seekg(0);

  Tool *tmp = (Tool*) malloc(sizeof(Tool));
  int size = 0;

  while(true){
    this->dataBase.read(reinterpret_cast<char*>(tmp), sizeof(Tool));

    if(this->dataBase.eof()) break;

    size++;
  }

  free(tmp);
  return size;
}


void Inventory::listAllTools() {
  cout << left;
  cout.fill('-');
  cout << setw(53) << "-" << endl;

  cout.fill(' ');
  cout << setw(5) << "ENTRY" << " | " << setw(25) << "NAME" << " | "
    << setw(8) << "QUANTITY" << " | " << setw(8) << "PRICE" << endl;

  cout.fill('-');
  cout << setw(53) << "-" << endl;

  cout.fill(' ');

  this->dataBase.clear();
  this->dataBase.seekg(0);

  Tool *tmp = (Tool*) malloc(sizeof(Tool));

  bool isEmpty = true;
  while(true){
    this->dataBase.read(reinterpret_cast<char *>(tmp), sizeof(Tool));

    if(this->dataBase.eof()) break;

    if(strcmp(tmp->getName(), "") == 0) continue;

    isEmpty = false;

    cout << *tmp;
  }

  if(isEmpty){
    cout << "       THE INVENTORY IS EMPTY, NOTHING TO SHOW!" << endl;
  }

  free(tmp);
}

bool Inventory::createTool(Tool& tool) {
  if(tool.getEntry() > this->dataBaseEntries || tool.getEntry() <= 0 
    || (strcmp(tool.getName(), "") == 0)) return false;

  Tool *tmp = (Tool*) malloc(sizeof(Tool));
  // not working
  // Tool tmp; 

  this->dataBase.clear();
  
  this->dataBase.seekg((tool.getEntry()-1)*sizeof(Tool));
  this->dataBase.read(reinterpret_cast<char*>(tmp), sizeof(Tool));
  // this->dataBase.read(reinterpret_cast<char*>(&tmp), sizeof(Tool));

  if((strcmp(tmp->getName(), "") != 0)) return false;

  this->dataBase.seekp((tool.getEntry()-1)*sizeof(Tool));
  this->dataBase.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

  this->dataBase.flush();
  free(tmp);
  
  return true;
}

bool Inventory::showTool(int entry) {
  if(entry > this->dataBaseEntries || entry <= 0) return false;
  
  this->dataBase.clear();

  Tool *tmp = (Tool*) malloc(sizeof(Tool));
  
  this->dataBase.seekg((entry-1)*sizeof(Tool));
  this->dataBase.read(reinterpret_cast<char *>(tmp), sizeof(Tool));

  if((strcmp(tmp->getName(), "") != 0)){
    cout << endl << "FERRAMENTA:" << endl;

    cout << setw(5) << "ENTRY" << " | " << setw(25) << "NAME" << " | "
      << setw(8) << "QUANTITY" << " | " << setw(8) << "PRICE" << endl;
    
    cout.fill('-');
    cout << setw(53) << "-" << endl;

    cout.fill(' ');

    cout << *tmp;

    free(tmp);

    return true;
  }

  free(tmp);

  return false;
}

bool Inventory::isValidEntry(int entry){
  if(entry > this->dataBaseEntries || entry <= 0) return false;

  this->dataBase.clear();

  Tool *tmp = (Tool*) malloc(sizeof(Tool));
  
  this->dataBase.seekg((entry-1)*sizeof(Tool));
  this->dataBase.read(reinterpret_cast<char *>(tmp), sizeof(Tool));
    
  if((strcmp(tmp->getName(), "") != 0)){

    free(tmp);

    return false;
  }

  free(tmp);

  return true;
}

bool Inventory::hasEntry(int entry) {
  if(entry > this->dataBaseEntries || entry <= 0) return false;

  this->dataBase.clear();

  Tool *tmp = (Tool*) malloc(sizeof(Tool));
  
  this->dataBase.seekg((entry-1)*sizeof(Tool));
  this->dataBase.read(reinterpret_cast<char *>(tmp), sizeof(Tool));
    
  if((strcmp(tmp->getName(), "") != 0)){

    free(tmp);

    return true;
  }

  free(tmp);

  return false;
}

bool Inventory::deleteTool(int entry){
  if(entry > this->dataBaseEntries || entry <= 0) return false;

  this->dataBase.clear();
 
  Tool *tmp = (Tool*) malloc(sizeof(Tool));

  this->dataBase.seekg((entry-1)*sizeof(Tool));
  this->dataBase.read(reinterpret_cast<char *>(tmp), sizeof(Tool));

  if(tmp->getQuantity() == 0 && (strcmp(tmp->getName(), "") != 0)){
    tmp->setName("");
    tmp->setPrice(0);

    this->dataBase.seekp((entry-1)*sizeof(Tool));
    this->dataBase.write(reinterpret_cast<char *>(tmp), sizeof(Tool));

    this->dataBase.flush();

    free(tmp);

    return true;
  }

  free(tmp);

  return false;
}

bool Inventory::updateTool(Tool& tool){
  if(tool.getEntry() > this->dataBaseEntries || tool.getEntry() <= 0 
    || (strcmp(tool.getName(), "") == 0)) return false;

  this->dataBase.clear();

  this->dataBase.seekp((tool.getEntry()-1)*sizeof(Tool));
  this->dataBase.write(reinterpret_cast<char*>(&tool), sizeof(Tool));

  this->dataBase.flush();

  return true;
}
