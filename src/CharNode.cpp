#include "CharNode.h"
#include <algorithm>
#include <iostream>
#include <functional>


CharNode::CharNode(char element, string significado) {
    this->father = nullptr;
    this->character = element;
    this->significado = significado;
}


// CharNode* CharNode::addChild(char element, string significado){

//    list<CharNode*>::iterator k;
//    bool contain = false;
// for(k = subtrees.begin();k!=subtrees.end();k++){
//     if((*k)->character==element){
//     contain =  true;
//     break;
//     }
// }

//     if(contain == false ){
//         CharNode *n = new CharNode(element, significado);
//         n->father = this;
//         this->subtrees.push_back(n);
//         return n;
//     }else{
//         CharNode *ptr = (*k);
//         return ptr;
//     }
// }
CharNode* CharNode::addChild(string word, string significado) {
    list<CharNode*>::iterator k;
    bool contain = false;
    if (word.length() == 0) {
        return this->father;
    }
    for (k = this->subtrees.begin();k != this->subtrees.end();k++) {

        if ((*k)->character == word[0]) {

            contain = true;
            break;
        }
    }

    if (contain == true) {

        word = word.substr(1);

        (*k)->addChild(word, significado);

    }
    if (contain == false) {

        char letra = word[0];
        CharNode* n;
        if (word.length() == 1) {
            n = new CharNode(letra, significado);
        }
        else {
            n = new CharNode(letra, "");
        }
        word = word.substr(1);
        this->subtrees.push_back(n);

        n->addChild(word, significado);
    }
    return nullptr;
}
void CharNode::printTreee(string word) {

    list<CharNode*>::iterator k;

    if (this->character != '.') {
        word = word + this->character;
    }
    if (this->significado != "") {
        cout << word << " - significado:" << significado << endl;
    }

    for (k = subtrees.begin();k != subtrees.end(); k++) {
        (*k)->printTreee(word);
    }

}
void CharNode::printTreeeSemSig(string word) {

    list<CharNode*>::iterator k;

    if (this->character != '.') {
        word = word + this->character;
    }
    if (this->significado != "") {
        cout << word << endl;
    }

    for (k = subtrees.begin();k != subtrees.end(); k++) {
        (*k)->printTreeeSemSig(word);
    }

}
void CharNode::printNodes(int nivel) {

    list<CharNode*>::iterator k;
    cout << nivel;
    for (int i = 0; i <= nivel;i++) {
        cout << "-";
    }

    cout << this->character;
    if(this->significado!="")
        cout<<" significado: " << this->significado << endl;
    cout<<endl;

    nivel++;

    for (k = subtrees.begin();k != subtrees.end(); k++) {
        (*k)->printNodes(nivel);
        // cout<<(*k)->character<<endl;
    }
}


CharNode* CharNode::findPrefix(string word) {
    list<CharNode*>::iterator k;
    CharNode* ptr;

    if (word.length() == 0) {
        return this;
    }
    bool found = false;
    for (k = subtrees.begin();k != subtrees.end();k++) {
        if ((*k)->character == word[0]) {
            found = true;
            break;
        }
    }
    if(found == false){
        cout<<"prefixo nao existe no dicionario"<<endl;
        return nullptr;
    }
    word = word.substr(1);
    ptr = (*k)->findPrefix(word);

    return ptr;
}

void CharNode::findSingleWord(string word, string conc) {
    list<CharNode*>::iterator k;
  
    
    if(word.length()==0 && this->significado!=""){
        cout<<conc<<", significado:  "<< this->significado<<endl;
        return;
    }

    bool found = false;
    for (k = subtrees.begin();k != subtrees.end();k++) {
        if ((*k)->character == word[0]) {
            found = true;
            break;
        }
    }
   
    if(found==false){
        cout<<"Palavra não encontrada"<<endl;
        return;
    }
   
    conc += word[0];
   
    word = word.substr(1);
   
    (*k)->findSingleWord(word,conc);

}
void CharNode::ordenaAlfabetica(){
    list<CharNode*>::iterator k;
    // sort(subtrees.begin(),
    // subtrees.end(),
    // [](const CharNode *a, const CharNode *b ){
    //     return a->character < b->character;
    // } );

    //sort(subtrees.begin(),subtrees.end());
    subtrees.sort(CharNode::compareCharacters);

    for (k = subtrees.begin();k != subtrees.end();k++) {
        (*k)->ordenaAlfabetica(); 
    }
}

