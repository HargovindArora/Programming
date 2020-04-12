#include<iostream>
#include<list>
#define endl '\n'
using namespace std;

int main(){

    list<pair<int, int>> *l;
    int n;
    cin >> n;

    l = new list<pair<int, int>>[n];

    int e;
    cin >> e;
    for(int i=0; i<e; i++){

        int x,y,weight;
        cin >> x >> y >> weight;
        l[x].push_back(make_pair(y, weight));
        l[y].push_back(make_pair(x, weight));
    }

    for(int i=0; i<n; i++){

        cout << "Linked List " << i << " -> ";
        for(auto x:l[i]){
            cout << "(" << x.first << ", " << x.second << ")" << ", ";
        }
        cout << endl;
    }

    return 0;
}