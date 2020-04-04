#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"
#include <string>
using namespace std;

class LinkedList 
{
private:
    Node* head;
    int count;
    Node* runToEndOfList();
    Node* runToIndex(int index);
    
public:
    LinkedList();
    void addFront(string payload);
    string getFront();
    string removeFront();
    void addEnd(string payload);
    string getEnd();    
    string removeEnd();
    void addAtIndex(int index, string payload);
    string getIndex(int index);
    string removeIndex(int index);
    void display();
    void displayPointers();
    void sort(); //re-arranges the linked list such that it is in ascending numerical order
    string* toStringArray();
    int getCount();
};
#endif /* LinkedList_hpp */