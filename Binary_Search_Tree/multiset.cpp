#include<set>
#include<iostream>
using namespace std;

typedef multiset<int>::iterator It;

int main(){

    int arr[] = {11, 41, 22, 11, 16, 9, 369, 369, 369, 369, 369};
    int n = sizeof(arr)/sizeof(int);
    multiset<int> m(arr, arr+n);

    // for(int x:m){
    //     cout << x << " ";
    // }
    m.erase(11);
    m.insert(89);

    for(int x:m){
        cout << x << " ";
    }
    cout << endl << m.count(11) << endl;

    auto it = m.find(369);
    cout << (*it) << endl;

    pair<It, It> p = m.equal_range(369);

    for(auto it=p.first; it!=p.second; it++){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it=m.lower_bound(10); it!=m.upper_bound(90); it++){
        cout << *it << "-";
    }

    return 0;
}