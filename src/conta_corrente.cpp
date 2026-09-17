#include "conta_corrente.h"

ContaCorrente::ContaCorrente(int senha, int numero, std::string titular,
                             double saldo)
    : Conta(senha, numero, titular, saldo) {}

const char *ContaCorrente::type() const { return _type; }

void ContaCorrente::aplicaOperacaoMensal() {
  saldo -= 15.0f; // Cobra taxa de manutenção
  if (saldo < 0) {
    std::cout << "Saldo negativo!!!" << std::endl;
  }
}

// Saque com limite de cheque especial (R$500,00)
// Infelizmente, a interface exigiu que:
// (a) saque() seja completamente implementado pela classe derivada; ou
// (b) saldo seja declarado protected.
void ContaCorrente::saque(int senha, double valor) {
  if (!validaSenha(senha)) {
    std::cout << "Senha inválida!" << std::endl;
    return;
  }

  if (valor < 0) {
    std::cout << "O valor do saque deve ser positivo!" << std::endl;
    return;
  }

  if (this->saldo - valor < -500) {
    std::cout << "Saldo insuficiente!" << std::endl;
    return;
  }

  this->saldo -= valor;
  std::cout << "Saque de R$" << valor << " realizado com sucesso." << std::endl;
}
