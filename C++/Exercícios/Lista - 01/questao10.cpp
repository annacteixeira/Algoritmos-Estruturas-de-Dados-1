#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class AcessoNegadoException : public exception {
  private:
    string mensagem;
  public:
    AcessoNegadoException(string msg) : mensagem(msg) {}

    const char* what() const noexcept override {
      return mensagem.c_str();
    }
};

class LoginSistema {
  private:
    string usuario;
    string senha;

  public:
    LoginSistema(string usuario = "", string senha = "") {
      this->usuario = usuario;
      this->senha = senha;
    }

    string getUsuario() const {
      return usuario;
    }

    string getSenha() {
      return senha;
    }

    void setUsuario(string u) {
      usuario = u;
    }

    void setSenha(string s) {
      senha = s;
    }

    bool logar() {
      return verificarLogin(usuario, senha);
    }

    bool logar(string u, string s) {
      usuario = u;
      senha = s;
      return verificarLogin(u, s);
    }

  private:
    bool verificarLogin(string u, string s) {
      if(u.empty() || s.empty()) {
        throw AcessoNegadoException("\nUsuario ou senha nao podem estar vazios");
      }

      if(u != "aluno" || s!= "1234") {
        throw AcessoNegadoException("\nAcesso nao autorizado: usuario ou senha incorretos");
      }

      return true;
    }
};

int main() {
  LoginSistema login;
  string usuario, senha;

  cout << "\n---LOGIN NO SISTEMA---";
  cout << "\nUsuario: ";
  getline(cin, usuario);

  cout<<"\nSenha: ";
  getline(cin, senha);

  try {
    if(login.logar(usuario, senha)) {
      cout << "\nLogin realizado com sucesso!\n";
    }
  } catch(const AcessoNegadoException& e) {
    cout << "\nErro de login: " << e.what() << endl;
  }

  return 0;
}