#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string word;
    //
    cout << "Please enter a word:";
    cin >> word;
    if (isPalindrome(word))
        cout << word << " is a palindrome";
    else
        cout << word << " is not a palindrome";
    return 0;
}
//Section a, - returns a bool indicating whether the input string is a palindrome
bool isPalindrome(string str){
    int i, j;
    bool palIndicator = true;
    for (i = 0, j = str.length()-1; i < str.length(), j >= 0; i++, j--){
        if (str[i] != str[j]){
            palIndicator = false;
            break;
        }
    }
    return palIndicator;
}

