#include<iostream>
using namespace std;

// TC = O(log(n))
int countBits(int n){

    int ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}


int countBitsBetter(int n){

    int ans=0;
    while(n>0){
        n = n&(n-1);
        ans++;
    }
    return ans;
}


int main(){

    int n;
    cin >> n;

    cout << countBitsFastest(n) << endl;
    cout << __builtin_popcount(n) << endl;

    return 0;
}