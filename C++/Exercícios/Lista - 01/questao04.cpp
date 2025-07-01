#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
  protected:
    string nome;
    string raca;
    int idade;
    float preco;

  public:
    Animal(string nome, string raca, int idade, float preco) {
      this->nome = nome;
      this->raca = raca;
      this->idade = idade;
      this->preco = preco;
    }

    virtual ~Animal(){}

    string getNome() const {
      return nome;
    }

    string getRaca() const {
      return raca;
    }

    int getIdade() const {
      return idade;
    }

    float getPreco() const {
      return preco;
    }

    void setNome(string nome) {
      nome = nome;
    }

    void setRaca(string raca) {
      raca = raca;
    }

    void setIdade(int idade) {
      idade = idade;
    }

    void setPreco(float preco) {
      preco = preco;
    }

    virtual void exibir() const {
      cout << "Nome = " << nome << ", raca = " << raca << ", idade = " << idade << ", preco = " << preco << endl;
    }
};

class Cachorro : public Animal {
  public:
    Cachorro(string nome, string raca, int idade, float preco) : Animal(nome, raca, idade, preco) {}

    void exibir() const override {
      cout << "\nCachorro\n";
      Animal::exibir();
    }
};

class Gato : public Animal {
  public:
    Gato(string nome, string raca, int idade, float preco) : Animal(nome, raca, idade, preco) {}

    void exibir() const override {
      cout << "\nGato\n";
      Animal::exibir();
    }
};

class PetShop {
  private:
    vector<Animal*> animais;

  public:
    ~PetShop() {
      for(Animal* a: animais){
        delete a;
      }
    }

    void adicionarAnimal(Animal* a) {
      animais.push_back(a);
      cout << "\nAnimal adicionado com sucesso\n";
    }

    void listarAnimais() const {
      if(animais.empty()) {
        cout << "Nenhum animal cadastrado\n";
        return;
      }

      for(size_t i = 0; i < animais.size(); i++){
        cout << "\n ID: " << i;
        animais[i]->exibir(); 
      }
    }

    void atualizarAnimal(int id) {
      if(id < 0 || id >= animais.size()) {
        cout << "ID inválido\n";
        return;
      }

      string nome, raca;
      int idade;
      float preco;

      cout << "\nNovo nome: ";
      cin.ignore();
      getline(cin, nome);

      cout << "\nNova raca: ";
      getline(cin, raca);

      cout << "\nNova idade: ";
      cin >> idade;

      cout << "\nNovo preco: ";
      cin >> preco;

      animais[id]->setNome(nome);
      animais[id]->setRaca(raca);
      animais[id]->setIdade(idade);
      animais[id]->setPreco(preco);

      cout << "Animal atualizado com sucesso!\n";
    }

    void removerAnimal(int id) {
      if(id < 0 || id >= animais.size()) {
        cout << "ID inválido\n";
        return;
      }

      delete animais[id];
      animais.erase(animais.begin() + id);
      cout << "Animal removido com sucesso!\n";
    }
};

int main() {
  PetShop loja;

  int opcao;

  do {
    cout <<"1 - Adicionar cachorrro\n";
    cout <<"2 - Adicionar gato\n";
    cout << "3 - Listar animais\n";
    cout << "4 - Atualizar animal\n";
    cout << "5 - Remover animal\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";

    cin >> opcao;

    if(opcao == 1 || opcao == 2) {
      string nome, raca;
      int idade;
      float preco;

      cin.ignore();
      cout << "\nNome: ";
      getline(cin, nome);

      cout << "\nRaca: ";
      getline(cin, raca);

      cout << "\nIdade: ";
      cin >> idade;

      cout << "\nPreco: ";
      cin >> preco;

      if(opcao == 1) {
        loja.adicionarAnimal(new Cachorro(nome, raca, idade, preco));
      } else {
        loja.adicionarAnimal(new Gato(nome, raca, idade, preco));
      }
    } else if(opcao == 3) {
      loja.listarAnimais();
    } else if(opcao == 4) {
      int id;
      cout << "\nInforme o ID do animal a atualizar: ";
      cin >> id;
      loja.atualizarAnimal(id);
    } else if(opcao == 5) {
      int id;
      cout << "\nInforme o ID do animal a remover: ";
      cin >> id;
      loja.removerAnimal(id);
    } else if(opcao == 0) {
      cout << "Saindo...\n";
    } else {
      cout << "Opcao invalida!\n";
    }
  } while(opcao != 0);

  return 0;
}