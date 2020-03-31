#include <string.h>
#include <iostream>
#include<string>
#include "queue.hpp"

using namespace std;

class myString
{
private:
    static bool compare(string character,string delimiters);
    static int counting(string s, string delimiters);
    static queue* transfer(string* s, int length);
public:
    static queue* split(string s, string delimiters);
};
