#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> a;

    int n;
    cin >> n; // Number of elements
    vector<int> b(n,4); //n elements having value 4

    vector<int> c(b.begin(), b.end()); //Copy b in c

    vector<int> d{1, 23, 456, 7890}; // Vector with these specific value

    for(auto it=b.begin(); it!=b.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;

    int c_length = c.size();
    for(int i=0; i<c.size(); i++){
        cout << c[i] << " ";
    }
    cout << endl;

    for(auto x:d){
        cout << x << " ";
    }
    cout << endl;
    cout << d.max_size() << endl;
    cout << d.size() << endl;
    cout << d.capacity() << endl;
 
    return 0;
}