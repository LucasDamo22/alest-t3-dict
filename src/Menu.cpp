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
std::string capitalizeFirstLetter(const std::string& str) {
    std::string result = str;
    
    if (!result.empty()) {
        result[0] = std::toupper(result[0]); // Converte a primeira letra para maiúscula
        
        for (size_t i = 1; i < result.length(); ++i) {
            result[i] = std::tolower(result[i]); // Converte o restante para minúsculo
        }
    }
    
    return result;
}
void prefix(WordTree *t){
    string prefixo;
    bool temPrefix;
    cout<<"digite o prefixo"<<endl;
    cin.ignore();
    getline(std::cin,prefixo);
    prefixo = capitalizeFirstLetter(prefixo);
    cout<<endl;
    temPrefix  = t->findAll(prefixo);
    if(temPrefix== true ){
        cout<< "entre as palavras acima, qual palavra você gostaria de saber o significado:" <<endl;
        //cin.ignore();
        getline(std::cin,prefixo);
        prefixo = capitalizeFirstLetter(prefixo);
        cout<<endl;
        t->findSingleWord(prefixo);
    }

    

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