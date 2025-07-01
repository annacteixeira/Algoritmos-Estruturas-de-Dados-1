#include <iostream>
#include <fstream>
using namespace std;

/*
Frequentemente a entrada de dados é feita pelo teclado e a saída de dados é feita em tela
A entrada de dados pelo teclado nem sempre é a melhor solução:
  Imagine usar o teclado para entrar com nome, preço e quantidade em estoque de 1000 produtos

As vezes a saída de dados na tela não é a melhor opção:
  Seria conveniente gerar uma lista de produtos fora de estoque em um arquivo

Os programas de computador trabalham com arquivos
  Documentos, planilhas, apresentações, imagens, vídeos, sons, etc.
  Compiladores lêem o arquivo fonte de um programa e geram um arquivo executável

Um arquivo é um conjunto de bits guardado em algum dispositivo de armazenamento permanente

O SO se encarrega de gerenciar os arquivos
Como programador estamos interessados em conectar um programa a um arquivo para: 
  Ler informações do arquivo
  Gravar informações no arquivo

Os arquivos se dividem em: arquivos texto e arquivos binários
*/

/*
ARQUIVOS TEXTO:
- Sequência de bits em que n bits representam um caractere
- Na codificação ASCII, 1 caractere = 8 bits
- Em Unicode, um caractere tem de 8 a 32 bits

ARQUIVOS BINÁRIOS:
- Sequência de bits em que um conjunto de n bits representa uma informação na sua forma nativa (inteira, ponto-flutuante, caractere, etc.)

*/

/*
A entrada e saída em arquivos texto é muito parecida com a entrada e saída feita no terminal de comandos

1. Incluir o arquivo de inclusão fstream
  Define uma classe ofstream para manipular a saída

2. Criar um objeto do tipo ofstream

3. Associar um objeto ofstream com um arquivo do disco usando a função open()

4. Usar o operador de inserção << com o objeto ofstream

5. Fechar o arquivo com a função close()
*/

int main() {
  ofstream fout; // objeto ofstream
  char arquivo[50];

  cout << "Informe o nome do arquivo que voce deseja gravar: ";
  cin >> arquivo;

  fout.open(arquivo); // fout associado ao arquivo lorem.txt

  if (!fout.is_open()) {
    cerr << "Erro ao abrir o arquivo!" << endl;
    return 1;
  } else {
    cout << "Arquivo aberto com sucesso!" << endl;
  }

  double wt = 125.8;
  char linha[81] = "Objetos são variáveis de uma classe";

  fout << wt << '\n'; // escreve um número
  fout << linha << endl; // escreve uma linha de texto

  fout.close();

  // ###########################################################################

  char carro[50];
  int ano;
  float precoNormal;
  float precoPromocional;

  fout.open("carrinho.txt");

  fout.precision(2);

  fflush(stdin);
  cout << "Entre com a marca e modelo do carro: ";
  cin.getline(carro, 50); // lê uma linha inteira de texto até encontrar um caractere delimitador ou fim de linha
  fflush(stdin);

  cout << "\nEntre com o ano: ";
  cin >> ano;

  cout << "\nDigite o preco normal: ";
  cin >> precoNormal;

  precoPromocional = precoNormal - (precoNormal * 0.2);

  fout << "Marca e modelo do carro: " << carro;
  fout << "\nAno do carro: " << ano;
  fout << "\nPreco normal: " << precoNormal;
  fout << "\nPreco promocional = " << precoPromocional << endl;

  fout.close();

  /*
  OBSERVAÇÕES:
  - O método open() cria um novo arquivo se ele não existir ou sobrescreve o arquivo, se ele existir
  - A abertura de um arquivo pode falhar caso o arquivo utilizado seja um arquivo de acesso restrito
    - Um arquivo já aberto em outro programa
    - Um arquivo protegido pelo SO
  */

  // ####################################################################################
  // LEITURA de arquivos texto

  /*
  1. Incluir o arquivo fstream
  2. Definir uma classe ifstream
    Não existe um objeto predefinido
  
  3. Criar um objeto do tipo ifstream
  4. Associar um objeto ifstream com um arquivo do disco usando a função open()
  5. Usar o operador de extração >>, o método get() ou o método getline()
  6. Fechar o arquivo com a função close()
  */

  /*
  Se o arquivo não existir no disco, todas as tentativas de uso do objeto ifstream vão falhar

  */

  ifstream fin;
  fin.open("boliche.txt");
  if(!fin.is_open()) {
    cout << "A abertura do arquivo falhou!" << endl;
    exit(EXIT_FAILURE);
  }

  double num;
  char linha_lida[81];

  fin >> num; // lê um número de carrinho.txt
  fin.getline(linha_lida, 81); // lê uma linha de texto

  fin.close();

  // #############################################################################

  fin.open("numeros.txt");

  if (!fin.is_open()) {
    cout << "A abertura do arquivo falhou!" << endl;
    exit(EXIT_FAILURE);
  }

  double valor;
  double soma = 0.0;
  int cont = 0;

  while (fin >> valor) {
    ++cont;
    soma += valor;
  }

  if (fin.eof()) {
    cout << "\nFim do arquivo alcançado\n";
  } else if (fin.fail()) {
    cout << "\nTipo incorreto de dado na entrada\n";
  } else {
    cout << "\nEntrada encerrada por razão desconhecida\n";
  }

  cout << "Quantidade de numeros lidos: " << cont << endl;
  cout << "Soma dos valores: " << soma << endl;

  fin.close();
  return 0;
}