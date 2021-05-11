#include <iostream>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void printPerfectNumberAndAmicableNumber(int M);

int main() {
    int M;
    cout << "Please enter a positive integer >= 2:";
    cin >> M;
    printPerfectNumberAndAmicableNumber(M);
    return 0;
}

//Section A. Function that gets the count and sum of proper divisors of a given input
void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs){
    int i,j, count, sum;
    count = 0;
    sum = 0;
    for (i= 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            sum += i;
            count ++;
        }
    }

    if (sqrt(num) == (int)sqrt(num))
        j = i - 2;
    else
        j = i - 1;

    for (i = j; i >= 1; i--) {
        if (num % i == 0) {
            if(num/i != num)
                sum += num/i;
            count++;
        }
    }
    count --;
    outCountDivs = count;
    outSumDivs = sum;
}

//Section B. return true if the num is the sum of its proper divisors
bool isPerfect(int num){
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);
    //cout << countDivs << " ";
    //cout << sumDivs;
    if (sumDivs == num)
        return true;
    else
        return false;
}

//Section C. prints all perfect numbers and amicable numbers
void printPerfectNumberAndAmicableNumber(int num){
    int i, iCountDiv, iSumDiv, currNum, currCount, currSum;
    cout << "List of Perfect Number: " << endl;
    for (i = 1; i <= num; i++){
        if(isPerfect(i)){
            cout << i << " ";
        }
    }
    cout << endl << "List of Amicable Number: " << endl;
    for (i = 1; i <= num; i++) {
        analyzeDivisors(i, iCountDiv, iSumDiv);
        currNum = iSumDiv;
        analyzeDivisors(currNum, currCount, currSum);
        if (i == currSum && i != currNum)
            cout << i << " ";
    }
    cout << endl;
}

