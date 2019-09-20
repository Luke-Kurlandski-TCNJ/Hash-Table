#include <iostream>
#include "SLL.h"
using  namespace  std;

template <class V>
class HashTable {
    int tableSize; // table size
    
    SLL<V>* table;
    
    public:
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which use size as the table size
    HashTable(int size){
      // implement this method
        table = new SLL<V>[size];
        tableSize = size;
    }
    
    // search item in the table
    // if found, return true; otherwise, return false
    bool find(V item){
      // implement this method
        if(table[stoi(item) % tableSize].search(item) != nullptr)
            return true;
        else
            return false;
    }
    
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2){
      //implement this method
        //cout << tableSize << endl;
        
        return table[stoi(item1)%tableSize].insert(item1, item2);
    }
    
    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false 
    bool erase(V item){
      // implement this method
        return table[stoi(item)%tableSize].remove(item);

    }

    // return the total number of nodes in the hash table    
    int getSize(){
      // implement this method
        int total = 0;
        for(int i=0; i<tableSize; i++) {
            total += table[i].getSize();
        }
        return total;
    }

};
