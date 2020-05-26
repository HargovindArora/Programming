#include<iostream>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second >= p2.second;
}

int main(){

    int n, s;
    cin >> n >> s;
    pair<int, int> a[n];
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[i].first = x;
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[i].second = x;
    }
    // for(int i=0; i<n; i++){
    //     cout << a[i].first << " ";
    // }cout << endl;
    sort(a, a+n, compare);
    // for(int i=0; i<n; i++){
    //     cout << a[i].first << " ";
    // }cout << endl;
    int sum=0, allocated=0;
    int i;
    for(i=0; i<n; i++){
        if(s>=0){
            s -= a[i].first;
            sum += a[i].second;
        }
        else{
            continue;
        }
    }
    cout << sum << endl;

    return 0;
}