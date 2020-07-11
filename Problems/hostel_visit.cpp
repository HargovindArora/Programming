#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

ll rocketDistance(ll x, ll y) {
    return x*x + y*y;
}
int main(int argc, char const *argv[])
{
    int q, k, x, y, type;
    cin>>q>>k;
    priority_queue<ll> pq;
    for(ll i=0;i<q;i++) {
        cin>>type;
        if(type==1) {
            cin>>x>>y;
            if(pq.size()==k) {
                if(rocketDistance(x, y)<pq.top()) {
                    pq.pop();
                    pq.push(rocketDistance(x, y));
                }
            } else {
                pq.push(rocketDistance(x, y));
            }
        } else {
            cout<<pq.top()<<endl;
            cout << pq.size() << endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <set>
// using namespace std;
// #define ll long long int;
// multiset<ll> distances;
// int main() {
//     ll n, k;
//     cin >> n >> k;
//     for(ll i = 0; i < n; ++i) {
//         ll query; 
//         cin >> query;
//         if (query == 1) {
//             ll x, y;
//             cin >> x >> y;
//             distances.insert(x * x + y * y);
//             if (distances.size() > k) {
//                 distances.erase(--distances.end());
//             }
//         } else {
//             cout << *distances.rbegin() << '\n';
//         }
//     }
//     return 0;
// }