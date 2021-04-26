#include <iostream>
#include <string>
using namespace std;
int const M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1;

int main() {

    int n, number;
    int count,sum;
    string RomanDig;
    cout << "Enter decimal number:" << endl;
    cin >> number;

    n = number;
    if(n/M > 0) {
        count = 1;
        sum = 0;
        while (count <= n/M){
            RomanDig += "M";
            sum += M;
            count ++;
        }
        n -= sum;
    }

    if (n / D >= 1) {
        n -= D;
        RomanDig += "D";
    }

    count = 1;
    sum = 0;
    if (n / C > 0) {
        if (n / C < 4) {
            while (count <= n / C) {
                RomanDig += "C";
                sum += C;
                count ++;
            }
        } else {
            count = 1;
            while (count <= 4) {
                RomanDig += "C";
                sum += C;
                count ++;
            }
        }
        n -= sum;
    }


    if (n / L >= 1){
        n -= L;
        RomanDig += "L";
    }

    count = 1;
    sum = 0;
    if (n / X > 0) {
        if (n / X < 4) {
            count = 1;
            while (count <= n / X) {
                RomanDig += "X";
                sum += X;
                count ++;
            }
        } else {
            count = 1;
            while (count <= 4) {
                RomanDig += "X";
                sum += X;
                count ++;
            }
        }
        n -= sum;
    }

    if (n / V >= 1) {
        n -= V;
        RomanDig += "V";
    }

    count = 1;
    sum = 0;
    if (n / I > 0) {
        if (n / I < 4) {
            count = 1;
            while (count <= n / I) {
                RomanDig += "I";
                sum += I;
                count ++;
            }
        } else {
            count = 1;
            while (count <= 4) {
                RomanDig += "I";
                sum += I;
                count ++;
            }
        }
        n -= sum;
    }

    cout << number<< " is " << RomanDig;

    return 0;
}
