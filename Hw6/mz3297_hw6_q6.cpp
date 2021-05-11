#include <iostream>
#include <string>
using namespace std;

bool isDigit(char ch);
bool containOnlyDigit(string str);
string findWord(string s, int start, int endSpace);

int main() {
    string userInput, word;
    int startInd, spaceInd,i;

    //Prompt the user to type an input string
    cout << "Please enter a line of text:" << endl;
    getline(cin, userInput);

    //Cases:
    //1. For any words that's not the last word, check to see if they are all digits, Yes --> replace\ with 'x'
    //   need to also change the starting and ending index location
    //2. If it is the last word, do the same check, Yes --> replace with 'x'

    startInd = 0;
    while(userInput.find(" ",startInd) != string:: npos){
        spaceInd = userInput.find(" ",startInd) ;
        word = findWord(userInput, startInd, spaceInd);

        if(containOnlyDigit(word)){
            for(i = startInd; i < startInd + word.length(); i++){
                userInput[i] = 'x';
            }
        }
        startInd = spaceInd + 1;
    }
    //check to see if the last word contains only numbers
    spaceInd = userInput.length() ;
    word = findWord(userInput, startInd, spaceInd);

    if(containOnlyDigit(word)){
        for(i = startInd; i < spaceInd + word.length(); i++){
            userInput[i] = 'x';
        }
    }

    cout << userInput;

    return 0;
}

//Helper to determine whether a character is a digit
bool isDigit(char ch) {
    bool isADigit = true;
    if (ch < '0' || ch > '9')
        isADigit = false;
    return isADigit;
}

//Helpter to determine whether a word contains only digits
bool containOnlyDigit(string str){
    bool containOnlyNum = true;
    int i;
    for(i = 0; i < str.length(); i++){
        if(isDigit(str[i]) == false) {
            containOnlyNum = false;
            break;
        }
    }
    return containOnlyNum;
}

//Helper to output the substring of interest that's a word with no space in between
string findWord(string s, int start, int endSpace){
    string word;
    word = s.substr(start, endSpace - start);
    return word;
}
