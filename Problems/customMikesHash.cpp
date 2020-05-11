#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map<int, int> m;

bool compare(int a, int b){
    return m[a]<m[b];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){

        int x;
        cin >> x;
        if(m.find(x)==m.end()){
            v.push_back(x);
        }
        m[x] = i;

    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}