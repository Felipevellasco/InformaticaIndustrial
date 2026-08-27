#include <iostream>

#include "mymath.h"

int main() {

  std::pair<float, const char *> inputs[] = {
      {25, "25"},
      {static_cast<float>(fact(7)), "7!"},
      {potencia(2.5, 3), "2.5^3"},
  };

  std::cout << fact(3) << std::endl;

  for (auto &[input, inputName] : inputs) {
    std::cout << "y(" << inputName << ") = " << y(input) << std::endl;
  }

  return 0;
}
