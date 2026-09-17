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

  // O destrutor virtual faz com que os destrutores de todas as subclasses sejam
  // chamados em ordem, destruindo os objetos em camadas. Isso impede que haja
  // um vazamento de memória caso a classe base possua alocação dinâmica.
  // Exemplo: imagine que a minha implementação de vector seja usada como base
  // para uma nova classe. Sem o destrutor virtual ou a palavra "final" para
  // impedir herança, caso o objeto que herda a classe seja destruído com delete
  // ou por redução da stack, a memória alocada ficará órfã, pois o ponteiro
  // _data será perdido sem que o operador delete[] seja chamado.
  virtual ~Conta();

  virtual const char *type() const = 0;
  virtual void aplicaOperacaoMensal() = 0;

  virtual void saque(int senha, double valor);

  // Não declarei virtual pois é muito mais simples imprimir os dados
  // diretamente na classe; basta utilizar um método virtual type() (conforme
  // implementado) para coletar o tipo da subclasse e manter a implementação
  // atual. Como a única alteração na classe é o tipo, virtualizar este método
  // dá mais trabalho do que necessário.
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
  void aplicaOperacaoMensal() override;

  // Saque com limite de cheque especial (R$500,00)
  // Infelizmente, a interface exigiu que:
  // (a) saque() seja completamente implementado pela classe derivada; ou
  // (b) saldo seja declarado protected.
  void saque(int senha, double valor) override;
};

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
