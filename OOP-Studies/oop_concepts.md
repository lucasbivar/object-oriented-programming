# Object Programming Oriented 

OOP is a programming paradigm which means that is a set of rules and ideas and concepts. The mainly idea of OOP is be able to represent real-life objects with their characteristics, attributes and behaviors.

## Benefits
  - Modular Structure;
  - Software becomes easier to maintain;
  - Reusable code;
  - Encapsulation: it's not mandatory knows the object's internal implementation to use;

### Class
Classes are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members(class attributes)


```cpp
class Employee{
  std::string Name;
  std::string Company;
  unsigned short int Age;

  void IntroduceYourself(){
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company - " << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
  }
};
```

Classes have the same format as plain data structures, except that they can also include functions and have these new things called access specifiers.

An access specifier (or access modifiers) is one of the following three keywords: private, public or protected. These specifiers modify the access rights for the members that follow them *(In cpp, by default, all class members are private)*:

- **private:** Are accessible only from within other members of the same class (or from their "friends");

- **protected:** Same thing of private, but can be accessible also from members of their derived classes (Inheritance);

- **public:** Are accessible from anywhere where the object is visible;


### Object
An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.

```cpp
int main(){
  Employee e1;

  e1.Name = "Lucas Bivar";
  e1.Company = "Google";
  e1.Age = 18;

  return 0;
}
```

### Constructors
What would happen in the previous example if we called the member function area before having setted the values? In order to avoid that, a class can include a special function called its constructor, which is automatically called whenever a new object of this class is created, allowing the class to initialize member variables or allocate storage.

This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void.

Pay attention: When we create a constuctor, we are going to lose that default constructor. We can fix this creating our own default constructor;

```cpp
class Employee{
public:
  std::string Name;
  std::string Company;
  unsigned short int Age;
  // Default constructor
  Employee(){
      Name = "No name";
      Company = "No company";
      Age = 0;
  };

  //Constructor
  Employee(std::string name, std::string company, unsigned short int age){
    Name = name;
    Company = company;
    Age = age;
  };
};
```
<hr>

## **4 PILLARS OF OOP**
### **1. Encapsulation**

Encapsulation is the technique of making the fields in a class private and providing access to the field via public methods. If a field is declared private, it cannot be accessed directly by anyone outside the class, thereby hiding the fields within the class, improving the security of our code and allowing we create custom rules to the fields.

To access the encapsulated attributes, we use methods. This methods are called getters and setters;

```cpp
class Employee{
private:
  std::string Name; 
  unsigned short int Age;
  
public:

  // setter (name)
  void setName(std::string name){
    Name = name;
  }
  // getter (name)
  std::string getName(){
    return Name;
  }

  // setter (age)
  void setAge(unsigned short int age){
    if(age >= 18){
      Age = age;
    }
  }

  // getter (age)
  unsigned short int getAge(){
    return Age;
  }

};

```

### **2. Abstraction**

Data abstraction or information hiding refers to providing only essential information to the 
outside world and hiding their background details (The complex implementation behind this), showing always the relevant features to the given project. To create this abstraction, we use *Abstract Classes* similar to interface in Java or C#.

```cpp
//abstract class - contract with rules
class AbstractEmployee{
  // virtual function or abstract function
  virtual void AskForPromotion() = 0;
};
```

In Abstract Class we will make the contract, setting the rules of our class. All classes inherited from the abstract must have the implementation of the virtual function, that was settled in contract. Example:

```cpp
class Employee:AbstractEmployee{
private:
  std::string Name;
  std::string Company;
  unsigned short int Age;

public:
  void AskForPromotion(){
    if(Age > 30){
      std::cout << Name << " got promoted!" << std::endl;
    }else{
      std::cout << Name << ", sorry No promotion for you!" << std::endl;
    }
  };
};

```

### **3. Inheritance**

Inheritance is the process of forming a new class from an existing class called as base class, new class is formed called as derived class. This principle is very important, since helps to reduce the code size.

![](https://beginnersbook.com/wp-content/uploads/2019/03/Kotlin_inheritance_example.png)

#### Base Class
```cpp
class AbstractEmployee{
  virtual void AskForPromotion() = 0;
};

class Employee{
protected:
  std::string Name;

private:
  std::string Company;
  unsigned short int Age;

public:
  Employee(std::string name, std::string company, unsigned short int age){
    Name = name;
    Company = company;
    Age = age;
  };

  void AskForPromotion(){
    if(Age > 30){
      std::cout << Name << " got promoted!" << std::endl;
    }else{
      std::cout << Name << ", sorry No promotion for you!" << std::endl;
    }
  };
};
```

#### Derivated Classes

```cpp
// if we not set the inheritance access specifier, it will be private by default
class Developer: public Employee{
public:
  std::string FavProgrammingLanguage;

  // Constructor of derived class
  Developer(std::string name, std::string company, unsigned short int age, std::string favProgrammingLanguage): Employee(name, company, age){
    FavProgrammingLanguage = favProgrammingLanguage;
  };

  void FixBug(){
    std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
  }
};


class Teacher: public Employee {
public:
  std::string Subject;

  // Constructor of derived class
  Teacher(std::string name, std::string company, unsigned short int age, std::string subject): Employee(name, company, age){
    Subject = subject;
  }

  void PrepareLesson(){
    std::cout << Name << " is preparing " << Subject << " lesson..." << std::endl;
  }
};
```

#### Main program

```cpp
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
```

### **4. Polymorphism**

Polymorphism means having many forms. In OOP, polymorphism is the ability of objects of different types to respond to functions of the same name. The user does not have to know the exact type of the object in advance. The behavior of the object can be implemented at
run time.

The most common use of polymorphism is when a base class (Employee in this case) reference is used to refer to a derived class (Developer or Teacher in this case) object.

```cpp
class Employee{
protected:
  std::string  Name;

public:
  Employee(std::string name){
    Name = name;
  };

  void setName(std::string  name){
    Name = name;
  }

  std::string getName(){
    return Name;
  }

  virtual void Work(){
    std::cout << Name << " is checking the email, task backlog, performing tasks..." << std::endl;
  }

};
```

Look the function "Work" with virtual keyword, this keyword means that when a virtual function is invoked, it says: "hey, can you please check if there is implementation of this function in my derived classes? If yes, please execute that instead." 
So, in this case, the compiler looks at the contents of the pointer instead of it's type. In other words, the virtual keyword signals to the compiler that we don't want static linkage for this function, but dynamic linkage.

```cpp 
class Developer: public Employee{
public:
  std::string FavProgrammingLanguage;
  Developer(std::string name, std::string favProgrammingLanguage): Employee(name){
    FavProgrammingLanguage = favProgrammingLanguage;
  };

  void Work(){
    std::cout << Name << " is writing " << FavProgrammingLanguage << " code..." << std::endl;
  }
};
```

```cpp 
class Teacher: public Employee {
public:
  std::string  Subject;
  Teacher(std::string  name, std::string subject): Employee(name){
    Subject = subject;
  }

  void Work(){
    std::cout << Name << " is teaching " <<  Subject << "..." << std::endl;
  }
};
```

```cpp
int main(){
  Employee employee1 = Employee("Vinicius Celestino");

  Developer employee2 = Developer("Lucas Bivar", "C++");

  Teacher employee3 = Teacher("Joao Victor", "OOP");

  employee1.Work(); // Vinicius Celestino is checking the email, task backlog, performing tasks...

  employee2.Work(); // Lucas Bivar is writing C++ code...
  employee3.Work(); // Joao Victor is teaching OOP...


  std::cout << std::endl;


  Employee *employeePtr1 = &employee2; 
  Employee *employeePtr2 = &employee3; 

  employeePtr1->Work(); // Lucas Bivar is writing C++ code...
  employeePtr2->Work(); // Joao Victor is teaching OOP...

  return 0;
}
```