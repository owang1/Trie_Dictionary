// freqencies.cpp

#include "map.h"

#include <iostream>
#include <string>

#include <strings.h>
#include <unistd.h>
#include <fstream>
#include <iomanip>


void processWord(std::string &str);
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
    //std::string filterWord;
    // Get & store dictionary input from file stream -> /usr/share/dict/words 
    std::string dictionaryName = "/usr/share/dict/words";
    std::ifstream dictionaryFile;

    dictionaryFile.open(dictionaryName);    
    while (dictionaryFile >> word) {        
        trie->insert(word);
    }
    /*
    while(dictionaryFile >> word){
        char c;
        int i = 0;
        while(word[i]){
            c = word[i];
            putchar(tolower(c));
            i++;
        }
        trie->insert(word);
    }*/

    std::ifstream movieFile;
    movieFile.open(movieName);
    /*while(movieFile >> word){

        bool found = trie->search(word);
        if(found){
            numFound++;          
            std::cout << word << std::endl;    
        }
        count++;
    }*/
    while(movieFile >> word){
 //       filterWord = processWord(word);
        if(word.size() > 1){
        processWord(word);
        }
        found = trie->search(word);
        if(found){
            numFound++;
        }   
        count++;    
    }
    
    float percent = 100*((float)numFound / count);
 
    // Display results 
    std::cout << "NUMBER OF VALID WORDS: " << numFound << std::endl;
    std::cout << "TOTAL: " << count << std::endl;
    std::cout << std::setprecision(3) << "PERCENT VALID: " << percent << "%" << std::endl;

    // FOR TESTING: Output words and frequencies
    // trie->dump(std::cout);

    delete trie;
    return 0;
}

// Filtering function that deletes the first and/or last characters
// if they are not in the alphabet (i.e. punctuation)
void processWord(std::string &str){
    
    if(!std::isalpha(str.at(0))){
        str.erase(0,1);
    }
    if(!std::isalpha(str.back())){
        str.pop_back();
    }
    
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
