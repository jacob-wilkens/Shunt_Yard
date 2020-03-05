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

 string* myString::split(string s, string delimiters){
    string* ar = new string[s.length()];
    int arIndex =  0;
    int start = 0;
    int count = 0;
    string myChar;

        for(int i = 0; i < s.length(); i++){
            myChar = s.at(i);
            count++;
            if(compare(myChar, delimiters) == true){
                ar[arIndex] = s.substr(start, count - 1);
                arIndex++;
                ar[arIndex] = s.at(i);
                arIndex++;
                start = i + 1;
                count = 0;
            } else {
                if(i == s.length() - 1){
                    ar[arIndex] = s.substr(start, count);
                    break;
                }
            }

        }
        return ar;
}
