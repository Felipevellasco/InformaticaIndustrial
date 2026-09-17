#ifndef BANCO_H
#define BANCO_H

#include "conta.h"
#include "vector.hpp"

#define NUMCONTAS 100 //Define que a palavar NUMCONTAS passa a valer como escrever 100

class Banco
{
private:
    u::vector<Conta*> contas;

public:
    Banco();
    ~Banco();
    Conta* buscaConta(int numero); //Metodo que retorna o endereço do objeto conta que possui o mesmo numero informado
    void atendimento();
};


#endif
