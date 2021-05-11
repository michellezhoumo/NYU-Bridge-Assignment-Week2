#include <iostream>
using namespace std;

int main() {
    int n, numOfEvenDig, numOfOddDig;
    int count, curr_num, countNumOfEvenGreaterThanNumOfOdd;

    cout << "Please enter a positive integer: ";
    cin >> n;

    countNumOfEvenGreaterThanNumOfOdd = 0;

    for(count = 1; count <= n; count ++){

        numOfEvenDig = 0;
        numOfOddDig = 0;

        for(curr_num = count; curr_num > 0; curr_num /=10){
            if(curr_num % 10 % 2 == 0)
                numOfEvenDig ++;
            else
                numOfOddDig ++;
        }

        if(numOfEvenDig > numOfOddDig)
            cout << count << endl;
            countNumOfEvenGreaterThanNumOfOdd ++;
    }

    return 0;
}
