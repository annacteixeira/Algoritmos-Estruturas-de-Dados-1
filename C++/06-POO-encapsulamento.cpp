/*
Classes e tipos

A um tipo é associado:
  - Uma representação: quantidade de memória, organização dos dados, interpretação para os bits
  - Um conjunto de operações: somar / subtrair, multiplicar / dividir, comparar

A classe é a forma do C++ traduzir uma abstração em um tipo definido pelo programador

A classe é definida em duas partes:
  - Declaração: descreve os atributos e métodos
  - Definição: Contém a implementação dos métodos

  Assim como registros, uma classe define um novo tipo

private: seção de membros privados (encapsulamento)
public: seção de membros públicos (interface)

INTERFACE:
Os métodos são também chamados de interface pública - fornecem acesso aos atributos

- Eles fornecem acesso aos dados da classe
- Garantem a integridade dos dados -> protegem contra alterações incorretas dos atributos

A classe encapsula os atributos, eles são ocultados do resto do programa
*/

// Jogo.h -----------------------------------------------------------------------------
#include <string>
using std::string;

class Jogo {
  private:
    string nome;
    float preco;
    int horas;
    float custo;

    void calcular() {
      if(horas > 0) {
        custo = preco / horas;
      }
    }

    public:
      void adquirir(const string & titulo, float valor);
      void atualizar(float valor);
      void jogar(int tempo);
      void exibir();
};

/*
As operações aparecem como métodos da classe
Métodos podem ser definidos inline ou representados por seus protótipos
*/

// Jogo.cpp ---------------------------------------------------------------------------

// definição da classe Jogo
#include <iostream>
#include <Jogo.h>
using namespace std;

void Jogo::adquirir(const string & titulo, float valor) {
  nome = titulo;
  preco = valor;
  horas = 0;
  custo = valor;
}

void Jogo::atualizar(float valor) }{
  preco = valor;
  calcular();
}

void Jogo::jogar(int tempo) {
  horas = horas + tempo;
  calcular();
}

void Jogo::exibir() {
  cout << nome << " R$" << preco << " " << horas << "h = R$" << custo <<"/h\n";
}