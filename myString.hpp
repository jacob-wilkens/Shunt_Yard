#include <string.h>
#include <iostream>
#include<string>
#include "LinkedList.hpp"

using namespace std;

class myString
{
private:
    static bool compare(string character,string delimiters);
    static int counting(string s, string delimiters);
public:
    static string* split(string s, string delimiters);
};
