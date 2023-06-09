#include "CharNode.h"
#include <algorithm>
#include <iostream>



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




}
void CharNode::printTreee(string word) {

    list<CharNode*>::iterator k;
    cout<<"tree 1"<<endl;
    cout<<word<<endl;
    cout<<this->character<<endl;
    cout<<"----"<<endl;
    if (this->character != '.'){
        word = word + this->character;
    }
    cout<<"tree 2"<<endl;
    // cout<<"charnodeprint"<<endl;
    // cout << word << endl;
    // cout<<significado<<endl;
    if (this->significado != "") {
        cout << word << " - significado:" << significado << endl;
    }
    cout<<"tree 4"<<endl;
    for (k = subtrees.begin();k != subtrees.end(); k++) {
        (*k)->printTreee(word);
    }

}
void CharNode::printNodes(int nivel) {

    list<CharNode*>::iterator k;
    cout << nivel;
    for (int i = 0; i <= nivel;i++) {
        cout << "-";
    }
    cout << this->character << " sig " << this->significado << endl;

    nivel++;
    for (k = subtrees.begin();k != subtrees.end(); k++) {
        (*k)->printNodes(nivel);
        // cout<<(*k)->character<<endl;
    }

}


CharNode* CharNode::findPrefix(string word){
    list<CharNode*>::iterator k;
    cout<<"1"<<endl;
    if(word.length()==0){
        cout<<"Word = 0"<<endl;
        cout<<this->character<<"   caractere"<<endl;
        return this;
    }
    for(k=subtrees.begin();k!=subtrees.end();k++){
        if((*k)->character==word[0]){
            break;
        }
    }
    cout<<"2"<<endl;
    word = word.substr(1);
    cout<<"3"<<endl;
    
    
        cout<<"word maior que 0   "<<word<<endl;
        cout<<this->character<<"   caractere"<<endl;
    (*k)->findPrefix(word);
    }
    
