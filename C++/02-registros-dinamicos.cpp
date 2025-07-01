/*
O operador new também permite criar registros dinâmicos
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
  char nome[20];
  float salario;
  unsigned gols;

} Jogador;

int main(){
  Jogador * j1 = new Jogador;

  /*
    O operador '.' não pode ser usado com ponteiros
    A linguagem oferece o operador ->

    Utiliza-se . com registros
    Utiliza-se -> com ponteiros para registros
  */

  cout << "Informe o nome do jogador: ";
  cin >> j1->nome;
  // Atribuição a um registro dinâmico: strcpy(j1->nome, "Neymar"); //(*pj).nome
  cout << endl << "Informe o salario do jogador: ";
  cin >> j1->salario; // (*pj).salario
  cout << endl << "Informe a quantidade de gols do jogador: ";
  cin >> j1->gols; // (*pj).gols

  cout << "Nome do jogador: " << j1->nome;
  cout << endl << "Salario do jogador: " << j1->salario;
  cout << endl << "Quantidade de gols do jogador: " << j1->gols;

  delete j1;

  Jogador * time = new Jogador[3];

  for(int i = 0; i < 3; i++){
    cout << "\n\nInforme o nome do jogador " << i + 1 << ": ";
    cin >> time[i].nome;

    cout << "\nInforme o salario do jogador " << i + 1 << ": ";
    cin >> time[i].salario;

    cout << "\nInforme a quantidade de gols do jogador " << i + 1 << ": ";
    cin >> time[i].gols;
  }

  for(int i = 0; i < 3; i++){
    cout << "\nJogador " << i + 1 << ": " << time[i].nome << ", salario: " << time[i].salario << ", quantidade de gols: " << time[i].gols << endl;
  }

  delete [] time; // delete de vetor usa colchetes
}