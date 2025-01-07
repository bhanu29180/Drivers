#include <iostream>

class Base {
public:
  void someFunction() {
    std::cout << "This is the Base class function." << std::endl;
  }
};

class Derived1 : public Base {
public:
  void someFunction() { 
    std::cout << "This is the Derived1 class function." << std::endl; 
  }
};

class Derived2 : public Base {
public:
  void someFunction() { 
    std::cout << "This is the Derived2 class function." << std::endl; 
  }
};

int main() {
  Derived1 derived1Obj1;
  Derived1 derived1Obj2;
  Derived2 derived2Obj1;
  Derived2 derived2Obj2;

  derived1Obj1.someFunction(); // Output: This is the Derived1 class function.
  derived1Obj2.someFunction(); // Output: This is the Derived1 class function.
  derived2Obj1.someFunction(); // Output: This is the Derived2 class function.
  derived2Obj2.someFunction(); // Output: This is the Derived2 class function.

  return 0;
}