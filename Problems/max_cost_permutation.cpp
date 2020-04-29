//https://hack.codingblocks.com/app/practice/5/1019/problem

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int sum=0;
    for(int i=0; i<n; i++){
        a[i] *= i;
        sum += a[i];
    }
    cout << sum << endl;


    return 0;
}