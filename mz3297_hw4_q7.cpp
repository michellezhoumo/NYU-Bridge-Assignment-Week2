#include <iostream>
using namespace std;

int main() {
    int n,countH,countV;
    cout <<"Please enter a positive integer:" << endl;
    cin >> n;

    for(countH = 1; countH <= n; countH ++){
        for(countV = countH; countV <= countH * n; countV += countH){
            cout << countV << "    " ;
        }
        cout << endl;
    }
    return 0;
}
