#include <string.h>
#include <iostream>
#include "myString.hpp"

using namespace std;

int main(){
    string str = "3+4*2/(1-5)";
    string delims = "+-*/()";
    queue* myQ = myString::split(str, delims);
    myQ->display();
    cout << "q size is " << myQ->getCount() << "\n";
}

