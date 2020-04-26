#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void solve(){

    int n, s, max1=INT_MAX, max2=INT_MAX;
    cin >> n >> s;

    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i=0; i<n; i++){

        int x;
        cin >> x;
        if(x==0){
            max1 = min(max1, v[i]);
        }
        if(x==1){
            max2 = min(max2, v[i]);
        }

    }
    if(max1==INT_MAX || max2==INT_MAX ){
        cout << "no" << endl;
    }
    else if(max1+max2+s<=100){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}