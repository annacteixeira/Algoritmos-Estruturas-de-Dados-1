/*
  1. Escreva um programa para cadastrar clientes de uma loja. As informações necessárias são:
  nome, data de nascimento, endereço e telefone. Devem ser usada classes para a construção deste
  cadastro.
  Utilize os conceitos de classe, atributos e método construtor. Crie o main, que declara um vetor de
  clientes e que permite ao usuário adicionar os clientes nesse vetor. O tamanho do vetor deverá
  ser definido pelo usuário
*/

#include <iostream>
#include <string>
using namespace std;

class Cliente {
  private:
    string nome;
    string dataNascimento;
    string endereco;
    string telefone;

  public:
    // Construtor
    Cliente(string nome, string dataNascimento, string endereco, string telefone) {
      this->nome = nome;
      this->dataNascimento = dataNascimento;
      this->endereco = endereco;
      this->telefone = telefone;
    }

    // Método

    void exibirCliente() {
      cout << "\n---Dados do cliente---" << endl;
      cout << "Nome: " << nome << endl;
      cout << "Data de nascimento: " << dataNascimento << endl;
      cout << "Endereco: " << endereco << endl;
      cout << "Telefone: " << telefone << endl;
    }
};

int main() {
  int tam;

  cout << "Informe a quantidade de clientes que voce deseja cadastrar: ";
  cin >> tam;
  cin.ignore();

  Cliente* clientes[100];

  for(int i = 0; i < tam; i++) {
    string nome, dataNascimento, endereco, telefone;

    cout << "\nCadastro do cliente " << i + 1 << endl;

    cout << "Nome: ";
    getline(cin, nome);

    cout << "\nData de nascimento: ";
    getline(cin, dataNascimento);

    cout << "\nEndereco: ";
    getline(cin, endereco);

    cout << "\nTelefone: ";
    getline(cin, telefone);

    clientes[i] = new Cliente(nome, dataNascimento, endereco, telefone);
  }

  cout << "\n---Lista de clientes---" << endl;
  for(int i = 0; i < tam; i++) {
    clientes[i]->exibirCliente();
  }

  for(int i = 0; i < tam; i++) {
    delete clientes[i];
  }

  return 0;
}