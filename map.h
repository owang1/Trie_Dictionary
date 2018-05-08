// map.h

#pragma once

// Includes --------------------------------------------------------------------

#include <iostream>
#include <functional>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

// Type definitions ------------------------------------------------------------

// Structures ------------------------------------------------------------------

struct Node {
    char key;
    bool isEnd;
    std::vector<Node*> children;

    Node(char key, bool isEnd=false){
        this->key = key;
        this->isEnd = isEnd;
    }
    ~Node() {      

        for(size_t i=0; i < children.size(); i++){
            delete children[i];
        }
    }
};


// Classes ---------------------------------------------------------------------

class TrieMap {
public:
            void                insert(std::string key);
            bool                search(std::string key);
            void                dump(std::ostream &os);
                                ~TrieMap() { delete root; }
                                TrieMap(Node *root) { this->root = root; }
private:
            Node *root = nullptr; 

};

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
