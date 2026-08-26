#include <iostream>

#include "mymath.h"

int main() {

float inputs[] = {25, static_cast<float>(fact(7)), potencia(2.5, 3)};

  std::cout << fact(3) << std::endl;

  for (auto &input : inputs) {
    std::cout << "y(" << input << ") = " << y(input) << std::endl;
  }

  return 0;
}
