#include <fstream>
using std::ofstream;
using std::ios;

#include <iostream>
using std::endl;
using std::left;

#include <iomanip>
using std::setw;


int main(){
  ofstream fout;
  fout.open("dados.dat", ios::out);
  
  fout << left;

  fout << setw(20) << "char" << setw(5) << sizeof(char) << endl;
  fout << setw(20) << "unsigned char" << setw(5) << sizeof(unsigned char) << endl;
  fout << setw(20) << "int" << setw(5) << sizeof(int) << endl;
  fout << setw(20) << "short int" << setw(5) << sizeof(short int) << endl;
  fout << setw(20) << "unsigned short int" << setw(5) << sizeof(unsigned short int) << endl;
  fout << setw(20) << "long" << setw(5) << sizeof(long) << endl;
  fout << setw(20) << "long long int" << setw(5) << sizeof(long long int) << endl;
  fout << setw(20) << "unsigned long long" << setw(5) << sizeof(unsigned long long) << endl;
  fout << setw(20) << "float" << setw(5) << sizeof(float) << endl;
  fout << setw(20) << "double" << setw(5) << sizeof(double) << endl;

  fout.close();

  return 0;
}