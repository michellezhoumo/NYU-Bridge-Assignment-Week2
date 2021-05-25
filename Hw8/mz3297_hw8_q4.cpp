#include <iostream>
using namespace std;

int lowestCost(int cost[], int n);

int main() {
    int c[] = {0,3,80,6,57,10};
    cout << "Current Game Board = ";
    for(int i : c)
        cout << i << "  ";
    cout << endl << "The lowest cost for the current gameboard is: " << lowestCost(c, 6);
    return 0;
}

//n is the size of costArr
int lowestCost(int cost[], int n){
    int sum = 0, i;
    if(n == 1){
        sum = cost[0];
    }
    else if(n == 2){
        sum = cost[0] + cost[1];
    }
    else if(n == 3){
        sum = cost[0] + cost[2];
    }
    else {
        if (lowestCost(cost + 1, n - 1) > lowestCost(cost + 2, n - 2))
            sum += lowestCost(cost + 2, n - 2) + cost[0];
        else
            sum += lowestCost(cost + 1, n - 1) + cost[0];
    }
    return sum;
}
