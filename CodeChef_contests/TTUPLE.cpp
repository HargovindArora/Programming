#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

void solve()
{

    int p, q, r;
    cin >> p >> q >> r;
    int a, b, c;
    cin >> a >> b >> c;

    ll ans = 0;

    while (1)
    {

        a = a % p;
        b = b % q;
        c = c % r;

        if (a == b && a == c)
        {
            ans += 1;
            break;
        }
        ans += 1;
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}