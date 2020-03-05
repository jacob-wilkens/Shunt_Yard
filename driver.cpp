#include <string.h>
#include <iostream>
#include "myString.hpp"

using namespace std;

int main(){
    string str = "hello, my name is jacob, ksdfj,kfskldfjsdlkfj,dsklfjsldkfjs,dsfkjsldkfj,dksjf";
    string delims = ",";
    string* m = myString::split(str, delims);
    for(int i = 0; i < 13; i++ ){
        cout << m[i] << "\n";
    }
}

