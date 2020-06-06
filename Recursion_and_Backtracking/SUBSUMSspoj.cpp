#include<vector>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

vector<ll> subsets(vector<ll> v){

    vector<ll> ans;
    int n = v.size();
    for(int i=0; i<(1<<n); i++){

        int j=0;
        ll sum=0;
        for(int no=i; no>0; no=no>>1){
            if(no&1){
                sum += v[j];
            }
            j++;
        }
        ans.push_back(sum);
    }
    return ans;
}

int main(){



    return 0;
}