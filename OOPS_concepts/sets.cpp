#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int> s;

    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(3);
    s.insert(1);

    for(auto x:s){
        cout << x << ", ";
    }
    cout << endl;
    for(set<int>::iterator it=s.begin(); it!=s.end(); it++){
        cout << *it << ", ";
    }

    return 0;
}