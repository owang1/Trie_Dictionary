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

        // Use findChild() to see if the next letter of the key is in the children vector
        Node* temp = findChild(curr, key[i]);    

        if(temp == NULL){

            // Letter yet a child, so create a new Node  
            temp = new Node(key[i], false);
            curr->children.push_back(temp);
            curr = temp;

        }else{
            // If letter is a child, visit that child next
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

    // Iterate through each letter of the key
    for(size_t i = 0; i < key.length(); i++){

        // Call findChild()
        Node* temp = findChild(curr, key[i]);
        if(temp == NULL){                                    // Not found
            return false;
        
        // Stop if reached end of key
        }else if((i == key.length() - 1 ) && !temp->isEnd){  
            return false;

        // Traverse down found child
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

// Function returns location of the child that contains "letter" 

Node *findChild(Node *node, char &letter){

    // Iterate through <Node*> children vector
    for(size_t i = 0; i < node->children.size(); i++){

        Node* temp = node->children.at(i);
        if(temp->key == letter){
            return temp;       
        }
    }
    // Returns NULL if none of the children have that letter
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
