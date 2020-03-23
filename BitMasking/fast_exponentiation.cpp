#include<iostream>
using namespace std;

int raise_to(int a, int n){
    int ans = 1;

    while(n>0){
        int last_bit = n&1;
        if(last_bit){
            ans = ans*a;
        }
        a = a*a;
        n = n>>1;
    }

    return ans;
}


int main(){

    int num, power;
    cin >> num >> power;

    cout << raise_to(num, power) << endl;

    return 0;
}