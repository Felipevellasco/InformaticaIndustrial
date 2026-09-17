#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <string>

class Conta {
private:
  int senha;

protected:
  double saldo;

public:
  int numero;
  std::string titular;

  Conta();
  Conta(int senha, int numero, std::string titular, double saldo);
  virtual ~Conta();

  virtual const char *type() const = 0;

  virtual void saque(int senha, double valor);

  void exibeDados();
  double getSaldo(int senha);
  void setSaldo(double valor);
  void setSenha(int novaSenha);
  void deposito(double valor);
  bool validaSenha(int senha);
};

class ContaCorrente : public Conta {
private:
  const char *const _type = "Corrente";

public:
  ContaCorrente(int senha, int numero, std::string titular, double saldo);

  const char *type() const override;

  // Saque com limite de cheque especial (R$500,00)
  // Infelizmente, a interface exigiu que:
  // (a) saque() seja completamente implementado pela classe derivada; ou
  // (b) saldo seja declarado protected.
  void saque(int senha, double valor) override;
};

class ContaPoupança : public Conta {
private:
  const char *const _type = "Poupança";

public:
  ContaPoupança(int senha, int numero, std::string titular, double saldo);

  const char *type() const override;

  void render(double taxa);
};

#endif
