#include "conta_poupanca.h"

ContaPoupança::ContaPoupança(int senha, int numero, std::string titular,
                             double saldo)
    : Conta(senha, numero, titular, saldo) {}

void ContaPoupança::_render(double taxa) {
  saldo *= taxa; // rendimento simples
}

const char *ContaPoupança::type() const { return _type; }

void ContaPoupança::aplicaOperacaoMensal() {
  _render(0.05f / 100); // Rendimento de 0.05% ao mês
}
