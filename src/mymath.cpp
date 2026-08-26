#include "mymath.h"

int fact(int input) {
  if (input <= 1)
    return 1;

  return input * fact(input - 1);
}

float y(float x) {
  float result = fact(2);
  result += fact(3) * potencia(x, 1);
  result += fact(4) * potencia(x, 2);
  result += fact(5) * potencia(x, 3);

	return result;
}

// ---------------

float potencia(float b, int exp) {
  float r = b;
  for (int i = 1; i < exp; i++) {
    r *= b;
  }
  return r;
}

int soma(int a, int b) { return a + b; }

int soma(int a, int b, int c) { return a + b + c; }

float soma(int a, float b) { return a + b; }
