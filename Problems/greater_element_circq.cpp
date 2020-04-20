#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

//O(n) approach using stack
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!s.empty() && nums[s.top()] <= nums[i % n])
        {
            s.pop();
        }

        res[i % n] = (s.empty() ? -1 : nums[s.top()]);
        s.push(i % n);
    }

    return res;
}

//O(n2) approach using queue, but better than bruteforce
int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> v;
    v.reserve(10000);
    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    queue<ll> q;
    for(int i=0; i<=n-1; i++){
        // if(i==n-1){
        //     int x=0;
        //     while(v[i]>=v[x] && x<i){
        //         x++;
        //     }
        //     if(x==i){
        //         q.push(-1);
        //         continue;
        //     }
        //     q.push(v[x]);
        //     continue;
        // }
        int j=i+1;
        while(v[i]>=v[j] && j<=n-1){
            j++;
        }
        if(j==n){
            int x=0;
            while(v[i]>=v[x] && x<i){
                x++;
            }
            if(x==i){
                q.push(-1);
                continue;
            }
            q.push(v[x]);
            continue;
        }
        q.push(v[j]);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}