#include <iostream>
#include <set>
using namespace std;

class PersonCompare
{

public:
    bool operator()(pair<char, int> p1, pair<char, int> p2)
    {
        return p1.second < p2.second;
    }
};

int main()
{

    pair<char, int> p1 = make_pair('A', 369);
    pair<char, int> p2 = make_pair('C', 36);
    pair<char, int> p3 = make_pair('E', 3);
    pair<char, int> p4 = make_pair('G', 6);
    pair<char, int> p5 = make_pair('I', 9);

    multiset<pair<char, int>, PersonCompare> m;

    m.insert(p1);
    m.insert(p4);
    m.insert(p3);
    m.insert(p2);
    m.insert(p5);

    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;

    return 0;
}