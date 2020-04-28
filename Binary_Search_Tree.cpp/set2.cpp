#include<iostream>
#include<set>
using namespace std;

int main(){

    set<pair<int,int>> s;
    s.insert(make_pair(10,11));
    s.insert(make_pair(10,12));
    s.insert(make_pair(20,1));
    s.insert(make_pair(20,111));
    s.insert(make_pair(2,11));
    s.insert(make_pair(5,11));
    s.insert(make_pair(0,11));
    s.insert(make_pair(3,111));

    s.erase(s.find(make_pair(5,11)));
    s.insert(make_pair(5,4));

    auto it = s.upper_bound(make_pair(20,1));
    cout << it->first << " " << it->second << endl;

    for(auto p:s){
        cout << p.first << " and " << p.second << endl;
    }

    return 0;
}