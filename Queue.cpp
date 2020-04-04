#include "Queue.hpp"
#include <iostream>
using namespace std;

Queue::Queue()
{
    this->head = 0;
    this->tail = 0;
    this->count = 0;
}

void Queue::display()
{
    Node* currNode = this->head;
    int i = 0;
    while(i != count)
    {
        cout << currNode->getPayload() << " ";
        currNode = currNode->getNextNode();
        i++;
    }
    cout << "\n";
}

void Queue::enqueue(string payload)
{
    Node* n = new Node(payload);
    if(this->tail)
    {
        this->tail->setNextNode(n);
        this->tail = n;
    }
    else
    {
        this->head = n;
        this->tail = n;
    }
    this->count++;
}

string Queue::dequeue()
{
    if(this->head)
    {
        Node* temp = this->head;
        this->head = this->head->getNextNode();
        string val2Return = temp->getPayload();
        delete temp;
        this->count--;
        return val2Return;
    }
    else
    {
        return ""; //this should never happen!!!!  Throw an exception
    }
    
}

int Queue::getCount()
{
    return this->count;
}