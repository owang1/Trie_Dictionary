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

/* This program tests the execution time of insert and search for specified text files
 * Test files are included to demonstrate how tries work better for groups of lists that
 * share common prefixes
 * The pre_# text files contain random 6 letter words that all begin with the letter "a," while
 * the rand_# and insert_# text files are completely random 6 letter words
 * These words were generated using listofrandomwords.com
 *
 * Example command line arguments for suggested usage:
 *  ./map_bench pre_20.txt insert_20.txt
 *  ./map_bench rand_20.txt insert_20.txt
 */


// Type Definitions ------------------------------------------------------------

typedef std::chrono::high_resolution_clock  Clock;

int main(int argc, char *argv[]) {
    if(argc != 3){
        std::cout << "Usage: " << std::endl;
        std::cout << "To test prefix, execute: ./map_bench [pre_#.txt] [insert_#.txt]" << std::endl;
        std::cout << "To test random, execute: ./map_bench [rand_#.txt] [insert_#.txt]" << std::endl;
        return 1;
    }
    
    int count = 0;
    double total_insert = 0;
    double total_search = 0;
  
    // Benchmark 5 tests
    while(count < 5){

    Node *root = new Node('\0', false);
    TrieMap *trie = new TrieMap(root);
    std::string word;
    
    // Insert
    std::string dictionaryName = argv[1];
    std::ifstream dictionaryFile;
    
    dictionaryFile.open(dictionaryName);
    
    auto insert_start = Clock::now();
    while(dictionaryFile >> word){
        trie->insert(word);
    }
    auto insert_stop = Clock::now();
    auto insert_diff = insert_stop - insert_start; 
    total_insert = total_insert + std::chrono::duration<double>(insert_diff).count();
    
    // Search
    std::string lookupName = argv[2];
    std::ifstream lookupFile;
    lookupFile.open(lookupName);

    auto search_start = Clock::now();
    while(lookupFile >> word){
        trie->search(word);
    }
    auto search_stop = Clock::now();
    auto search_diff = search_stop - search_start;
    total_search = total_search + std::chrono::duration<double>(search_diff).count();

    dictionaryFile.close();
    lookupFile.close();
    delete trie;
    count++;
    }
    double average_insert = total_insert/count;
    double average_search = total_search/count;
   
    std::cout << "Average Insert: " << std::setprecision(5) << average_insert << " s" << std::endl;
    std::cout << "Average Search: " << std::setprecision(5) << average_search << " s" << std::endl;
    return 0;
}

//vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
