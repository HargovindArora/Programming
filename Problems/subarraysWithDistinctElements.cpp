#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ll sum = 0;
    unordered_set<int> m;
    int j = 0;
    for(int i=0; i<n; i++){
        while(j<n and m.find(arr[j])==m.end()){
            m.insert(arr[j]);
            j++;
        }
        sum += ((j-i)*(j-i+1))/2;
        m.erase(arr[i]);
    }
    cout << sum%MOD << endl;

    return 0;
}