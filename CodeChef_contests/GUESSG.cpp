#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

void solve()
{

    int n;
    cin >> n;

    int beg = 1, end = n, i = 0;
    int beg_p = beg, end_p = end;
    char c1, c2;
    while (1)
    {

        if (i % 2 == 0)
        {
            int m = (beg + end) / 2;
            cout << m << endl;
            cin >> c1;
            if (c1 == 'E')
            {
                return;
            }
            if (c1 == 'L')
            {
                end = m - 1;
                if (beg == end)
                {
                    end = end_p;
                    beg = beg_p;
                }
                continue;
            }
            if (c1 == 'G')
            {
                beg = m + 1;
                if (beg == end)
                {
                    beg = beg_p;
                    end = end_p;
                }
            }
        }
        else
        {
            int m = (beg_p + end_p) / 2;
            cout << m << endl;
            cin >> c2;
            if (c2 == 'E')
            {
                return;
            }
            if (c2 == 'L')
            {
                end_p = m - 1;
                if (beg == end)
                {
                    beg = beg_p;
                    end = end_p;
                }
                continue;
            }
            if (c2 == 'G')
            {
                beg_p = m + 1;
                if (beg == end)
                {
                    beg = beg_p;
                    end = end_p;
                }
            }
        }
        i++;
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}