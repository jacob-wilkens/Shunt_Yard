#include <string.h>
#include <iostream>
#include "myString.hpp"

using namespace std;

int main(){
    string str = "-5403+348/8*46-";
    string delims = "+-*/";
    myString s = myString(str);
    LinkedList ll = s.split(delims);
    ll.display();

}

