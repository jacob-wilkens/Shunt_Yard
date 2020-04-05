#include <string.h>
#include <iostream>
#include "myString.hpp"
#include "Stack.hpp"
#include "LinkedList.hpp"
#include<string>

using namespace std;

void cleanup(Queue* outputQ, LinkedList* opList){//clears the list to output queue
    int opListLength = opList->getCount();
    for(int i = 0; i < opListLength; i++){
    outputQ->enqueue(opList->removeFront());
    } 
}

int stringIsInt(string s){//checks to see if the string can convert to int
    int val;
    try {
        val = stoi(s);
    } catch(exception a)
    {
        val = 0;
    }
    return val;
}
int opperandValue(string s){//determines the value of the opperator for precendence
    if( s == "+" or s == "-"){
        return 1;
    } else if (s == "*" or s == "/"){
        return 2;
    } else if(s == "("){
        return 3;
    } else if (s == ")"){
        return 4;
    } else if (s == "^"){
        return 5;
    }
}

int perenClean(Queue* outputQ, LinkedList* opList){//when a closed peren is found this cleans out the opList to output queue
    bool reached = false;
    int i = 0;
    while(i < opList->getCount() || reached == false){
        if(opList->getFront() == "("){
            opList->removeFront();
            reached = true;
            return i;
        } else {
            outputQ->enqueue(opList->removeFront());
            i++;
        }
    }
}

void precedenceRules(Queue* inputQ, Queue* outputQ, LinkedList* opList){
    int length = inputQ->getCount();
    int currentOp;
    int previousOp;
    int opCount = 0;
    int opInPeren = 0;
    int opListLength;
    bool openPeren = false;
    
    for(int i = 0; i < length; i++){
        string s = inputQ->dequeue();
        
        if(stringIsInt(s) != 0){//adds num to output queue
            outputQ->enqueue(s);
            continue;
        } else if(opperandValue(s) == 5){//exponent
            opList->addFront(s);
        } else if(opperandValue(s) == 4){//closed peren
            opCount -= perenClean(outputQ, opList);
            previousOp = opperandValue(opList->getFront());
            openPeren = false;

        } else if(openPeren == true){//for open peren

            if(opInPeren == 0){//first op after open peren
                opList->addFront(s);
                previousOp = opperandValue(s);
                opCount++;
                opInPeren++;
            } else if(opInPeren > 0){//rules for ops after first one
                currentOp = opperandValue(s);
                if(currentOp > previousOp){
                    previousOp = currentOp;
                    opList->addFront(s);
                    opInPeren++;
                } else if(currentOp == previousOp){
                    outputQ->enqueue(opList->removeFront());
                    opList->addFront(s);
                    opInPeren--;
                }
                opCount++;
                previousOp = currentOp;
            }

        }
        else {//for operator
            currentOp = opperandValue(s);
            if(opCount == 0){//first operator
                previousOp = opperandValue(s);
                opCount++;
                opList->addFront(s);
                continue;
            } else if(currentOp == 3){//open peren
                opList->addFront(s);
                opCount++;
                openPeren = true;
                continue;
            } else if(currentOp > previousOp){//new operator is greater than previous
                previousOp = currentOp;
                opList->addFront(s);
            } else if(currentOp == previousOp){//operators are equal
                outputQ->enqueue(opList->removeFront());
                opList->addFront(s);
            }
            opCount++;
            previousOp = currentOp;
        } 
    }
    cleanup(outputQ, opList);//dump rest of op stack
}

int main(){
    string str = "3+4*2/(1-5)^2^3";
    string delims = "+-*/()^";

    Queue* inputQ = myString::split(str, delims);
    Queue* outputQ = new Queue();
    LinkedList* opList = new LinkedList();

    precedenceRules(inputQ, outputQ, opList);

    cout << "------------------------" << "\n";
    outputQ->display();
    cout << "------------------------" << "\n";
    opList->display();
    delete opList, inputQ;

}

