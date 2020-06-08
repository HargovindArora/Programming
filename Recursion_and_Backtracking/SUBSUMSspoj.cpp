#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> subsets(vector<ll> v)
{

    vector<ll> ans;
    int n = v.size();
    for (int i = 0; i < (1 << n); i++)
    {

        int j = 0;
        ll sum = 0;
        for (int no = i; no > 0; no = no >> 1)
        {
            if (no & 1)
            {
                sum += v[j];
            }
            j++;
        }
        ans.push_back(sum);
    }
    return ans;
}

int main()
{

    vector<ll> v1, v2;
    int n, a, b;
    cin >> n >> a >> b;
    int n1 = n / 2;
    int n2 = n - n1;

    for (int i = 0; i < n1; i++)
    {
        ll x;
        cin >> x;
        v1.emplace_back(x);
    }
    for (int i = 0; i < n2; i++)
    {
        ll x;
        cin >> x;
        v2.emplace_back(x);
    }

    vector<ll> sum1, sum2;
    sum1 = subsets(v1);
    sum2 = subsets(v2);
    sort(sum2.begin(), sum2.end());

    ll ans = 0;
    for (int i = 0; i < sum1.size(); i++)
    {

        ll lo = a - sum1[i];
        ll hi = b - sum1[i];
        auto it1 = lower_bound(sum2.begin(), sum2.end(), lo);
        auto it2 = upper_bound(sum2.begin(), sum2.end(), hi);
        ans += it2 - it1;
    }
    cout << ans << endl;

    return 0;
}