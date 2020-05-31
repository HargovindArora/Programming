#include<iostream>
#include<vector>
#include<bitset>
#define ll long long int
using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void sieve(){

    b.set(); // Set all bits
    b[0] = b[1] = 0;
    for(ll i=2; i<=n; i++){
        if(b[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=n; j=j+2*i){
                b[j] = 0;
            }
        }
    }
}

bool isPrime(ll no){

    if(no<=n){
        return (b[no]==1)? true:false;
    }
    for(ll i=0; primes[i]*(ll)primes[i]<=no; i++){
        if(no%primes[i]==0){
            return false;
        }
    }
    return true;
}

int main(){

    sieve();
    if(isPrime(21474836476)){
        cout << "Prime" << endl;
    }
    else{
        cout << "Composite" << endl;
    }

    return 0;
}