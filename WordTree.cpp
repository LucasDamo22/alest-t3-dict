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
    root->printNodes(1);
}
void WordTree::printTree() {
    
    root->printTreee("");
}


