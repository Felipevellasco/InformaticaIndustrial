#include "banco.h"
#include "conta.h"
#include <iostream>

using namespace std;

Banco::Banco() // O construtor criara 4 contas
{
  criaConta("Joao", 1234, AccountType::corrente, 300);
  criaConta("Jose", 4567, AccountType::poupança, 800);
  criaConta("Maria", 7890, AccountType::corrente, 1000);
  criaConta("Madalena", 8956, AccountType::poupança, 2000);
}

Banco::~Banco() {
  for (int i = 0; i < contas.size(); i++) {
    auto &conta = contas[i];

    delete conta;
    conta = nullptr;
  }
}

bool Banco::criaConta(std::string titular, int senha, AccountType tipo,
                      double saldo) {
  Conta *newAccount = nullptr;

  switch (tipo) {
    using enum AccountType;
  case corrente:
    newAccount = new ContaCorrente(senha, idCounter, titular, 0.0f);
    break;
  case poupança:
    newAccount = new ContaPoupança(senha, idCounter, titular, 0.0f);
    break;

  case count:
    [[fallthrough]];
  default:
    std::cout << "Tipo inválido!" << std::endl;
    return false;
  }

  this->contas.push_back(newAccount);
  return true;
}

Conta *Banco::buscaConta(int numero) // Retorna o endereço da conta que possuir
                                     // o mesmo numero informado
{
  for (int i = 0; i < NUMCONTAS; i++) {
    if (numero == this->contas[i]->numero) {
      return this->contas[i];
    }
  }

  return nullptr;
}

void Banco::atendimento() // Realiza o atendimento ao cliente(Função chamada na
                          // main)
{
  Conta *contaCliente;
  int numC = 0;
  int senhain;
  bool atendimento = true;

  cout << "Bem vindo ao sistema de atendimento do banco" << endl;
  cout << "Digite o numero da sua conta: ";
  cin >> numC;

  contaCliente =
      this->buscaConta(numC); // Chama o Metodo buscaConta() do banco para achar
                              // o objeto conta que possui o numero numC

  if (contaCliente ==
      nullptr) // Se não achar nenhuma conta que corresponda entra nesse if
  {
    cout << "Conta invalida" << endl;
  } else {
    cout << "Digite a sua senha: ";
    cin >> senhain;

    if (contaCliente->validaSenha(senhain)) {
      cout << "Ola " << contaCliente->titular << endl;
      while (atendimento) // Realiza o atendimento
      {
        int op;
        double valor;
        cout << "Qual operacao deseja fazer? (1 - Saque, 2 - Deposito, 3 - Ver "
                "Saldo, 4 - Sair): ";
        cin >> op;
        switch (op) {
        case 1:
          cout << "Digite o valor: ";
          cin >> valor;
          contaCliente->saque(senhain, valor);
          break;
        case 2:
          cout << "Digite o valor: ";
          cin >> valor;
          contaCliente->deposito(valor);
          break;
        case 3:
          cout << "Saldo: R$ " << contaCliente->getSaldo(senhain) << endl;
          break;
        case 4:
          atendimento = false;
          break;
        }
      }
    } else {
      cout << "Senha invalida" << endl;
    }
  }
}

int Banco::removeConta(int numero) {
  int index = 0;
  for (; index < contas.size(); index++)
    if (contas[index]->numero == numero) {
      break;
    }

  if (index == contas.size())
    return 1;

  Conta *conta = contas.pop(index);

  delete conta;

  return 0; // Não entendi: por que retornar int??

  // Por que guardamos ponteiros?
  //
  // Resposta:
  // O uso de ponteiros permite que os objetos tenham polimorfismo através de
  // herança. Isso traz a possibilidade de implementar tipos especializados de
  // objetos. Exemplo: uma conta polimórfica pode ser do tipo conta corrente ou
  // conta poupança.
}
