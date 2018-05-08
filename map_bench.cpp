// map_bench.cpp

#include "map.h"

#include <cassert>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

#include <strings.h>
#include <unistd.h>
#include <algorithm>
#include <iomanip>
#include <fstream>
void makeLower(std::string &str);
void checkAlpha(std::string &str); 


// Type Definitions ------------------------------------------------------------

typedef std::chrono::high_resolution_clock  Clock;

int main(int argc, char *argv[]) {
    if(argc == 3){
    std::string lookupName = argv[2];
    Node *root = new Node('\0', false);
    TrieMap *trie = new TrieMap(root);
    std::string word;
    
    // Insert
    std::string dictionaryName = argv[1];
    std::ifstream dictionaryFile;
    
    dictionaryFile.open(dictionaryName);
    auto insert_start = Clock::now();
    
    while(dictionaryFile >> word){
        makeLower(word);
        trie->insert(word);
    }
    auto insert_stop = Clock::now();
    auto insert_diff = insert_stop - insert_start; 

    /*for (int i = 0; i < nitems; i++) {
        std::string k = int_to_key(i, padlength);
        std::string v = k;
        map->insert(k, v);
    }
    auto insert_stop  = Clock::now();
    auto insert_diff  = insert_stop - insert_start;
*/
    std::cout << "Insert: " << std::setprecision(5) << std::chrono::duration<double>(insert_diff).count() << " s" << std::endl;

    // Search

    std::ifstream lookupFile;
    lookupFile.open(lookupName);

    auto search_start = Clock::now();
    while(lookupFile >> word){
        makeLower(word);
        
        if(word.size() > 1){
            checkAlpha(word);;
        }
        trie->search(word);
    }
    auto search_stop = Clock::now();
    auto search_diff = search_stop - search_start;
/*
    auto search_start = Clock::now();
    for (int i = 0; i < nitems; i++) {
        std::string k = int_to_key(i, padlength);
        map->search(k);
    }
    auto search_stop  = Clock::now();
    auto search_diff  = search_stop - search_start;
*/
    std::cout << "Search: " << std::setprecision(5) << std::chrono::duration<double>(search_diff).count() << " s" << std::endl;

    delete trie;
    }
    return 0;
}
void makeLower(std::string &str){
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

}

// Deletes first/last letters if they are not alphabetical
void checkAlpha(std::string &str){

    if(!std::isalpha(str.at(0))){
         str.erase(0,1);
    }
    if(!std::isalpha(str.back())){
         str.pop_back();       
    }
 }
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
