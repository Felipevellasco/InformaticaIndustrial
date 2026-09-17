# Informática Industrial - 2026.3

Este repositório armazena as versões e implementações dos exercícios de informática industrial da UFJF feitos por mim.  

## Instruções para compilação

O repositório utiliza um framework de execução de comandos chamado [Just](https://github.com/casey/just).  

Para compilar, basta digitar no terminal:
```bash
just build # para compilar em modo 'release'

# OU

just run # para compilar em modo debug e executar o arquivo imediatamente
```

A saída padrão do programa compilado é na pasta `.build/`, com artefato de nome `main`.

Caso queira saber quais outros comandos foram configurados, você pode verificar o [justfile](justfile) ou simplesmente
abrir um terminal e digitar:
```bash
just
```
que, por padrão, exibirá uma lista de comandos disponíveis.

## Respostas: exercício 2
### Parte 1: escolha do método de crescimento do vetor

```cpp
  // Aumenta em 2x o número de espaços necessários para adicionar o valor no
  // índice pedido pelo usuário; caso o vetor precise crescer, é muito provável
  // que o usuário peça por mais memória posteriormente. Dessa forma,
  // incrementar o vetor em mais espaços que o pedido previne alocações
  // dinâmicas recorrentes, que podem atrasar consideravelmente o código
  // considerando o tamanho do vetor original (que precisa ser copiado).
```

Comentário presente em [vector.hpp](include/vector.hpp#L44).

### Parte 1: por que usar ponteiros no vetor?

```cpp
  // O uso de ponteiros permite que os objetos tenham polimorfismo através de
  // herança. Isso traz a possibilidade de implementar tipos especializados de
  // objetos. Exemplo: uma conta polimórfica pode ser do tipo conta corrente ou
  // conta poupança.
```

Comentário presente em [banco.cpp](src/banco.cpp#L137).

### Parte 3: por que o destrutor virtual?

```cpp
  // O destrutor virtual faz com que os destrutores de todas as subclasses sejam
  // chamados em ordem, destruindo os objetos em camadas. Isso impede que haja
  // um vazamento de memória caso a classe base possua alocação dinâmica.
  // Exemplo: imagine que a minha implementação de vector seja usada como base
  // para uma nova classe. Sem o destrutor virtual ou a palavra "final" para
  // impedir herança, caso o objeto que herda a classe seja destruído com delete
  // ou por redução da stack, a memória alocada ficará órfã, pois o ponteiro
  // _data será perdido sem que o operador delete[] seja chamado.
```

Comentário presente em [conta.h](include/conta.h#L20).
