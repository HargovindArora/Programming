#include<iostream>
#include<set>
using namespace std;

int main(){

    int arr[] = {10, 2, 1, 9, 5, 3, 7, 8, 4};
    int n = sizeof(arr)/sizeof(int);

    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    s.erase(10);
    //OR
    auto it = s.find(8);
    s.erase(it);

    for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;

    return 0;
}