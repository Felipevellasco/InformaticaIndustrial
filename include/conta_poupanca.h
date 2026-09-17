#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include "conta.h"

class ContaPoupança : public Conta {
private:
  const char *const _type = "Poupança";
  void _render(double taxa);

public:
  ContaPoupança(int senha, int numero, std::string titular, double saldo);

  const char *type() const override;
  void aplicaOperacaoMensal() override;
};

#endif
