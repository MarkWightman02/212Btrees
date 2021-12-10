#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <utility>

#include "alphaBTree.cpp"

void fixEntry(std::string &entry) {
    
    
    for (int i = 0; i < entry.size(); i++) {
        if ( (i==0 || i==entry.size() - 1) && ispunct(entry.at(i)) ) {
            entry.erase( entry.begin()+i);
            i--;
        }
        else if (  ispunct( entry.at(i))  && entry.at(i) != '-' && int( entry.at(i) ) != 39) {
            entry.erase( entry.begin()+i);
            i--;
        }
        else if (isalpha(entry.at(i)) ) {
            entry.at(i) = tolower( entry.at(i) );
        }
    
        
    }
    
}

void checkOccurences(std::string entry, std::vector < std::pair <std::string, int> > &occurences) {
    
    for (int i = 0; i < occurences.size(); i++) {
        
        if (entry == occurences[i].first ) {
            occurences[i].second ++;
            return;
        }
        
    }
    
    std::pair <std::string, int> newEntry(entry, 1);
    
    occurences.push_back(newEntry);
    
}



int main() {
    
    int numWords = 0, wordCount = 0;
    
    std::ifstream book;

    std::string line, entry;
    
    std::vector <std::pair <std::string, int> > occurences;
    std::vector <int> wordCounts;
    
    book.open("mobydick.txt");
    
    for (int z = 0; std::getline(book, line); z++) {
        
        
        std::stringstream ss;
        ss << line;
        
        for(int i = 0; std::getline(ss, entry, ' '); i++) {
            fixEntry(entry);
            //std::cout << entry << ' ';
            if (entry.size() > 0) {
                
                checkOccurences(entry, occurences);
                numWords++;
            }
            
        }
    
    }
    
    BTree myTree(3);
    
    for (int i = 0; i < occurences.size(); i++) {
        //std::cout << '(' << occurences[i].first << ", " << occurences[i].second << ") ";
        //wordCount += occurences[i].second;
        myTree.insert(occurences[i]);
    }
    
    
    book.close();
    
    //myTree.traverse();
    
    // std::ofstream myDot;
    // myDot.open("AlphaDotFile.dot");
    // myDot << "digraph G {\n";
    
    // myTree.makeDot(myDot);
    // myDot << "}\n";
    // myDot.close();
    
    
    myTree.search("the");
    
    return 0;
}

