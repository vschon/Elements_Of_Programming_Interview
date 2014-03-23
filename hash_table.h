#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <list>
#include <algorithm>
#include <utility>
#include <stdexcept>

#define BUCKET_MAX 6991 
typedef std::pair<std::string, int> HashNode;

class matchPairString {
public:
    matchPairString(std::string key_) : firstKey(key_) {}
    bool operator()(const std::pair<std::string, int>& elem) const {
        return firstKey == elem.first;
    }
private:
    std::string firstKey;
};

class HashTable {
private:
    std::list<HashNode>* hTable;
    const size_t bucketCount; 
public:
    HashTable();
    ~HashTable();
    unsigned int HashFunction(std::string key_);
    int bucketSize();
    void insert(std::string key_, int value_);
    void remove(std::string key_);
    int at(std::string key_);
    void display();
    int size();
protected:
    bool keyMatch(HashNode node);
};

HashTable::HashTable() : bucketCount(BUCKET_MAX) {
    hTable = new list<HashNode>[bucketCount];
}

HashTable::~HashTable() {
    for(size_t i = 0; i < bucketCount; i++){
        hTable[i].clear();
    }
    delete[] hTable;
}

int HashTable::bucketSize() {
    return bucketCount;
} 

unsigned int HashTable::HashFunction(std::string key_) {
    unsigned long hash = 5381;
    for(char c : key_) {
        hash = ((hash << 5) + hash) + c;
    }
    hash = hash > 0 ? hash : -hash;
    return hash%bucketCount; 
}

    
void HashTable::insert(std::string key_, int value_) {
    unsigned int keyNum = HashFunction(key_);
    if(hTable[keyNum].empty()) {
        hTable[keyNum].emplace_back(std::make_pair(key_, value_));
    }
    else {
        std::list<HashNode>::iterator it = find_if(hTable[keyNum].begin(), hTable[keyNum].end(), matchPairString(key_));
        if(it != hTable[keyNum].end()) {
            it->second = value_;
        }
        else
            hTable[keyNum].emplace_back(make_pair(key_, value_));
    }
}

int HashTable::at(std::string key_) {
    unsigned int keyNum = HashFunction(key_);
    if(hTable[keyNum].empty()) {
        throw invalid_argument("Key_error");
    }
    else {
        std::list<HashNode>::iterator it = find_if(hTable[keyNum].begin(), hTable[keyNum].end(), matchPairString(key_));
        if(it != hTable[keyNum].end()) {
            return it->second;
        }
        else{
            throw invalid_argument("Key_error");
        }
    }   
}

void HashTable::remove(std::string key_) {
    unsigned int keyNum = HashFunction(key_);
    if(hTable[keyNum].empty()) {
        throw invalid_argument("Key_error");
    }
    else {
        std::list<HashNode>::iterator it = find_if(hTable[keyNum].begin(), hTable[keyNum].end(), matchPairString(key_));
        if(it != hTable[keyNum].end()) {
            hTable[keyNum].remove_if(matchPairString(key_));
        }
        else{
            throw invalid_argument("Key_error");
        }
    } 
}

void HashTable::display() {
    for(size_t i = 0; i < BUCKET_MAX; i++) {
        if(!hTable[i].empty()) {
            for(std::list<HashNode>::iterator it = hTable[i].begin(); it != hTable[i].end(); it++) {
                cout << it->first << " : " << it->second << endl;
            }
        }
    } 
    
}

int HashTable::size() {
    int count = 0;
    for(size_t i = 0; i < BUCKET_MAX; i++) {
        if(!hTable[i].empty()) {
            for(std::list<HashNode>::iterator it = hTable[i].begin(); it != hTable[i].end(); it++) {
                count++;
            }
        }
    } 
    return count;
}


    






    







