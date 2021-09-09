#include <iostream>
using std::cout;
using std::endl;
using std::left;

#include <iomanip>
using std::setw;


int main(){
  cout.fill('-');

  cout << setw(14) << "-" << endl;
  cout << "| Num | Char |" << endl;
  cout << setw(14) << "-" << endl;


  cout.fill(' ');
  for(int i = 33; i < 126; i++){
    cout << "| " << setw(3) << left << i << " | " << setw(4) << 
      static_cast<char>(i) << " |" << endl;
  }

  cout.fill('-');
  cout << setw(14) << "-" << endl;

  return 0;
}