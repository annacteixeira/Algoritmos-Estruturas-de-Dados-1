/*
Programação Orientada a Objetos

  É uma abordagem para o desenvolvimento de programas baseada nas ideias de:
    - Abstração
    - Encapsulamento
    - Polimorfismo
    - Herança

  Um dos principais objetivos dessa abordagem é melhorar e facilitar o reuso de código

  Na POO, as funções não precisam indicar sobre qual dado agir. Elas sempre agem sobre os dados associados
*/

/*
Abstração

Um dos pilares da orientação a objetos é a abstração.

Abstração é a habilidade de concentrar nos aspectos essenciais de um contexto qualquer, ignorando características menos importantes
ou acidentais

Exemplo 1: Carro em um jogo 2D
-> O carro em um jogo é uma abstração de um veículo real
-> Dados: cor, tamanho
-> Funções: acelerar, frear

Exemplo 2: Carro em um jogo 3D
-> Dados: cor, marca, modelo, velocidade, aceleração
-> Funções: esterçar, acelerar, frear, nitro

Exemplo 3: Carro em uma simulação 3D
-> Motor: potência, consumo
-> Pneus: aderência, temperatura, pressão, desgaste
*/

/*
A POO abstrai os problemas em Classes e Objetos

-> Carro é uma classe
  Ele tem características:
    cor, tipo, velocidade máxima  = ATRIBUTOS
  
  Podemos definir operações sobre ele:
    acelerar, frear, ligar = MÉTODOS


Uma classe representa vários objetos

Exemplo:
class Carro {
  private:
    int cor;
    string tipo;
    float velocidade;
  
  public:
    void ligar();
    void desligar();
    void acelerar();
    void frear();
}

Objetos do tipo Carro:
- Amarelo Esporte 180km/h
- Vermelho Transporte 120km/h
- Verde Passeio 140km/h

Classes e objetos abstraem o mundo real

class Pessoa {
  private:
    string nome;
    int idade;
    float altura;

  public:
    void comer();
    void trabalhar();
    void divertir();
    void dormir();
}
*/

/*
A POO abstrai objetos através de uma classe
Uma classe agrupa/reúne/associa
  - Dados: atributos da classe
  - Funções: métodos da classe

  Objetos são representantes de uma classe
*/

/*
EXERCÍCIOS DE FIXAÇÃO

1. Defina uma classe para representar uma conta bancária. Os dados membros da classe devem incluir o nome
do cliente (string), o número da conta (int) e o saldo (float)

As funções devem permitir:
a. criar e inicializar um objeto
b. exibir os dados da conta
c. depositar dinheiro
d. sacar dinheiro
*/

#include <iostream>
using namespace std;

int main() {
  class contaBancaria {
    private:
      string cliente;
      int numConta;
      float saldo;

    public:
      void criarConta(string nome, int numeroConta, float saldoInicial);
      void exibirDados();
      void depositarDinheiro(float valor);
      void sacarDinheiro(float valor);
  };
}