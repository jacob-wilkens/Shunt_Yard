#include <string.h>
#include <iostream>
#include "myString.hpp"

using namespace std;

int main(){
    string str = "skdlfj,,kkk,lll,,";
    string delims = ",";
    string* m = myString::split(str, delims);
    for(int i = 0; i < 8; i++ ){
        cout << m[i] << "\n";
    }

    //LinkedList* ll = new LinkedList();
    
    //for(int i = 0; i < 5; i++){
        //ll->addEnd(m[i]);
    //}
    
    //ll->display();
    //delete ll;
}

