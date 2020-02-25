#include<iostream>
using namespace std;

int factorial(int n){
    int result=1;
    for(int i=1; i<=n; i++){
        result = result*i;
    }
    return result;
}

int main(){
    int n,r;
    cin >> n >> r;

    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n-r);

    int nCr = nfact/(rfact*nrfact);

    cout << nCr << endl;;

    return 0;
}