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
using namespace std;

class Alimento {
  private:
    string nomeLoja;
    string telefoneLoja;
    float precoAlimento;

  public:
    Alimento(string nomeLoja, string telefoneLoja, float precoAlimento) {
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

  for(int i = 0; i < TAM; i++) {
    string nomeLoja, telefoneLoja;
    float precoAlimento;

    cout << "\nCadastro do Alimento " << i + 1 << endl;

    cout << "Nome da loja: ";
    getline(cin, nomeLoja);

    cout << "Telefone da loja: ";
    getline(cin, telefoneLoja);

    cout << "Preco do alimento: ";
    cin >> precoAlimento;
    cin.ignore();

    alimentos[i] = new Alimento(nomeLoja, telefoneLoja, precoAlimento);
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