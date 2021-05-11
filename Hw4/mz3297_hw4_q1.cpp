#include <iostream>
using namespace std;

int main() {
    int n, count;
    cout << "Section A - While Loop" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n;

    count = 1;
    while(count <= n){
        cout << 2 * count << endl;
        count ++;
    }

    cout << "Section B - For Loop" << endl;
    cout << "Please enter a positive integer: ";
    cin >> n;

    for(count = 1; count <= n; count ++){
        cout << 2 * count << endl;
    }
    return 0;
}
