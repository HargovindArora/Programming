#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]] = i;
    }

    for(int i=n; i>=1; i--){
        int init = mp[i];
        int best = n-i;
        if(best==init){
            continue;
        }
        else{
            mp[i] = best;
            mp[arr[best]] = init;
            swap(arr[init], arr[best]);
            k--;
            if(k==0){
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}