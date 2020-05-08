#include<iostream>
#include<unordered_set>
using namespace std;

int longestConsecSubseq(int *arr, int n){
    
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s.find(arr[i]-1)!=s.end()){
            continue;
        }
        else{
            int count = 0;
            int x = arr[i];
            while(s.find(x)!=s.end()){
                count++;
                x++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = longestConsecSubseq(arr, n);
    cout << ans << endl;

    return 0;
}