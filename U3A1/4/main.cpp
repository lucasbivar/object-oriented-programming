#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::right;
using std::fixed;
using std::showpoint;

#include <iomanip>
using std::setw;


int main(){
  int fahrenheit;
  cout << "Digite uma temperatura em Fahrenheit (0 a 212): ";
  cin >> fahrenheit;

  double celsius = (5.0/9.0)*(fahrenheit - 32);

  cout << right;

  cout.fill('-');
  cout << setw(28) << "-" << endl;
  
  cout.fill(' ');
  cout << "|" << setw(11) << "Escala" << " | " << setw(11) << "Temperatura" << " |" << endl;
  
  cout.fill('-');
  cout << setw(28) << "-" << endl;

  cout.fill(' ');
  cout << fixed;
  cout.precision(3);

  cout << "|" << setw(11) << "Fahrenheit" << " | " << setw(11) << fahrenheit << " |" << endl;
  cout << "|" << setw(11) << "Celsius" << " | " << setw(11) << celsius << " |" << endl;

  cout.fill('-');
  cout << setw(28) << "-" << endl;

  return 0;
}