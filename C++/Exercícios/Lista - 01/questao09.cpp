/*
6. Escreva uma classe em C++ que gerencie jogos de loteria lotofacil. A classe deve permitir a
escolha de 15 números que variam de 1 a 25. A escolha de um número deve ser feita em um
método especializado. Caso o escolhido seja repetido, inferior a 1 ou superior a 25 seja escolhido,
o sistema deve gerar uma exceção nesse método, que deve ser propagada e tratada no
procedimento principal (main)
*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class EntradaInvalidaException : public exception {
  private:
    string mensagem;
  public:
    EntradaInvalidaException(const string& msg) : mensagem(msg) {}
    const char* what() const noexcept override {
      return mensagem.c_str();
    }
};

class Lotofacil {
  private:
    vector<int> numerosEscolhidos;
  public:
    void escolherNumero(int numero) {
      if(numero < 1 || numero > 25){
        throw EntradaInvalidaException("\nO numero deve ser de 1 a 25");
      }

      for(int n : numerosEscolhidos) {
        if(n == numero) {
          throw EntradaInvalidaException("\nEsse numero ja foi escolhido");
        }
      }

      if(numerosEscolhidos.size() >= 15) {
        throw EntradaInvalidaException("Ja foram escolhidos os 15 numeros");
      }

      numerosEscolhidos.push_back(numero);
      cout << "Numero " << numero << " adicionado com sucesso\n";
    }

    void mostrarJogo() const {
      cout << "\nNumeros escolhidos: ";
      for(int n : numerosEscolhidos) {
        cout << n << " ";
      }
      cout << endl;
    }

    int getQuantidade() const {
      return numerosEscolhidos.size();
    }
};

int main() {
  Lotofacil jogo;
  int numero;

  cout << "Lotofacil - Escolha 15 numeros entre 1 e 25\n";

  while(jogo.getQuantidade() < 15) {
    if(cin.eof()) break;

    cout << "\nDigite um numero: ";
    cin >> numero;

    try {
      jogo.escolherNumero(numero);
    } catch(const EntradaInvalidaException& e) {
      cout << "Erro: " << e.what() << endl;
    }

    if(cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Entrada invalida. Digite um numero inteiro\n";
      continue;
    }

    if(cin.peek() == '\n') {
      cin.ignore();
    }

    cout << "\nTodos os 15 numeros foram escolhidos!" << endl;
    jogo.mostrarJogo();
  }

  return 0;
}
