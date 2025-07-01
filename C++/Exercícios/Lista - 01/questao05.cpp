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

class Cliente {
  private:
    string nome;
    string dataNascimento;
    string endereco;
    string telefone;

  public:
    // Construtor
    Cliente(string nome, string dataNascimento, string endereco, string telefone) {

      if(nome.empty()) throw EntradaInvalidaException("Nome nao pode estar vazio\n");
      if(endereco.empty()) throw EntradaInvalidaException("Endereco nao pode estar vazio\n");
      if(telefone.empty()) throw EntradaInvalidaException("Telefone nao pode estar vazio\n");
      if(dataNascimento.size() != 10 || dataNascimento[2] != '/' || dataNascimento[5] != '/') throw EntradaInvalidaException("Data de nascimento deve estar no formato DD/MM/AAAA");
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
  int cadastrados = 0;

  while(cadastrados < tam) {
    string nome, dataNascimento, endereco, telefone;

    cout << "\nCadastro do cliente " << cadastrados + 1 << endl;

    cout << "\nNome: ";
    getline(cin, nome);

    cout << "\nData de nascimento: ";
    getline(cin, dataNascimento);

    cout << "Endereco: ";
    getline(cin, endereco);

    cout << "Telefone: ";
    getline(cin, telefone);

    try {
      clientes[cadastrados] = new Cliente(nome, dataNascimento, endereco, telefone);
      cadastrados++;
    } catch (const EntradaInvalidaException & e) {
      cout << "Erro ao cadastrar cliente: " << e.what() << "\nTente novamente\n";
    }
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