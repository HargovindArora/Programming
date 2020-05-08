#include<iostream>
#include<unordered_set>
using namespace std;

bool subarrayWithSumZero(int *arr, int n){

    unordered_set<int> s;
    int pre = 0;
    for(int i=0; i<n; i++){
        pre += arr[i];
        if(pre==0 or s.find(pre)!=s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool b = subarrayWithSumZero(arr, n);
    if(b==0){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
    }

    return 0;
}