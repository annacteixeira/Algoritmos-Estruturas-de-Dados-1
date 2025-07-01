#include <iostream>
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

class contaCorrente {
  protected:
    float saldo;

  public:
  // construtor
    contaCorrente(float saldoInicial = 0.0) {
      saldo = saldoInicial;
    }

    void depositar(float valor) {
      if(valor <= 0) {
        throw EntradaInvalidaException("\nDeposito invalido: o valor deve ser maior que zero");
      }

      saldo += valor;
      cout << "Depósito de R$" << valor << " realizado com sucesso\n";
    }

    // método virtual -> pode ser sobrescrito por subclasse
    virtual void sacar(float valor) {

      if(valor <= 0) {
        throw EntradaInvalidaException("\nSaque invalido: o valor deve ser maior que zero");
      }
      float taxa = valor * 0.005;
      float total = valor + taxa;

      if(total > saldo) {
        throw EntradaInvalidaException("\nSaldo insuficiente para o saque");
      }

      saldo -= total;
      cout << "Saque de R$ " << valor << " realizado com taxa de R$ " << taxa << endl;

    }

    float getSaldo() const {
      return saldo;
    }

};

class contaCorrenteEspecial : public contaCorrente {
  public:
    contaCorrenteEspecial(float saldoInicial = 0.0) : contaCorrente(saldoInicial) {}

    void sacar(float valor) override {
      float taxa = valor * 0.001;
      float total = valor + taxa;

      if(total > saldo) {
      throw EntradaInvalidaException("\nSaldo insuficiente para o saque");
      }

      saldo -= total;
      cout << "Saque de R$ " << valor << " realizado com taxa reduzida de R$ " << taxa << endl;
    }
};

int main() {
  contaCorrente* conta = nullptr;
  int tipo;

  cout << "Escolha o tipo de conta\n";
  cout << "1 - Conta comum\n";
  cout << "2 - Conta especial\n";
  cout << "Opcao: ";
  cin >> tipo;

  if(tipo == 1) {
    conta = new contaCorrente();
  } else if(tipo == 2) {
    conta = new contaCorrenteEspecial();
  } else {
    cout << "\nOpcao invalida!\n";
    return 1;
  }

  int opcao;
  float valor;

  do {
    cout << "1 - Depositar\n";
    cout << "2 - Sacar\n";
    cout << "3 - Mostrar saldo\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao;

    try {
        switch(opcao) {
        case 1:
          cout << "\nInforme o valor a depositar: ";
          cin >> valor;

          conta->depositar(valor);
          break;

        case 2:
          cout << "\nInforme o valor a sacar: ";
          cin >> valor;

          conta->sacar(valor);
          break;

        case 3:
          cout << "\nSaldo: R$" << conta->getSaldo() << endl;
          break;

        case 0:
          cout << "\nSaindo...";
          break;

        default:
          cout << "\nOpcao invalida!\n";
      }
    } catch(const EntradaInvalidaException& e) {
      cout << "\nErro: "<< e.what() << endl;
    }
    
  } while(opcao != 0);

  delete conta;

  return 0;
}