#include <string.h>
#include <iostream>
#include<string>
#include "queue.hpp"

using namespace std;

class myString
{
private:
    static bool compare(string character,string delimiters);
public:
    static queue* split(string s, string delimiters);
};
