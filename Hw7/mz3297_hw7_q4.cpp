#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArSize);

int main() {
    string s = "You can do it";
    int arSize, i;
    string * sArr;
    sArr = createWordsArray(s, arSize);
    cout << "String Array = [";
    for (i = 0; i < arSize; i++) {
        if (i == arSize - 1)
            cout << *(sArr + i);
        else
            cout << *(sArr + i) << ", ";
    }
    cout << "]" << endl;
    cout << "Current Array Size = " << arSize << endl;
    delete[] sArr;
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArSize){
    int aSize, start,i;
    string * words = new string[aSize]{"x"};
    aSize = 0;
    start = 0;
    i = 0;
    while(sentence.find(" ",start) != string:: npos){
        words[i] = sentence.substr(start,sentence.find(" ",start) - start);
        start = sentence.find(" ",start) + 1;
        aSize ++;
        i++;
    }
    //add the last word to string array and increase the array size to include the last word;
    words[i] = sentence.substr(start, sentence.length() - start);
    aSize++;
    outWordsArSize = aSize;
    return words;
}