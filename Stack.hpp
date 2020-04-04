#ifndef Stack_hpp
#define Stack_hpp

#include "Node.hpp"
#include <string.h>
#include <iostream>

class Stack
{
    private:
        Node* top;
        int count;
    
    public:
        Stack();
        void push(string s);
        string pop();
        string peek();
        int getCount();
        void display();
};

#endif