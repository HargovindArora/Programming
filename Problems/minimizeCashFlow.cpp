#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

void solve()
{

    int person, transaction;
    cin >> person >> transaction;
    int balance[10000] = {0};

    for (int i = 0; i < transaction; i++)
    {
        int p1, p2, amount;
        cin >> p1 >> p2 >> amount;
        balance[p1] -= amount;
        balance[p2] += amount;
    }
    multiset<pair<int, int>> s;
    for (int i = 0; i < person; i++)
    {
        s.insert(make_pair(balance[i], i));
    }

    while (!s.empty())
    {

        auto front = *(s.begin());
        s.erase(s.begin());
        auto end = *(prev(s.end()));
        s.erase(prev(s.end()));

        int front_amount = front.first;
        int front_person = front.second;
        int end_amount = end.first;
        int end_person = end.second;

        int settle_amount = min(-1 * front_amount, end_amount);
        front_amount += settle_amount;
        end_amount -= settle_amount;

        cout << "Person " << front_person << " pays " << settle_amount << " amount to person " << end_person << endl;

        if (front_amount)
        {
            s.insert(make_pair(front_amount, front_person));
        }
        if (end_amount)
        {
            s.insert(make_pair(end_amount, end_person));
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}