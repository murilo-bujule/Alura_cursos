/*************************************************
ALGORITMO: JOGO DA FORCA
DADOS DE ENTRADA:
    palavra_secreta (const string) - Palavra a ser adivinhada
    tentativas_maximas (int) - Número máximo de tentativas
    chute (char) - Palpite do jogador

VARIÁVEIS DE AUXÍLIO:
    nao_acertou (bool) - Indica se a palavra foi adivinhada corretamente
    nao_enforcou (bool) - Indica se o jogador ainda tem tentativas restantes
    chutou (map<char, bool>) - Mapa que armazena os palpites do jogador)
    chutes_errados (vector<char>) - Vetor que armazena os palpites errados do
jogador

DADOS DE SAÍDA:
    (Mesma de entrada) palavra_secreta (const string) - Palavra a ser adivinhada

**************************************************/

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void Clear();
void introducao();
bool letra_existe(char, string);
bool nao_acertou(string, map<char, bool> &);
bool nao_enforcou(vector<char> &);
void imprime_palavra_secreta(string, map<char, bool> &);
void imprime_chutes_errados(vector<char> &);
void chuta(vector<char> &, map<char, bool> &, string);
vector<string> le_arquivo(vector<string> &);
string sorteia_palavra(vector<string> &, string);
void adiciona_palavra(vector<string> &);
void salva_arquivo(vector<string> &);

int main() {
  string palavra_secreta = "EU NAO DEVERIA SER UMA OPCAO";
  map<char, bool> chutou;
  vector<char> chutes_errados;
  vector<string> lista_palavras;

  introducao();
  le_arquivo(lista_palavras);
  palavra_secreta = sorteia_palavra(lista_palavras, palavra_secreta);

  while (nao_acertou(palavra_secreta, chutou) && nao_enforcou(chutes_errados)) {
    imprime_palavra_secreta(palavra_secreta, chutou);
    imprime_chutes_errados(chutes_errados);
    chuta(chutes_errados, chutou, palavra_secreta);
  }
  cout << endl;

  cout << "Fim de jogo!" << endl;
  if (nao_acertou(palavra_secreta, chutou)) {
    cout << "Você perdeu! A palavra era: " << palavra_secreta << endl;
  } else {
    cout << "Você ganhou! A palavra era: " << palavra_secreta << endl;

    cout << "Você deseja adicionar uma nova palavra ao jogo? (S/N)" << endl;
    char resposta;
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') {
      adiciona_palavra(lista_palavras);
    }
  }
}

/* for antigo
bool letra_existe(char chute, string palavra_secreta) {
  for (int i = 0; i < palavra_secreta.size(); i++) {
    if (chute == palavra_secreta[i]) {
      return true;
    }
  }
  return false;
}
*/

void introducao() {
  cout << "**********************************" << endl;
  cout << "*** Bem vindo ao jogo da forca ***" << endl;
  cout << "**********************************" << endl << endl;
}

bool letra_existe(char chute, string palavra_secreta) {
  for (char letra : palavra_secreta) {
    if (chute == letra) {
      return true;
    }
  }
  return false;
}

void imprime_palavra_secreta(string palavra_secreta, map<char, bool> &chutou) {
  for (char letra : palavra_secreta) {
    if (chutou[letra]) {
      cout << letra << " ";
    } else {
      cout << "_ ";
    }
  }
}

// Função que verifica se há alguma letra que ainda não foi descoberta
bool nao_acertou(string palavra_secreta, map<char, bool> &chutou) {
  for (char letra : palavra_secreta) {
    if (!chutou[letra]) {
      return true;
    }
  }
  return false;
}

bool nao_enforcou(vector<char> &chutes_errados) {
  return chutes_errados.size() < 5;
}

void imprime_chutes_errados(vector<char> &chutes_errados) {
  cout << endl << "Chutes errados: ";
  for (char letra : chutes_errados) {
    cout << letra << " ";
  }
}

void chuta(vector<char> &chutes_errados, map<char, bool> &chutou,
           string palavra_secreta) {
  char chute;
  cout << endl << "Digite uma letra: ";
  cin >> chute;
  chutou[chute] = true;

  cout << endl << "Chute: " << chute << endl;

  if (letra_existe(chute, palavra_secreta)) {
    cout << "Você acertou! Seu chute está na palavra" << endl;
  } else {
    cout << "Você errou! Seu chute não está na palavra" << endl;
    chutes_errados.push_back(chute);
  }
}

vector<string> le_arquivo(vector<string> &lista_palavras) {
  // i - input, f - file, stream - fluxo
  ifstream arquivo;
  arquivo.open("palavras.txt");
  if (arquivo.is_open()) {

    int qtd_palavras;
    cout << "Quantidade de palavras no arquivo: " << endl;
    arquivo >> qtd_palavras;
    cout << qtd_palavras << endl;

    for (int i = 1; i <= qtd_palavras; i++) {
      string palavra_lida;
      arquivo >> palavra_lida;
      lista_palavras.push_back(palavra_lida);
      cout << palavra_lida << endl;
    }
    arquivo.close();
    return lista_palavras;
  } else {
    cout << "Erro ao abrir o arquivo" << endl;
    exit(0);
  }
}

string sorteia_palavra(vector<string> &lista_palavras, string palavra_secreta) {
  srand(time(NULL));
  int indice_sorteado = rand() % lista_palavras.size();
  return lista_palavras[indice_sorteado];
}

void adiciona_palavra(vector<string> &lista_palavras) {
  cout << "Digite a nova palavra: ";
  string nova_palavra;
  transform(nova_palavra.begin(), nova_palavra.end(), nova_palavra.begin(),
            ::toupper);
  cin >> nova_palavra;

  // vector<string> lista_palavras_temp;
  lista_palavras.push_back(nova_palavra);

  salva_arquivo(lista_palavras);
}

void salva_arquivo(vector<string> &lista_palavras) {
  ofstream arquivo;
  arquivo.open("palavras.txt");
  if (arquivo.is_open()) {
    arquivo << lista_palavras.size() << endl;
    for (string palavra : lista_palavras) {
      arquivo << palavra << endl;
    }

    arquivo.close();
  } else {
    cout << "Erro ao abrir o arquivo" << endl;
    exit(0);
  }
}

/*
void Clear() {
#if defined _WIN32
  clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  std::cout << u8"\033[2J\033[1;1H"; // Using ANSI Escape Sequences
#elif defined(__APPLE__)
  system("clear");
#endif
}
*/