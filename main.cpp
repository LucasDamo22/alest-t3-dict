#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Palavra.h"
#include "WordTree.h"

using namespace std;

int main(){
    // lista de palavras
    // std::list<Palavra> lista;
    // string line, pal, sig;

    // // ponteiro para o arquivo
	// fstream fin;

	// // abre o arquivo
	// fin.open("dicionario.csv", ios::in);
    // if(fin.fail()){
    //     cout << "Erro ao abrir o arquivo!" << endl;
    //     return 0;
    // }

    // // enquanto nao for o fim do arquivo... segue lendo...
	// while (!fin.eof()) {
    //     // pega uma linha do arquivo e coloca dentro de "line"
	// 	getline(fin, line);

    //     // transforma essa linha em um fluxo
	// 	stringstream s(line);

    //     // lê cada coluna, ou seja, até chegar no ";"
	// 	getline(s, pal, ';');
    //     getline(s, sig, ';');
    //     Palavra p(pal, sig);
    //     lista.push_back(p);
    // }

    // while(lista.size() > 0){
    //     cout << lista.front().getPalavra() << ": " << lista.front().getSignificado() << endl;
    //     lista.pop_front();
    // }

    WordTree* t = new WordTree();
    t->addWord("abacate", "fruta que vem da planta abacateiro");
    t->addWord("abacateiro", "segunda linha");
    t->addWord("abacateira", "terceira linha");
    t->addWord("bola", "brinquedo infantil");
    t->addWord("boliche","jogo adulto");

    t->printTree();

}