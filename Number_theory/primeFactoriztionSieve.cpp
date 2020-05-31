#include<iostream>
#include<vector>
using namespace std;

vector<int> primeSieve(int *p, int n){

    p[0] = p[1] = 0;
    p[2] = 1;

    for(int i=3; i<n; i+=2){
        p[i] = 1;
    }

    for(int i=3; i<n; i+=2){
        if(p[i]){
            for(int j=i*i; j<n; j+=(2*i)){
                p[j] = 0;
            }
        }
    }

    vector<int> prime;
    prime.push_back(2);
    for(int i=3; i<n; i+=2){
        if(p[i]==1){
            prime.push_back(i);
        }
    }
    return prime;
}

vector<int> factorize(int n, vector<int> &primes){

    vector<int> factors;
    int i=0;
    int p = primes[0];
    while(p*p<=n){
        if(n%p==0){
            factors.push_back(p);
            while(n%p==0){
                n = n/p;
            }
        }
        i++;
        p = primes[i];
    }
    if(n!=1){
        factors.push_back(n);
    }
    return factors;
}

int main(){

    int N = 1000000;
    int p[N+1];
    for(int i=0; i<N; i++){
        p[i] = 0;
    }
    vector<int> primes = primeSieve(p, N);

    int t;
    cin >> t;
    while(t--){

        int no;
        cin >> no;
        vector<int> factors = factorize(no, primes);
        for(auto f:factors){
            cout << f << " ";
        }

        cout << endl;
    }

    return 0;
}