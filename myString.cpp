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

int myString::counting(string s, string delimiters){
    string myChar;
    int count = 0;
    int delimCount = 0;

    for(int i = 0; i < s.length(); i++){
            myChar = s.at(i);
            delimCount++;
            if(compare(myChar, delimiters) == true){
                if(delimCount == 1){
                    count++;
                    delimCount = 0;
                } else {
                count += 2;
                delimCount = 0;
                }
            } else {
                if(i == s.length() - 1){
                    break;   
                }
            }

        }
        return count;
}

 queue* myString::split(string s, string delimiters){
    string* ar = new string[counting(s, delimiters)];
    int arIndex =  0;
    int start = 0;
    int count = 0;
    string myChar;

        for(int i = 0; i < s.length(); i++){
            myChar = s.at(i);
            count++;
            if(compare(myChar, delimiters) == true){
                if(count == 1){
                    ar[arIndex] = s.at(i);
                    count = 0;
                    arIndex++;
                    start = i + 1;
                } else {
                ar[arIndex] = s.substr(start, count - 1);
                arIndex++;
                ar[arIndex] = s.at(i);
                arIndex++;
                start = i + 1;
                count = 0;
                }
            } else {
                if(i == s.length() - 1){
                    ar[arIndex] = s.substr(start, count);
                    break;
                    
                }
            }

        }
        return transfer(ar, counting(s, delimiters));
}
queue* myString::transfer(string* s, int length){
    queue* myQ = new queue();

    for(int i = 0; i < length; i++){
        myQ->enqueue(s[i]);
    }

    return myQ;
}
