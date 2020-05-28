#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int l=0, r=0, j=0, maxLen=0, curLen=0, zeroCount=0;
    for(int i=0; i<n; i++){

        if(a[i]==0){
            zeroCount++;
        }
        while(zeroCount>k){
            if(a[j]==0){
                zeroCount--;
            }
            j++;
        }
        curLen = i-j+1;
        if(curLen>maxLen){
            maxLen = curLen;
            l=j, r=i;
        }
    }
    for(int i=l; i<=r; i++){
        a[i] = 1;
    }
    cout << maxLen << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}