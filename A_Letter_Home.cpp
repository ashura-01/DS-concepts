#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

void solveProblem()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int minPos = *min_element(all(a));
    int maxPos = *max_element(all(a));

    int totalDistance = maxPos - minPos;
    int toNearest = min(abs(s - minPos), abs(s - maxPos));
    cout << totalDistance + toNearest << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}
