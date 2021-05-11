#include <iostream>
using namespace std;

int main() {
    int n;
    int space, star;
    int countSpace, countStar;

    cout << "Please enter a positive integer: ";
    cin >> n;

    space = 0;
    star = 2 * n - 1;

    for(space = 0,star = 2 * n - 1; star >= 1; space ++, star -= 2){
        for (countSpace = 0; countSpace < space; countSpace ++)
            cout << " ";
        for (countStar = 0; countStar < star; countStar ++)
            cout << "*";
        for (countSpace = 0; countSpace < space; countSpace ++)
            cout << " ";
        cout << endl;
    }

    for(space = n-1, star = 1; star <= 2 * n - 1; space --, star += 2){
        for (countSpace = 0; countSpace < space; countSpace ++)
            cout << " ";
        for (countStar = 0; countStar < star; countStar ++)
            cout << "*";
        for (countSpace = 0; countSpace < space; countSpace ++)
            cout << " ";
        cout << endl;
    }

    return 0;
}
