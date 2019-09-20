#include <iostream>
#include "node.h"
using  namespace  std;

template <class U>
class SLL {
    
    Node<U> * headPtr;
    int size;
    
    public:
    // default constructor
    SLL(){
      //implement this method
        headPtr = nullptr;
        size = 0;
    }

    // destructor    
    ~SLL(){
      // implement this method
        Node<U> *temp = headPtr;
        while(temp != nullptr) {
            Node<U> *temp2 = temp;
            temp = temp->next;
            //delete temp2->name;
            //delete temp2->SSN;
            delete temp2;
        }
    }
    
    Node<U>* getHeadPtr(){
        return headPtr;
    }
    
    // insert (item1, item2) to the list
    bool insert(U item1, U item2){
      //implement this method
        //create a new node
        Node<U> *n = new Node<U>;
        n->SSN = item1;
        n->name = item2;
        n->next = nullptr;
        //handles an empty linked list
        if(size == 0) {
            headPtr = n;
            size++;
            return true;
        }
        //handles if n goes before head
        if(n->SSN < headPtr->SSN) {
            n->next = headPtr;
            headPtr = n;
            size++;
            return true;
        }
        //handles a duplicate of headPtr
        if(n->SSN == headPtr->SSN) {
            delete n;
            return false;
        }
        //handles a single element list, where n goes after head
        if(size==1) {
            headPtr->next = n;
            size++;
            return true;
        }
        //handles a real list of two or more elements
        Node<U> *temp = headPtr;
        while(temp != nullptr) {
            if(temp->next == nullptr) {
                if(n->SSN > temp->SSN) {
                    temp->next = n;
                    size++;
                    return true;
                }
            }
            else {
                //handles a duplicate
                if(n->SSN == temp->next->SSN) {
                    delete n;
                    return false;
                }
                //inserts before an element
                if(n->SSN < temp->next->SSN) {
                    n->next = temp->next;
                    temp->next = n;
                    size++;
                    return true;
                }
            }
            temp = temp->next;
        }
        return false;
    }
    
    // if find the item1 value, return the pointer to the node
    // otherwise, return nullptr
    Node<U>* search(U item1){
      //implement this method
        Node<U> *temp = headPtr;
        while(temp != nullptr) {
            //match
            if(temp->SSN == item1) {
                return temp;
            }
            //sorted list allows for smart searching
            if(item1 < temp->SSN) {
                return nullptr;
            }
            //next node
            else {
                temp = temp->next;
            }
        }
        return nullptr;
    }
    
    // remove the node with key value: item1
    bool remove(U item1){
      //implement this method
        
        if(headPtr == nullptr)
            return false;
        //handles head removal
        Node<U> *temp = headPtr;
        if(temp->SSN == item1) {
            if(headPtr->next == nullptr) {
                delete headPtr;
                headPtr = nullptr;
                size--;
                return true;
            }
            headPtr = headPtr->next;
            size--;
            delete temp;
            return true;
        }
        //handles removal in middle of list
        while(temp->next != nullptr) {
            //sorted list allows for smart searching
            if(item1 < temp->SSN) {
                return false;
            }
            //match
            if(temp->next->SSN == item1) {
                Node<U> *temp2 = temp->next->next;
                delete (temp->next);
                temp->next = temp2;
                size--;
                return true;
            }
            //next node
            else {
                temp = temp->next;
            }
        }
        //handles removal of the last node
        if(temp->SSN == item1) {
            delete temp;
            size--;
            return true;
        }
        else {
            return false;
        }
    }
    
    int getSize(){
        return size;
    }
    
    // display the SSN values of each node in the linked list
    void display(){
        Node<U>* temp;
        temp = headPtr;
        while (temp!= nullptr) {
            cout << temp->SSN << endl;
            temp = temp->next;
        }
    }
};


