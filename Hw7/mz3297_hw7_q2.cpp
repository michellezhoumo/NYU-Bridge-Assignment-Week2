#include <iostream>
#include <string>
using namespace std;

const int NUMALPHABET = 26;

void eliminateDelim(string& s);
int * mapOccurrence(string s);
bool determineAnagram(string s1, string s2);

int main() {
    string str1 = "Eleven plus two";
    string str2 = "Twelve plus one";
    if (determineAnagram(str1, str2))
        cout << "\"" << str1 << "\" and \"" << str2 << "\" " << "are anagrams of each other";
    else
        cout << "\"" << str1 << "\" and \"" << str2 << "\" " << "are NOT anagrams of each other";
    return 0;
}

//Get rid of all deliminators from a string
void eliminateDelim(string& s){
    for (int i = 0; i < s.length(); i++){
        if(!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z'))
            s[i] = '\0';
    }
}

//Map number of occurrence of a char to char(as index) via int *
int * mapOccurrence(string s){
    int * countOccur = new int[NUMALPHABET]{0};
    for (int i = 0; i < NUMALPHABET; i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            countOccur[s[i] -'a']++;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            countOccur[s[i] -'A']++;
    }
    return countOccur;
}

//Determine whether 2 strings are anagrams of each other
bool determineAnagram(string s1, string s2){

    eliminateDelim(s1);
    eliminateDelim(s2);

    int * s1Arr, * s2Arr;
    bool isAnagram = true;

    if(s1.length() != s2.length()){
        isAnagram = false;
    }
    else {
        s1Arr = mapOccurrence(s1);
        s2Arr = mapOccurrence(s2);

        for (int i = 0; i < NUMALPHABET; i++) {
            if (*(s1Arr + i) != *(s2Arr + i)) {
                isAnagram = false;
                break;
            }
        }
        delete[] s1Arr;
        delete[] s2Arr;
    }
    return isAnagram;
}