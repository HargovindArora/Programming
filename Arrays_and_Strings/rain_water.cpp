#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> height;
    for(int i=0; i<10; i++){
        int x;
        cin >> x;
        height.push_back(x);
    }
    int n = height.size();
    if (n==0){
        return 0;
    }
    int lmax[n];
    int rmax[n];
    lmax[0] = height[0];
    for(int i=1; i<height.size(); i++){
        if(height[i]>lmax[i-1]){
        lmax[i] = height[i];
        continue;
        }
        lmax[i] = lmax[i-1];
    }
    for(int i=n-1; i>=0; i--){
        if(i == n-1){
            rmax[i] = height[i];
            continue;
        }
        if(height[i]>rmax[i+1]){
            rmax[i] = height[i];
            continue;
        }
        rmax[i] = rmax[i+1];
    }

    int store=0;
    for(int i=0; i<n; i++){
        store += min(lmax[i], rmax[i]) - height[i];
    }
    cout << store << endl;

    return 0;
}