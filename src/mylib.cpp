#include <cmath>

#include "mylib.hpp"

int fact(int input) {
  if (input <= 1)
    return 1;

  return input * fact(input - 1);
}

float y(float x) {
  float result = fact(2);
  result += fact(3) * std::pow(x, 1);
  result += fact(4) * std::pow(x, 2);
  result += fact(5) * std::pow(x, 3);

  return result;
}

void invertenome(char *nome) {
  int counter = 0;
  while (nome[counter] != '\0')
    counter++;

  char *inverted = new char[counter + 1];
  counter--;

  int i = 0;
  while (counter + 1) {
    inverted[i] = nome[counter];
    i++;
    counter--;
  }

  for (int j = 0; j <= i; j++) {
    nome[j] = inverted[j];
  }

  nome[i+1] = '\0';

  delete[] inverted;
  return;
}
