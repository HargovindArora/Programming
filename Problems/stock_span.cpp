#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;


void printSpan(vector<int> v, int n){

    stack<int> s;
    vector<int> v2;

    for(int day=0; day<n; day++){

        int currPrice = v[day];
        while(!s.empty() && v[s.top()]<=currPrice){
            s.pop();
        }
        int betterDay = s.empty()? 0:s.top()+1;
        int span = day+1 - betterDay;
        s.push(day);
        v2.push_back(span);
    }

    for(auto x:v2){
        cout << x << " ";
    }
    cout << "END" << endl;
}


int main(){

    int n;
    cin >> n;

    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    printSpan(v, n);

    return 0;
}