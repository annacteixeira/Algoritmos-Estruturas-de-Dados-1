/*
Desenvolva um sistema de comparação de preços de alimentos. Na primeira fase do seu
software, gostaria de criar uma classe que contenha o nome da loja, telefone e preço de um
alimento. Em seguida, irá cadastrar um total de 10 registros e exibir estatísticas desses itens, de
modo que possa verificar o melhor preço (menor valor), o preço médio e o preço máximo. Crie
classes e exiba as informações desejadas.
Utilize os conceitos de classe, atributos, métodos, método construtor. Proteja o acesso aos dados
implementando encapsulamento por meio de métodos get e set. Crie o main, que declara um vetor
de alimentos e que permite ao usuário adicionar nesse vetor informações das lojas e preço
*/

#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
using namespace std;

class EntradaInvalidaException : public exception {
  private:
    string mensagem;
  public:
    EntradaInvalidaException(string msg) : mensagem(msg) {}

    const char* what() const noexcept override {
      return mensagem.c_str();
    }
};

class Alimento {
  private:
    string nomeLoja;
    string telefoneLoja;
    float precoAlimento;

  public:
    Alimento(string nomeLoja, string telefoneLoja, float precoAlimento) {
      if(nomeLoja.empty()) throw EntradaInvalidaException("\nNome da loja nao pode estar vazio");
      if(telefoneLoja.empty()) throw EntradaInvalidaException("\nTelefone da loja nao pode estar vazio");
      if(precoAlimento <= 0) throw EntradaInvalidaException("\nO preco do alimento nao pode ser negativo");

      this->nomeLoja = nomeLoja;
      this->telefoneLoja = telefoneLoja;
      this->precoAlimento = precoAlimento;
    }

    // Getters
    string getNomeLoja() {
      return nomeLoja;
    }

    string getTelefone() {
      return telefoneLoja;
    }
    
    float getPreco() {
      return precoAlimento;
    }
    
    // Setters

    void setNomeLoja(string nomeLoja){
      nomeLoja = nomeLoja;
    }

    void setTelefoneLoja(string telefoneLoja) {
      telefoneLoja = telefoneLoja;
    }

    void setPrecoAlimento(float precoAlimento) {
      precoAlimento = precoAlimento;
    }

    void exibir() {
      cout << "\nLoja: " << nomeLoja << endl;
      cout << "\nTelefone: " << telefoneLoja << endl;
      cout << "\nPreco: R$" << precoAlimento << endl;
    }

};

int main() {
  const int TAM = 10;
  Alimento* alimentos[TAM];
  int cadastrados = 0;

  while(cadastrados < TAM) {
    string nomeLoja, telefoneLoja;
    float precoAlimento;

    cout << "\nCadastro do Alimento " << cadastrados + 1 << endl;

    cout << "Nome da loja: ";
    getline(cin, nomeLoja);

    cout << "Telefone da loja: ";
    getline(cin, telefoneLoja);

    cout << "Preco do alimento: ";
    cin >> precoAlimento;
    cin.ignore();

    try {
      alimentos[cadastrados] = new Alimento(nomeLoja, telefoneLoja, precoAlimento);
      cadastrados++;
    } catch(const EntradaInvalidaException& e){
      cout << "Erro: " << e.what() << "\nTente novamente\n";
    }
  }

  float menorPreco = numeric_limits<float>::max();
  float maiorPreco = numeric_limits<float>::min();

  float soma = 0.0;
  int indiceMenor = 0;
  int indiceMaior = 0;

  for(int i = 0; i < TAM; i++) {
    float precoAtual = alimentos[i]->getPreco();
    soma += precoAtual;

    if(precoAtual < menorPreco) {
      menorPreco = precoAtual;
      indiceMenor = i;
    }

    if(precoAtual > maiorPreco) {
      maiorPreco = precoAtual;
      indiceMaior = i;
    }
  }

  float media = soma / TAM;

  cout << "\n---Estatisticas---" << endl;
  cout << "Menor preco: ";
  alimentos[indiceMenor] -> exibir();

  cout << "\nMaior preco: ";
  alimentos[indiceMaior] -> exibir();

  cout << "Preco medio dos alimentos: R$ " << media << endl;

  for(int i = 0; i < TAM; i++) {
    delete alimentos[i];
  }

  return 0;
}