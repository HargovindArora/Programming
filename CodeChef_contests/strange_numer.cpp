#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void kFactors(int n, int k) 
{ 
    vector<int> P; 
  
    while (n%2 == 0) 
    { 
        P.push_back(2); 
        n /= 2; 
    } 
  
    for (int i=3; i*i<=n; i=i+2) 
    { 
        while (n%i == 0) 
        { 
            n = n/i; 
            P.push_back(i); 
        } 
    } 
    if (n > 2) 
        P.push_back(n); 
    if (P.size() >= k) 
    { 
        cout << 1 << endl; 
    } 
    else{
        cout << 0 << endl;
    }
    P.clear();
    return; 
} 


int main(){

    int t;
    cin >> t;
    while(t--){

        int x, k;
        cin >> x >> k;

        kFactors(x, k);
    }

    return 0;
}