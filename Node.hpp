#ifndef Node_hpp
#define Node_hpp
#include <string>
using namespace std;
class Node 
{
private:
    string payload;
    Node* nextNode; //Node nextNode - java treats this as a Node* automatically
    
public:
    Node(string payload);
    string getPayload();
    Node* getNextNode();
    void setNextNode(Node* n);
    
};
#endif /* Node_hpp */