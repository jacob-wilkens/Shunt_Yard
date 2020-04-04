#ifndef myString_hpp
#define myString_hpp
#include "Queue.hpp"
#include <iostream>

using namespace std;

class myString
{
    public:
        static Queue* split(string s, string delims);
    
    private:
        static bool isInString(string searchString, char charToFind);
};
#endif