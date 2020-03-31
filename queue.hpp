#ifndef queue_hpp
#define queue_hpp
#include "Node.hpp"
#include <string>
using namespace std;

class queue 
{
private:
    int count;
    Node* end;
    Node* front;
    
public:
    queue();
    void enqueue(string payload);
    string dequeue();
    int getCount();
    void display();
};
#endif /* queue_hpp */