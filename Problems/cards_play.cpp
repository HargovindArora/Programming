#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define pb push_back
using namespace std;

bool v[1000005];
//ll sp[5000005];
vector<int>prime_vector;
void Sieve()
{
    for(ll i = 2; i < 1000005; i += 2)  
       {
       //even numbers have smallest prime factor 2
        v[i]=true;
        //sp[i]=2;
       } 
         prime_vector.pb(2);
    for (ll i = 3; i < 1000005; i += 2)
    {
        if (!v[i])
        {   prime_vector.pb(i);
            for (ll j = i; (j*i) < 1000005; j += 2)
            {
                if (!v[j*i])    
                    v[j*i] = true;//sp[i*j]=i;
            }
        }
    }
}


int main(){
    Sieve();
    int n, q;
    cin >> n >> q;
    vector<stack<int>> a;
    stack<int> s;
    a.reserve(1000);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }
    a.push_back(s);

    vector<stack<int>> b;
    b.reserve(1000);

    for(int i=0; i<q; i++){
        stack<int> s, t;
        while(!a[i].empty()){

            if(((a[i].top())%(prime_vector[i]))==0){
                s.push(a[i].top());
                a[i].pop();
                continue;
            }
            else{
                t.push(a[i].top());
                a[i].pop();
            }

        }
        b.push_back(s);
        a.push_back(t);
    }

    for(int i=0; i<b.size(); i++){
        while(!b[i].empty()){
            cout << b[i].top() << endl;
            b[i].pop();
        }
    }

    for(int i=0; i<a.size(); i++){
        while(!a[i].empty()){
            cout << a[i].top() << endl;
            a[i].pop();
        }
    }

    return 0 ;
}