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
    int sum = 0;
    if(n == 3){
        if((cost[0] + cost[1]) <= (cost[0] + cost[2]))
            sum += (cost[0] + cost[1]);
        else
            sum += (cost[0] + cost[2]);
    }
    else{
        if(n % 2 == 0) {
            sum += cost[n - 1];
            n = n-1;
        }
        if (cost[n - 2] <= cost[n - 1])
            sum += lowestCost(cost, n - 2) + cost[n - 2];
        else
            sum += lowestCost(cost, n - 2) + cost[n - 1];
    }
    return sum;
}
