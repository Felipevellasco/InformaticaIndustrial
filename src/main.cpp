#include <cmath>
#include <cstdint>
#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;

  float peso = 0;
  float altura = 0;

  while (true) {
    std::cout << "Digite o seu peso em kg:\n";
    std::cin >> peso;
    if (peso < 0) {
      std::cout << "Peso inválido inserido.\n";
      continue;
    }
    break;
  }

  while (true) {
    std::cout << "Digite a sua altura em metros:\n";
    std::cin >> altura;
    if (altura < 0) {
      std::cout << "Altura inválida inserida.\n";
      continue;
    }
    break;
  }

  float imc = (peso) / (altura * altura);

  std::cout << "IMC = " << imc << std::endl;

  // Abaixo: < 18.5
  // Normal < 24.9
  // Acima: < 29.9
  // Sobrepeso > 30

  enum imcClass_t : uint8_t {
    abaixo,
    normal,
    acima,
    sobrepeso,
  };

  imcClass_t weightClass;

  if (imc >= 30)
    weightClass = sobrepeso;
  else if (imc >= 25)
    weightClass = acima;
  else if (imc >= 18.5)
    weightClass = normal;
  else
    weightClass = abaixo;

  switch (weightClass) {
    using enum imcClass_t;
  case abaixo:
    std::cout << "Você está abaixo do peso desejado." << std::endl;
    break;
  case normal:
    std::cout << "Você está na faixa de peso normal." << std::endl;
    break;
  case acima:
    std::cout << "Você está acima do peso desejado." << std::endl;
    break;
  case sobrepeso:
    std::cout << "Você está obeso." << std::endl;
    break;
  default:
    std::cerr << "Erro de cálculo!" << std::endl;
    return 1;
  }

  return 0;
}
