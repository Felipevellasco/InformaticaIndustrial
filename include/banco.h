#ifndef BANCO_H
#define BANCO_H

#include "conta.h"
#include "vector.hpp"

#define NUMCONTAS                                                              \
  100 // Define que a palavar NUMCONTAS passa a valer como escrever 100

enum class AccountType {
  corrente = 0,
  poupança,

  count, // Apenas serve para contar o número de tipos de contas.
};

class Banco {
private:
  u::vector<Conta *> contas;
  uint32_t idCounter;

public:
  Banco();
  ~Banco();
  Conta *buscaConta(int numero); // Metodo que retorna o endereço do objeto
                                 // conta que possui o mesmo numero informado
  void atendimento();
  bool criaConta(std::string titular, int senha, AccountType tipo, double saldo);
  int removeConta(int numero);

  void closeMonth();
};

#endif
