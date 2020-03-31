#include "queue.hpp"
#include <iostream>
#include <string>
using namespace std;

queue::queue(){
    this->count = 0;
    this->end = 0;
    this->front = 0;
}

string queue::dequeue(){//remove from front
    Node* temp = this->front;
    this->front = temp->getNextNode();
    string payload = temp->getPayload();
    temp->setNextNode(0);
    delete temp;
    count--;
    return payload;
}

void queue::enqueue(string payload){//add to end
    Node* n = new Node(payload);
    
    if(count == 0){
        this->front = n;
        this->end = n;
        count++;
    } else {
        Node* temp = this->end;
        temp->setNextNode(n);
        this->end = n;
        count++;
    }

}

int queue::getCount(){
    return this->count;
}

void queue::display()
{
    Node* currNode = this->front;
    for(int i = 0; i < this->count; i++)
    {
        cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
}