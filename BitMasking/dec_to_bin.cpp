#include<iostream>
using namespace std;

long long int decToBin(long long int n){

    long long int ans = 0, p = 1;

    while(n>0){
        long long int last_bit = n&1;
        ans += p*last_bit;
        p = p*10;
        n = n>>1;
    }

    return ans;
}


int main(){

    long long int n;
    cin >> n;

    cout << decToBin(n) << endl;

    return 0;
}