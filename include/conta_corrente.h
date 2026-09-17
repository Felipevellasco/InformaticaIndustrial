#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "conta.h"

class ContaCorrente : public Conta {
private:
  const char *const _type = "Corrente";

public:
  ContaCorrente(int senha, int numero, std::string titular, double saldo);

  const char *type() const override;
  void aplicaOperacaoMensal() override;

  // Saque com limite de cheque especial (R$500,00)
  // Infelizmente, a interface exigiu que:
  // (a) saque() seja completamente implementado pela classe derivada; ou
  // (b) saldo seja declarado protected.
  void saque(int senha, double valor) override;
};

#endif
