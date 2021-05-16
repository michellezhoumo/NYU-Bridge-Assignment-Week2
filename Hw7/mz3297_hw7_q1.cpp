#include <iostream>
#include <string>
using namespace std;
int countWords(string& s);
void arrangeStrAndPrintCharCount(string S);

const int NUMALPHABET = 26;

int main() {
    string str;
    cout << "Please enter a line of text:" << endl;
    getline(cin, str);
    cout << countWords(str) << "\twords" << endl;
    arrangeStrAndPrintCharCount(str);
    return 0;
}

//Returns the number of words in the input string
int countWords(string& s){
    int count, i;
    bool inWord = false;
    count = 0;

    //Will only count the word when the "inWord" boolean switch from false to true
    for(i = 0; i < s.length(); i++){
        if(s[i] == ' ' || s[i] == ',' || s[i] == '.'){
            inWord = false;
        }
        else if (inWord == false){
            count ++;
            inWord = true;
        }

    }

    //Get rid of all deliminators from the str, return via reference
    for(i = 0; i < s.length(); i++){
        if(s[i] == ' ' || s[i] == ',' || s[i] == '.'){
            s[i] = '\0';
        }
    }
    return count;
}

// arrange string in alphabetical order and print the number of each character
void arrangeStrAndPrintCharCount(string s){
    //Initialize count of all alphabet to 0
    int countChar[NUMALPHABET] = {0}, i;

    for (i = 0; i < NUMALPHABET; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            countChar[s[i] - 'a']++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            countChar[s[i] - 'A']++;
    }
    for (i = 0; i < NUMALPHABET; i++){
        if(countChar[i] != 0)
            cout << countChar[i] << "\t" << static_cast<char>('a'+ i) << endl;
    }
}
