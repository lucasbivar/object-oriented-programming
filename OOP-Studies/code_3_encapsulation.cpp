#include <iostream>

using std::string;

class Employee{
private:
  string Name;
  string Company;
  unsigned short int Age;

public:
  Employee(){
      Name = "No name";
      Company = "No company";
      Age = 0;
  };

  Employee(string name, string company, unsigned short int age){
    Name = name;
    Company = company;
    Age = age;
  };

  void setName(string name){
    Name = name;
  }

  string getName(){
    return Name;
  }

  void setCompany(string company){
    Company = company;
  }

  string getCompany(){
    return Company;
  }

  void setAge(unsigned short int age){
    if(age >= 18){
      Age = age;
    }
  }

  unsigned short int getAge(){
    return Age;
  }


  void IntroduceYourself(){
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company - " << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
    std::cout << std::endl;
  }
};


int main(){
  Employee employee1, employee2, employee3, employee4;
  
  employee1 = Employee("Lucas Bivar", "Google", 18);
  employee2 = Employee("Vinicius Celestino", "Spotify", 19);
  employee3 = Employee("Joao Victor", "Facebook", 18);

  employee1.IntroduceYourself();
  employee2.IntroduceYourself();
  employee3.IntroduceYourself();
  employee4.IntroduceYourself(); // the default constructor was called

  return 0;
}

// g++ -Wall -std=c++17 OOP-Studies/code_2_constructors.cpp -o main && ./main