#include <iostream>
using namespace std;
double eApprox(int n);


int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double eApprox(int n){
    int i, denom;
    double term;
    denom = 1;
    for (i = 1; i <= n; i++){
        denom *= i;
        term += (double)1/denom;
    }
    return term;
}


