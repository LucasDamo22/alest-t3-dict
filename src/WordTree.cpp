#include "WordTree.h"
#include <iostream>

WordTree::WordTree() {
    this->root = new CharNode('.', "");
}

void WordTree::addWord(string word, string significado) {
    
    

    root->addChild(word, significado);
    
    // for(size_t i = 0; i < word.length();i++){
    //     char caractere = word[i];
    //     if (i == ((word.length())-1)){
    //         root->addChild(caractere, significado);
    //     }else{
    //         root->addChild(caractere,"");
    //     }
    // }
}
void WordTree::printNodes(){
    root->printNodes(0);
}
void WordTree::printTree() {
    
    root->printTreee("");
}

bool WordTree::findAll(string word){
    
    CharNode* ptr = root->findPrefix(word);
    
    word.pop_back();
    if(ptr!=nullptr){
        ptr->printTreeeSemSig(word);
        return true;
    }
    //string lele(1, ptr->character);
    return false;
}

void WordTree::findSingleWord(string word){
    root->findSingleWord(word,"");
}
void WordTree::ordena(){
    root->ordenaAlfabetica();
}
