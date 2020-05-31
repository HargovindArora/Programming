#include<iostream>
#include<vector>
#include<bitset>
#define ll long long int
using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

vector<ll> primeSieve(ll *p, ll n){

    p[0] = p[1] = 0;
    p[2] = 1;

    for(ll i=3; i<n; i+=2){
        p[i] = 1;
    }

    for(ll i=3; i<n; i+=2){
        if(p[i]){
            for(ll j=i*i; j<n; j+=(2*i)){
                p[j] = 0;
            }
        }
    }

    vector<ll> prime;
    prime.push_back(2);
    for(ll i=3; i<n; i+=2){
        if(p[i]==1){
            prime.push_back(i);
        }
    }
    return prime;
}

ll numOfDivisors(ll n, vector<ll> &primes){

    
    ll i=0;
    ll p = primes[0];
    ll ans=1;
    while(p*p<=n){
        if(n%p==0){
            ll count=0;
            while(n%p==0){
                count++;
                n = n/p;
            }
            ans = ans*(count+1);
        }
        i++;
        p = primes[i];
    }
    if(n!=1){
        ans = ans*2;
    }
    return ans;
}

int main(){

    ll N = 100000;
    ll p[N+1];
    for(ll i=0; i<N; i++){
        p[i] = 0;
    }
    vector<ll> primes = primeSieve(p, N);

    ll t;
    cin >> t;
    while(t--){

        ll no;
        cin >> no;
        ll divs = numOfDivisors(no, primes);

        cout << divs << endl;
    }

    return 0;
}