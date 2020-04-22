#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

ll idealTime(deque<ll> given, deque<ll> ideal, ll n){

    ll total = 0;
    for(int i=0; i<n; i++){

        if(given.front()==ideal.front()){
            total += 1;
            given.pop_front();
            ideal.pop_front();
            continue;
        }

        while(given.front()!=ideal.front()){
            total += 1;
            ll x = given.front();
            given.pop_front();
            given.push_back(x);
        }

        total += 1;
        given.pop_front();
        ideal.pop_front();

    }
    
    return total;
}

int main(){

    ll n;
    cin >> n;
    deque<ll> given, ideal;
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        given.push_back(x);
    }
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        ideal.push_back(x);
    }

    cout << idealTime(given, ideal, n) << endl;

    return 0;
}