#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.first>p2.first;
}

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end(), compare);
    int D, F;
    cin >> D >> F;
    for(int i=0; i<n; i++){
        v[i].first = D-v[i].first;
    }
    priority_queue<int> pq;
    int prev=0, curr=0, ans=0, flag=0;
    while(curr<n){

        if(F>=(v[curr].first-prev)){
            F = F-(v[curr].first-prev);
            pq.push(v[curr].second);
            prev = v[curr].first;
        }
        else{
            if(pq.empty()){
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans++;
            continue;
        }
        curr++;
    }
    if(flag==1){
        cout << -1 << endl;
    }
    else{
        D = D-v[n-1].first;
        if(F>=D){
            cout << ans << endl;
        }
        else{
            while(F<D){

                if(pq.empty()){
                    flag=1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;
            }
            if(flag==1){
                cout << -1 << endl;
            }
            else{
                cout << ans << endl;
            }
        }
    }

    return 0;
}