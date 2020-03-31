#include <string.h>
#include <iostream>
#include <string>
#include "myString.hpp"

using namespace std;

bool myString::compare(string character, string delimiters){
    
    for(int i = 0; i < delimiters.length(); i++ ){
        if(character.at(0) == delimiters.at(i)){
            return true;
        }
    }

    return false;
}

 queue* myString::split(string s, string delimiters){
    int start = 0;
    int count = 0;
    string myChar;
    queue* myQ = new queue();

        for(int i = 0; i < s.length(); i++){
            myChar = s.at(i);
            count++;
            if(compare(myChar, delimiters) == true){
                if(count == 1){
                    myQ->enqueue(myChar);
                    count = 0;
                    start = i + 1;
                } else {
                myQ->enqueue(s.substr(start, count - 1));
                myQ->enqueue(myChar);
                start = i + 1;
                count = 0;
                }
            } else {
                if(i == s.length() - 1){
                    myQ->enqueue(s.substr(start, count));
                    break;
                    
                }
            }

        }
        return myQ;
}

