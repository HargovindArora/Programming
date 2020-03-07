#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string x, string y){

    string xy = x.append(y);
    string yx = y.append(x);

    return xy.compare(yx) > 0 ? true: false;

}

int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;
        vector <string> sv;

        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            sv.push_back(s);
        }

        sort(sv.begin(), sv.end(), compare);

        for(int i=0; i<n; i++){
            cout << sv[i];
        }
    }
    
    return 0;
}