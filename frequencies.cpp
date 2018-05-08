// freqencies.cpp

#include "map.h"

#include <iostream>
#include <string>

#include <strings.h>
#include <unistd.h>
#include <fstream>
#include <iomanip>
#include <algorithm>

void makeLower(std::string &str);
void checkAlpha(std::string &str);
// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {

    // Usage statement
    if(argc < 2){
        std::cout << "Usage: ./frequences [filename.txt]" << std::endl;
        return 1;
    }

    int count = 0;
    int numFound = 0;
    std::string movieName = argv[1];
    
    // Declare a TrieMap and set the necessary variables
    Node *root = new Node('\0', false);
    TrieMap *trie = new TrieMap(root);
    std::string word;
    bool found;
    
    // Store dictionary words om the Trie
    std::string dictionaryName = "/usr/share/dict/words";
    std::ifstream dictionaryFile;

    dictionaryFile.open(dictionaryName);    
    while (dictionaryFile >> word) {     

        // Convert every word to all lowercase   
        makeLower(word);
        trie->insert(word);
    }
    

    // Get input from specified text file 
    std::ifstream movieFile;
    movieFile.open(movieName);
    
    // Check existence of each word in the dictionary trie
    while(movieFile >> word){

        // Handle case and punctuation
        makeLower(word);
        
        if(word.size() > 1){
            checkAlpha(word);
        }
        found = trie->search(word);

        if(found){
            numFound++;             // Increment matches
        }   
        count++;                    // Increment total "words"
    }
    
    float percent = 100*((float)numFound / count);
 
    // Display results 
    std::cout << std::endl;
    std::cout << "TRIE DICTIONARY RESULTS" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "NUMBER OF VALID WORDS: " << numFound << std::endl;
    std::cout << "TOTAL: " << count << std::endl;
    std::cout << std::setprecision(4) << "PERCENT VALID: " << percent << "%" << std::endl;
    std::cout << std::endl;
    // FOR TESTING: Output words and frequencies
    // trie->dump(std::cout);

    delete trie;
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
