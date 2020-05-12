#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){

    return p1.first>p2.first;
}

int main(){

    int n, d, f, t;
    cin >> t;
    while(t--){
        
        int flag = 0, ans = 0;
        vector<pair<int, int>> v;
        priority_queue<int> pq;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> d >> f;
            v.push_back(make_pair(d,f));
        }
        sort(v.begin(), v.end(), compare);
        int D,F;
        cin >> D >> F;
        for(int i=0; i<n; i++){
            v[i].first = D-v[i].first;
        }
        int prev = 0;
        int curr = 0;
        while(curr<n){

            if(F>=(v[curr].first-prev)){
                F = F-(v[curr].first-prev);
                pq.push(v[curr].second);
                prev = v[curr].first;
            }
            else{
                if(pq.empty()){
                    flag=1;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans = ans+1;
                continue;
            }
            curr++;
        }
        if(flag==1){
            cout << -1 << endl;
            continue;
        }
        D = D-v[n-1].first;
        if(F>=D){
            cout << ans << endl;
            continue;
        }
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
            continue;
        }
        cout << ans << endl;

    }

    return 0;
}