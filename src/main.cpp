#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Palavra.h"
#include "WordTree.h"

using namespace std;
void addPalavras(WordTree* t){
    //lista de palavras
    std::list<Palavra> lista;
    string line, pal, sig;

    // ponteiro para o arquivo
	fstream fin;

	// abre o arquivo
	fin.open("./data/dicionario.csv", ios::in);
    if(fin.fail()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    // enquanto nao for o fim do arquivo... segue lendo...
	while (!fin.eof()) {
        // pega uma linha do arquivo e coloca dentro de "line"
		getline(fin, line);

        // transforma essa linha em um fluxo
		stringstream s(line);

        // lê cada coluna, ou seja, até chegar no ";"
		getline(s, pal, ';');
        getline(s, sig, ';');
        Palavra p(pal, sig);
        lista.push_back(p);
    }

    while(lista.size() > 0){
        //cout << lista.front().getPalavra() << ": " << lista.front().getSignificado() << endl;
        t->addWord(lista.front().getPalavra(),lista.front().getSignificado());
        lista.pop_front();
    }

}
int main(){
    
    WordTree* t = new WordTree();
    addPalavras(t);
    t->ordena();
    // t->addWord("abacate", "fruta que vem da planta abacateiro");
    // t->addWord("abacateiro", "planta q da abacate");
    // t->addWord("abacateira", "mulher do abacateiro");
    
    // t->addWord("bola", "brinquedo infantil");
    // t->addWord("bolado","emoção");
    // t->addWord("boliche","jogo adulto");
    // t->addWord("bela","princesa disney");
    // t->addWord("escola","lugar de estudo");
    // t->addWord("dado","cubo com numeros");
    // t->addWord("casa","lugar de moradia");
    // t->addWord("esfolar","remover a pele");
    // t->addWord("casar","casar");
    // t->addWord("dandelio","planta, eu acho");


    //string teste = t->findAll("bola");
    
    //t->printTree();
    //t->printNodes();
    menu(t);
    

}