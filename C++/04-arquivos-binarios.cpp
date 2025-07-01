#include <iostream>
#include <fstream>
using namespace std;
/*
Muitas aplicações necessitam:
  - Ocultar a informação armazenada
  - Manter a precisão da informação

Ao abrir um arquivo, pode-se passar o modo de abertura
fin.open("boliche.txt", ios_base::in);

O modo de abertura define como ele será usado:
  - escrita de dados
  - leitura de dados
  - adição de dados
  - modo texto ou binário
*/

/*
ios_base::in -> leitura
ios_base::out -> escrita
ios_base::ate -> escreve no final do arquivo (at the end)
ios_base::app -> adiciona ao final do arquivo (append)
ios_base::trunc -> limpa arquivo, se ele existir
ios_base::binary -> cria arquivo binário

ifstream aceita epnas ios_base::in e ios_base::binary
ofstream aceita todos mas ios_base::in apenas faz com que o arquivo não seja limpo
*/

/*
Se o modo de abertura é omitido, são usados valores padrões:
ifstream: fin.open("boliche.txt", ios_base::in);
ofstream: fout.open("pesca.txt", ios_base::out | ios_base::trunc);

Para escrever dados sem apagar o arquivo:
fout.open("append.txt", ios_base::out | ios_base::app);
*/

/*
A manipulação de arquivos binários é feita com registros
  - O registro se torna o molde usado para gravar e ler informações
*/

typedef struct {
  char nome[50];
  int populacao;
  float gravidade;
} Planeta;

int main() {
  Planeta p = {"Ovolandia", 9000, 10.5};
  ofstream fout;

  fout.open("planetas.dat", ios_base::out | ios_base::binary);
  fout.write((char*) &p, sizeof(Planeta)); //typecast

  fout.close();

  /*
  Para recuperar informação, é preciso usar o mesmo registro
  */

  Planeta planeta_lido;

  ifstream fin;
  fin.open("planetas.dat", ios_base::in | ios_base::binary);
  

  if(fin.is_open()) {
    cout << "Dados do arquivo" << endl;
    while(fin.read((char*) &planeta_lido, sizeof(Planeta))) {
      cout << "Nome do planeta: " << planeta_lido.nome << endl;
      cout << "Populacao do planeta: " << planeta_lido.populacao << endl;
      cout << "Gravidade do planeta: " << planeta_lido.gravidade << endl;
    }
    fin.close();
  }

  
  // Acrescentar mais dados:
  fout.open("planetas.dat", ios_base::out | ios_base::app | ios_base::binary);
  if(!fout.is_open()) {
    cout << "O arquivo nao pode ser aberto!" << endl;
    system("pause");

    return EXIT_FAILURE;
  }

  cout << "\nNome do planeta: ";
  cin >> p.nome;

  cout << "\nPopulacao do planeta: ";
  cin >> p.populacao;

  cout << "\nGravidade do planeta: ";
  cin >> p.gravidade;

  fout.write((char *) &p, sizeof(Planeta));
  fout.close();

  fin.open("planetas.dat", ios_base::in | ios_base::binary);
  if(fin.is_open()) {
    cout << "\nConteudo do arquivo:" << endl;
    while(fin.read((char *) &p, sizeof(Planeta))) {
      cout << p.nome << " " << p.populacao << " " << p.gravidade << " " << endl;
    }
    fin.close();
  }

  return 0;
}