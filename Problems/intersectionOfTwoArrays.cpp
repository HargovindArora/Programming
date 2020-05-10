#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main(){

    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }

    vector<int> intersection;
    for(int i=0; i<n; i++){
        if(mp.find(b[i])!=mp.end()){
            if(mp[b[i]]>0){
                mp[b[i]]--;
                intersection.push_back(b[i]);
            }
        }
    }
    sort(intersection.begin(), intersection.end());

    cout << "[";
    for(int i=0; i<intersection.size(); i++){
        if(i==intersection.size()-1){
            cout << intersection[i];
            continue;
        }
        cout << intersection[i] << ", ";
    }
    cout << "]" << endl;

    return 0;
}