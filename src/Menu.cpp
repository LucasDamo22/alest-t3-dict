#include <iostream>
#include <string>
#include <sstream>
#include "WordTree.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;

std::string menuSelect()
{
    std::stringstream ss;
    ss << "====================================================================" << endl;
    ss << " 1 para imprimir os nodos da arvore" << endl;
    ss << " 2 para imprimir todas as palavras" << endl;
    ss << " 3 para o pesquisar um prefixo" << endl;
    ss << " " << endl;
    ss << " 9 para encerrar a aplicação" << endl;
    ss << "====================================================================" << endl;
    return ss.str();
}
void prefix(WordTree *t){
    string prefixo;
    cout<<"digite o prefixo"<<endl;
    cin.ignore();
    getline(std::cin,prefixo);
    cout<< "as palavras que contem este prefixo são as seguintes: "<<endl;
    t->findAll(prefixo);
    cout<< "entre qual palavra você gostaria de saber o significado" <<endl;
    cin.ignore();
    getline(std::cin,prefixo)

    t->

}

void menu(WordTree *t){
    int numSelect = 0;
    while(numSelect != 9){
    cout << menuSelect() << endl;
    cin >> numSelect;
        if(numSelect == 1){
            t->printNodes();
        }
        else if(numSelect == 2){
            t->printTree();
        }
        else if(numSelect == 3){
            prefix(t);
        }
    }
} 