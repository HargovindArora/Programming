#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n], load=0, max_load=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        load += arr[i];
    }
    if(load%n!=0){
        cout << -1 << endl;
    }
    else{

        load = load/n;
        int diff = 0;
        for(int i=0; i<n; i++){
            diff += (arr[i]-load);
            int ans = max(diff, -diff);
            max_load = max(ans, max_load);
        }
        cout << max_load << endl;
    }


    return 0;
}