#include <string.h>
#include <iostream>
#include<string>
#include "LinkedList.hpp"

using namespace std;

class myString
{
private:
    string s;
    bool compare(string character,string delimiters);
public:
    myString(string str);
    LinkedList split(string delimiters);
};
