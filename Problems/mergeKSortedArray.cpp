#include<bits/stdc++.h>
#define ll long long int
using namespace std;

typedef pair<int, pair<int, int>> customPair;

vector<int> mergeKSortedArrays(int v[10][100001], int k, int n){

    vector<int> result;
    priority_queue<customPair, vector<customPair>, greater<customPair>> pq;
    for(int i=0; i<k; i++){
        pq.push({v[i][0], {i, 0}});
    }
    while(!pq.empty()){
        customPair curr = pq.top();
        pq.pop();
        int arrayNumber = curr.second.first;
        int arrayIndex = curr.second.second;
        result.push_back(curr.first);
        if(arrayIndex+1 < n){
            pq.push({v[arrayNumber][arrayIndex+1], {arrayNumber, arrayIndex+1}});
        }
    }

    return result;
}

int main(){

    int k, n;
    cin >> k >> n;
    int v[10][100001];
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    vector<int> output = mergeKSortedArrays(v, k, n);
    for(auto x:output){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}