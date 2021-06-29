#include <iostream>

using std::string;

//abstract class - contract with rules
class AbstractEmployee{
  // virtual function or abstract function
  virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee{
protected:
  string Name;

private:
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

  void AskForPromotion(){
    if(Age > 30){
      std::cout << Name << " got promoted!" << std::endl;
    }else{
      std::cout << Name << ", sorry No promotion for you!" << std::endl;
    }
  };
};

// Developer is a derived (child or  sub) class from the base(super, parent) class Employee;
// So, Developers has all attributs and methods from Employee, but by default the inheritance
// is private and we have to change to public to access the methods from the base class
class Developer: public Employee{
public:
  string FavProgrammingLanguage;
  Developer(string name, string company, unsigned short int age, string favProgrammingLanguage): Employee(name, company, age){
    FavProgrammingLanguage = favProgrammingLanguage;
  };
  void FixBug(){
    // We can't access the name using just "Name", because we set the Name as private attribute,
    // and private attribute just can be accessed in the same class. So we have to change to protected.
    std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
  }
};

class Teacher: public Employee {
public:
  string Subject;
  Teacher(string name, string company, unsigned short int age, string subject): Employee(name, company, age){
    Subject = subject;
  }
  void PrepareLesson(){
    std::cout << Name << " is preparing " << Subject << " lesson..." << std::endl;
  }
};

int main(){
  Employee employee1 = Employee("Vinicius Celestino", "Spotify", 19);

  Developer employee2 = Developer("Lucas Bivar", "Google", 18, "C++");

  Teacher employee3 = Teacher("Joao Victor", "Facebook", 19, "OOP");

  employee1.IntroduceYourself();

  employee2.FixBug();
  employee2.AskForPromotion();

  std::cout << std::endl;

  employee3.PrepareLesson();
  employee3.AskForPromotion();

  return 0;
}

// g++ -Wall -std=c++17 OOP-Studies/code_5_inheritance.cpp -o main && ./main