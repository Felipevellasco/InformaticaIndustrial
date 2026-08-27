#include <iostream>

#include "mylib.hpp"

int main() {

  char name[30];

  std::cout << "Digite o seu nome:\n";
  std::cin.getline(name, sizeof(name));

  invertenome(name);
  std::cout << name << std::endl;

  return 0;
}
