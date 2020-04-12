#include<iostream>
#include<list>
#define endl '\n'
using namespace std;

int main(){

    list<int> l;

    list<int> l1{1,3,5,7,9};

    list<string> l2{"apple", "banana",  "grapes", "guava", "mango", "orange"};
    l2.push_back("pineapple");

    l2.sort();

    l2.reverse();

    cout << l2.front() << endl;
    l2.pop_front();

    l2.push_front("kiwi");
    cout << l2.back() << endl;
    l2.pop_back();

    for(auto s:l2){
        cout << s << "-->";
    }
    cout << endl;
    for(auto it=l2.begin(); it!=l2.end(); it++){
        cout << *it << "-->";
    }
    cout << endl;
    
    string f;
    cin >> f;
    l2.remove(f);
    for(auto s:l2){
        cout << s << "-->";
    }
    cout << endl;

    auto it = l2.begin();
    it++;
    it++;

    l2.erase(it);

    for(auto s:l2){
        cout << s << "-->";
    }
    cout << endl;

    it = l2.begin();
    it++;

    l2.insert(it, "juicy");

    for(auto s:l2){
        cout << s << "-->";
    }
    cout << endl;

    return 0;
}