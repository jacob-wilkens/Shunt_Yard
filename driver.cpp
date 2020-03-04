#include <string.h>
#include <iostream>

using namespace std;

bool compare(char character[], char delims[]){
    
    for(int i = 0; i < strlen(delims); i++ ){
        if(character[0] == delims[i]){
            return true;
        }
    }

    return false;
}

char* split(char stuff[], char delims[]){
    int i = 0;//count
    int arrayIndex = 0;
    char tempString[strlen(stuff)];//temp string
    char* characterArray[strlen(stuff)];

    while(i < strlen(stuff)){
        char singleCharacter[1] = {stuff[i]};

        if (compare(singleCharacter,delims) == true && i != 0){
            //cout << "temp string is " << tempString << "\n";
            characterArray[arrayIndex] = tempString;
            //<< "array index is " << characterArray[arrayIndex] << "\n";
            arrayIndex++;
            //cout << "single char is " << singleCharacter << "\n";
            characterArray[arrayIndex] = singleCharacter;
            //cout<< "array index is " << characterArray[arrayIndex] << "\n";
            arrayIndex++;
            memset(tempString, 0, sizeof(tempString));
            //cout << "temp string is " << tempString << "\n";
            

        } else if (i == 1 && compare(singleCharacter, delims) == true){
            characterArray[arrayIndex] = singleCharacter;
            arrayIndex++;

        } else {
            strcat(tempString, singleCharacter);
            if(i == strlen(stuff) - 1){
                //cout << "temp string is " << tempString << "\n";
                characterArray[arrayIndex] = tempString;
                //cout<< "array index is " << characterArray[arrayIndex] << "\n";
            }
        }
        
        i++;

   }
   return *characterArray;

}
int main(){
    char s[] = "123+13-2";
    char delims[] = "+-*/";
    char* myArr = split(s, delims);

}

