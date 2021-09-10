#ifndef INVENTORY_H
#define INVENTORY_H

#include <fstream>
using std::fstream;

#include "Tool.hpp"

	
class Inventory {
public:
	Inventory(int=100);
	~Inventory();

	void showAllTools();

	// delete the tool, if the quantity is equals to zero
	bool deleteTool(int);
	
	bool updateTool(Tool&);

	bool addTool(Tool&);

	// if the return is true, the tool was found.
	bool showTool(int); 

	// return true whether the entry is empty in inventory
	bool isValidEntry(int);

	bool hasEntry(int);

private:
	int countEntries();
	fstream dataBase;
	int dataBaseEntries;
};

#endif