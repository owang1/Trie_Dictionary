// trie.cpp: Trie Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node* findChild(Node *node, char &letter);
void    dump_r(Node *node, std::ostream &os);


// Methods ---------------------------------------------------------------------
// Insert function to build the Trie
void            TrieMap::insert(std::string key) {
    // Start at the root
    Node *curr = root;
    // Iterate through each letter of the key
    for(unsigned int i = 0; i < key.length(); i++){
        Node* temp = findChild(curr, key[i]);    
        if(temp == NULL){
            // Need to create a new node
            temp = new Node(key[i], false);
            curr->children.push_back(temp);
            curr = temp;
        }else{

            curr = temp;
        }
        // Mark the end of a word
        if(i == key.length() - 1){
            curr->isEnd = true;
        }
    }   
}

// Boolean function that returns true if the key is found in the trie
bool     TrieMap::search(std::string key) {
    bool result = true;
    Node* curr = root;
    for(size_t i = 0; i < key.length(); i++){
        Node* temp = findChild(curr, key[i]);
        if(temp == NULL){
            return false;
        }else if((i == key.length() -1 ) && !temp->isEnd){
            return false;
        }else{
            curr = temp;
        }
    }
    return result;
}

void            TrieMap::dump(std::ostream &os) {
    dump_r(root, os);
}

// Internal Functions ----------------------------------------------------------

Node *findChild(Node *node, char &letter){
    // Iterate through <Node*> children vector
    for(size_t i = 0; i < node->children.size(); i++){
        Node* temp = node->children.at(i);
        if(temp->key == letter){
            // Return temp pointer to existing child node
            return temp;       
        }
    }
    // Returns NULL if a child with that letter doesn't exist yet
    return NULL;
}

// Debugging function that displays contents of the Trie 
void dump_r(Node *node, std::ostream &os) {
    if (node == nullptr) {
        return;
    }
    for(size_t i = 0; i < node->children.size(); i++){
        os << node -> children[i] -> key;
        dump_r(node -> children[i], os);
        if(node->children[i]->isEnd){
            os << std::endl;
        }

    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
