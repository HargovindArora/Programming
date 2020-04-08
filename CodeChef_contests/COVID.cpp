#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<int> v;
        int count = 0, flag=0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(int i=0; i<n; i++){

            if(count==0 && v[i]==0){
                continue;
            }
            if(v[i]==1 && count==0){
                count = 1;
                continue;
            }
            if(v[i]==1 && count!=0){
                if(count>=6){
                    count = 1;
                    continue;
                }
                else{
                    cout << "NO" << endl;
                    flag=1;
                    break;
                }
            }
            count++;
        }
        if(!flag){
            cout << "YES" << endl;
        }
    }

    return 0;
}