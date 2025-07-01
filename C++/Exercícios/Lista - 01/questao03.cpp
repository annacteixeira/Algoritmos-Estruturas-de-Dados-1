/*
Crie uma classe para representar uma conta corrente, com métodos para depositar uma
quantia, sacar uma quantia e obter o saldo. Para cada saque será debitada também uma taxa de
operação equivalente à 0.5% do valor sacado. Crie, em seguida, uma subclasse (herdada) da classe
anterior para representar uma conta corrente de um cliente especial. Clientes especiais pagam
taxas de operação de apenas 0.1% do valor sacado.
Utilize os conceitos de classe, atributos, métodos, encapsulamento (get/set), método construtor e
herança. Crie um main com menu, que após o usuário definir o tipo de conta (comum ou especial),
permitirá ao usuário depositar, sacar e mostrar saldo da cota instanciada
*/

#include <iostream>
using namespace std;

class contaCorrente {
  protected:
    float saldo;

  public:
  // construtor
    contaCorrente(float saldoInicial = 0.0) {
      saldo = saldoInicial;
    }

    void depositar(float valor) {
      if(valor > 0) {
        saldo += valor;
        cout << "Depósito de R$" << valor << " realizado com sucesso\n";
      } else {
        cout << "Valor invalido para deposito!" << endl;
      }
    }

    // método virtual -> pode ser sobrescrito por subclasse
    virtual void sacar(float valor) {
      float taxa = valor * 0.005;
      float total = valor + taxa;

      if(total <= saldo) {
        saldo -= total;

        cout << "Saque de R$ " << valor << " realizado com taxa de R$ " << taxa << endl;
      } else {
        cout << "Saldo insuficiente para saque" << endl;
      }
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

      if(total <= saldo) {
        saldo -= total;
        cout << "Saque de R$ " << valor << " realizado com taxa reduzida de R$ " << taxa << endl;
      } else {
        cout << "Saldo insuficiente para saque" << endl;
      }
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
  } while(opcao != 0);

  delete conta;

  return 0;
}