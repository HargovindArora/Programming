#include<bits/stdc++.h>
#define endl '\n';
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        int l;
        cin >> l;
        int *arr = new int[l];
        for(int i=0; i<l; i++){
            cin >> arr[i];
        }
        unordered_map<int, int> mp;
        for(int i=0; i<l; i++){
            mp[arr[i]]++;
        }
        int q;
        cin >> q;
        while(q--){

            int n;
            cin >> n;

            if(mp.find(n)!=mp.end()){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }

    }

    return 0;
}