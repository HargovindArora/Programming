#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

    map<string, int> m;
    //1. Insert
    m.insert(make_pair("Burger", 100));
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);
    m["Pizza"] = 100;
    // 2. Search
    string item;
    cin >> item;
    m[item] -= 20;
    map<string, int>::iterator it = m.find(item);
    if(it!=m.end()){
        cout << "Price of " << item << " is " << m[item] << endl;
    }
    m.erase(item);
    if(m.count(item)){
        cout << "Price is " << m[item] << endl;
    }
    else{
        cout << "Not present!" << endl;
    }
    // 3. Iterate over
    m["Patty"] = 15;
    m["Chicken Lollipop"] = 100;
    for(auto it=m.begin(); it!=m.end(); it++){
        cout << it->first << " and " << it->second << endl;
    }
    for(auto x:m){
        cout << x.first << " : " << x.second << endl;
    }

    return 0;
}