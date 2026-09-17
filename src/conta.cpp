#include "conta.h"
#include <iostream>

Conta::Conta() {
  this->numero = 0;
  this->senha = 1111;
  this->titular = "Nenhum";
  this->saldo = 0;
}

Conta::Conta(int senha, int numero, std::string titular, double saldo) {
  this->senha = senha;
  this->numero = numero;
  this->titular = titular;

  if (saldo > 0) {
    this->saldo = saldo;
  } else {
    std::cout << "Saldo inicial invalido" << std::endl;
  }
}

Conta::~Conta() {}

void Conta::exibeDados() {
  std::cout << "Titular: " << this->titular << std::endl;
  std::cout << "Numero: " << this->numero << std::endl;
  std::cout << "Tipo: " << this->type() << std::endl;
}

double Conta::getSaldo(int senha) {
  if (senha == this->senha) {
    return this->saldo;
  } else {
    std::cout << "Senha inválida" << std::endl;
    return -10000000;
  }
}

void Conta::setSaldo(double valor) {
  if (valor > 0)
    this->saldo = valor;
  else
    std::cout << "Valor inválido" << std::endl;
}

void Conta::setSenha(int novaSenha) { this->senha = novaSenha; }

void Conta::deposito(double valor) {
  if (valor > 0) {
    this->saldo += valor;
  } else {
    std::cout << "Valor invalido" << std::endl;
  }
}

void Conta::saque(int senha, double valor) {
  if (senha == this->senha) {
    if (this->saldo > valor) {
      this->saldo -= valor;
      std::cout << "Saque de R$" << valor << " realizado com sucesso."
                << std::endl;
    } else {
      std::cout << "Saldo insuficiente" << std::endl;
    }
  } else {
    std::cout << "Senha invalida" << std::endl;
  }
}

bool Conta::validaSenha(int senha) { return (this->senha == senha); }

ContaCorrente::ContaCorrente(int senha, int numero, std::string titular,
                             double saldo)
    : Conta(senha, numero, titular, saldo) {}

const char *ContaCorrente::type() const { return _type; }

// Saque com limite de cheque especial (R$500,00)
// Infelizmente, a interface exigiu que:
// (a) saque() seja completamente implementado pela classe derivada; ou
// (b) saldo seja declarado protected.
void ContaCorrente::saque(int senha, double valor) {
  if (!validaSenha(senha)) {
    std::cout << "Senha inválida!" << std::endl;
    return;
  }

  if (this->saldo < valor - 500) {
    std::cout << "Saldo insuficiente!" << std::endl;
  }

  this->saldo -= valor;
  std::cout << "Saque de R$" << valor << " realizado com sucesso." << std::endl;
}

ContaPoupança::ContaPoupança(int senha, int numero, std::string titular,
                             double saldo)
    : Conta(senha, numero, titular, saldo) {}

const char *ContaPoupança::type() const { return _type; }

void ContaPoupança::render(double taxa) {
  saldo *= taxa; // rendimento simples
}
