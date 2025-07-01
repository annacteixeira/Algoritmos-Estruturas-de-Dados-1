// Existem duas formas de alocar memória:

/*
  1. Alocação automática: declaração de variáveis
  2. Alocação dinâmica: 
    alocar memória com o operador new
    guardar o endereço da memória em um ponteiro
    usar o ponteiro para acessar e modificar os dados
    liberar memória com o operador delete
*/

/*
int *pi = new int;
-> alocado 4 bytes

*/

/*
Toda memória alocada deve ser liberada ao final do uso
Deve-se manter new e delete sempre balanceados
  caso contrário, tem-se um vazamento de memória

O operador delete permite retornar a memória não mais utilizada para o sistema
O delete libera a memória mas não destrói o ponteiro
O ponteiro pode ser usado para novas alocações
*/

#include <iostream>
using namespace std;

void PrintNum(char ch) {
  int * p = new int { ch }; // aloca memória atribuindo valor: list initialization. nesse caso, aloca um int na heap com o valor ASCII do caractere
  cout << *p << endl;
  
  delete p;

  // é muito fácil esquecer o delete, por exemplo, ao sair da função
}

// CUIDADO com funções que alocam memória

int * GetNum(char ch) { // aloca memória e retorna um ponteiro para essa memória
  int * p = new int { ch };
  return p;
}

int main() {
  int * pi = new int; // alocação dinâmica
  *pi = 1001;

  cout << "Valor inteiro = " << *pi << endl;
  cout << "Localizacao = " << pi << endl << endl;

  double * pd = new double; // alocação dinâmica
  *pd = 500.35;

  cout << "Valor ponto-flutuante = " << *pd << endl;
  cout << "Localizacao = " << pd << endl << endl;

  cout << "Tamanho de pi = " << sizeof(pi) << endl; // máquina de 32 bits = 4, máquina de 64 bits = 8
  cout << "Tamanho de *pi = " << sizeof(*pi) << endl << endl; // tamanho do elemento apontado
  cout << "Tamanho de pd = " << sizeof(pd) << endl; // máquina de 32 bits = 4, máquina de 64 bits = 8
  cout << "Tamanho de *pd = " << sizeof(*pd) << endl << endl; // tamanho do elemento apontado

  delete pi;
  delete pd;

  PrintNum('A');

  int * p = new int; // aloca memória
  *p = 30;
  cout << *p << endl;
  delete p; // libera memória

  // se esse delete for esquecido, ocorre um memory leak

  p = new int; // aloca memória
  *p = 50;
  cout << *p << endl;
  delete p; // libera memória

  int * pnum = GetNum('A');
  cout << *pnum << endl;
  delete pnum; // lembrar de liberar a memória

  pnum = GetNum('B');
  cout << *pnum << endl;
  delete pnum; // lembrar de liberar a memória

  // Não se pode liberar o mesmo bloco de memória duas vezes

  int * num = new int;

  *num = 33;
  cout << *num << endl << endl;

  delete num; // libera memória
  // delete num; -> resultado indefinido

  /*
  É fácil esquecer que a memória já foi liberada
    Cuidado com múltiplos apontadores
  */

  int * ptr = new int { 40 };
  int * aux = ptr;

  cout << *aux << endl;
  delete aux;

  /*
  cout << *ptr << endl; // ptr aponta para memória inválida
  delete ptr; // memória já foi liberada
  */
  

  return 0;

  /*
  Cuidado com memória compartilhada entre funcções

  void processar(int * p){
    usou *p mas esqueceu que outra função também fará uso dessa memória

    delete p;
  }

  void exibir(int * p) {
    p aponta para memória inválida

    cout << *p << endl;
    delete p;
  }

  int main() {
    int * ptr = new int;
    *ptr = 40;

    processar(ptr);
    exibir(ptr);

    delete ptr;
  }
  */

  int tam;
  cout << "Digite o tamanho do vetor: ";
  cin >> tam;

  int * vet = new int [tam];
  
  delete [] vet;
}