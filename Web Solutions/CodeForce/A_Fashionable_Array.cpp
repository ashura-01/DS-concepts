#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem()
{
    int len;
    cin >> len;

    vector<int> arr(len);
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    if ((arr.front() + arr.back()) % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> oop;

    int count = 0;
    int lindex = len - 1;
    while (lindex >= 0 && (arr.front() + arr[lindex]) % 2 != 0)
    {
        count++;
        lindex--;
    }
    if (lindex >= 0)
        oop.push_back(count);

    int fcount = 0;
    int findex = 0;
    while (findex < len && (arr[findex] + arr.back()) % 2 != 0)
    {
        fcount++;
        findex++;
    }
    if (findex < len)
        oop.push_back(fcount);

    cout << *min_element(oop.begin(), oop.end()) << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}
