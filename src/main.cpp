#include <iostream>
#include <cstdint>

int main() {
  std::cout << "Hello World!" << std::endl;

  int16_t a = 10;
  int16_t b = 20;

  std::cin >> a;
  int16_t c = a + b;

  std::cout << "Count: " << c << std::endl;

  return 0;
}
