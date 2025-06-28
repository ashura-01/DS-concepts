#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void bruteForce()
{
    // Your problem-solving code here
    int x, m;
    cin >> x >> m;
    set<int> sett;
    sett.insert(0);
    sett.insert(x);

    while (m--)
    {
        int elem;
        cin >> elem;

        sett.insert(elem);
        int maxm = 0;

        for (auto i = sett.begin(); i != sett.end(); i++)
        {
            int diff = *std::next(i) - *i;

            maxm = (diff > maxm) ? diff : maxm;
        }
        cout << maxm << " ";
    }
    cout << endl;
}

void solveProblem()
{
    int x, m;
    cin >> x >> m;
    set<int> sett = {0, x};
    multiset<int> segment = {x};

    while (m--)
    {
        int elem;
        cin >> elem;

        auto right = sett.upper_bound(elem);
        auto left = prev(right);

        segment.erase(segment.find(*right - *left));

        segment.insert(elem - *left);
        segment.insert(*right - elem);

        sett.insert(elem);

        cout << *segment.rbegin() << " ";
    }

    cout << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}