#include <string.h>
#include <iostream>
#include <string>
#include "myString.hpp"

using namespace std;

myString::myString(string s){
    this->s = s;
}

bool myString::compare(string character, string delimiters){
    
    for(int i = 0; i < delimiters.length(); i++ ){
        if(character.at(0) == delimiters.at(i)){
            return true;
        }
    }

    return false;
}

LinkedList myString::split(string delimiters){
    string myChar;
    string TempString = "";
    LinkedList ll = LinkedList();

        for(int i = 0; i < this->s.length(); i++){
            myChar = this->s.at(i);
            TempString += myChar;
            if(compare(myChar, delimiters) == true){

                if(TempString.length() == 1){
                    ll.addEnd(TempString);
                    TempString = "";
                } else {
                    TempString.pop_back();
                    ll.addEnd(TempString);
                    TempString = myChar;
                    ll.addEnd(TempString);
                    TempString = "";
                } 
            } else {
                if(i == this->s.length() - 1){
                    ll.addEnd(TempString);
                    break;
                }
            }

        }
        return ll;
}
