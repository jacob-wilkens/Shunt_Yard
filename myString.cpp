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
    string myChar;
    string TempString = "";

        for(int i = 0; i < s.length(); i++){
            myChar = s.at(i);
            TempString += myChar;
            if(compare(myChar, delimiters) == true){

                if(TempString.length() == 1){
                    ar[arIndex] = TempString;
                    arIndex++;
                    TempString = "";
                } else {
                    TempString.pop_back();
                    ar[arIndex] = TempString;
                    arIndex++;
                    TempString = myChar;
                    ar[arIndex] = TempString;
                    arIndex++;
                    TempString = "";
                } 
            } else {
                if(i == s.length() - 1){
                    ar[arIndex] = TempString;
                    break;
                }
            }

        }
        return ar;
}
