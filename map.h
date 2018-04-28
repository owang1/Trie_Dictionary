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

typedef enum {
    DUMP_KEY,
    DUMP_VALUE,
    DUMP_KEY_VALUE,
    DUMP_VALUE_KEY,
} DumpFlag;

// Structures ------------------------------------------------------------------

struct Node {
    //std::string key;
    char key;
    bool isEnd;
    std::vector<Node*> children;

    ~Node() {        
        for(size_t i=0; i < children.size(); i++){
            delete children[i];
        }
    }
};


// Classes ---------------------------------------------------------------------

class Map {
public:
    virtual void                insert(std::string key) {}
    virtual bool                search(std::string key) { return NULL; }
    virtual void                dump(std::ostream &os, DumpFlag flag) {}
    virtual                     ~Map() {}
};
class TrieMap : public Map {
public:
            void                insert(std::string key);
            bool                search(std::string key);
            void                dump(std::ostream &os, DumpFlag flag);
                                ~TrieMap() { delete root; }
private:
            Node *root = nullptr; 

};

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
