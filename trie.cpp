// trie.cpp: Trie Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node *insert_help(Node *node, char &letter);
Node* findChild(Node *node, char &letter);      // Look for/create child node if needed
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);


// Methods ---------------------------------------------------------------------

void            TrieMap::insert(std::string key) {
    Node *curr = root;
    for(unsigned int i = 0; i < key.length(); i++){
        Node* temp = findChild(curr, key[i]);    // Go to the child of the node
        if(temp == NULL){
            // Need to create a new node
            curr->children.push_back(temp);
            curr = insert_help(temp, key[i]);
        }else{
            curr = temp;
        }
        if(i == key.length() - 1){
            curr->isEnd = true;
        }
    }   
}

bool     TrieMap::search(std::string key) {
    bool result = true;
    Node* curr = root;
    for(size_t i = 0; i < key.length(); i++){
        Node* temp = findChild(curr, key[i]);
        if(temp == NULL){
            return false;
        }else if((i == key.length() -1 ) && !curr->isEnd){
            // End of string reached but isEnd is true
            return false;
        }else{
            curr = temp;
        }
    }
    return result;
}

void            TrieMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

// Internal Functions ----------------------------------------------------------

Node *findChild(Node *node, char &letter){
    // Iterate through <Node*> children vector
    for(size_t i = 0; i < node->children.size(); i++){
        Node* temp = node->children.at(i);
        if(temp->key == letter){
            return temp;       
        }
    }
    // Returns NULL if a child with that letter doesn't exist yet
    return NULL;
}

Node *insert_help(Node *node, char &letter) {
    return new Node{letter, false, {}};
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
    if (node == nullptr) {
        return;
    }
/*
    dump_r(node->right, os, flag);
    switch (flag) {
        case DUMP_KEY:          os << node->entry.first  << std::endl; break;
        case DUMP_VALUE:        os << node->entry.second << std::endl; break;
        case DUMP_KEY_VALUE:    os << node->entry.first  << "\t" << node->entry.second << std::endl; break;
        case DUMP_VALUE_KEY:    os << node->entry.second << "\t" << node->entry.first  << std::endl; break;
    }
    dump_r(node->left, os, flag);*/
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
