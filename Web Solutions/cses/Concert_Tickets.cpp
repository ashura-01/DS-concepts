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

int immediateJuniorIndex(const vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

void solveProblem1()
{
    int n, m;
    cin >> n >> m;

    vector<int> ticketPrice(n);
    for (auto &elem : ticketPrice)
        cin >> elem;
    sort(all(ticketPrice));

    while (m--)
    {
        int x;
        cin >> x;
        int idx = immediateJuniorIndex(ticketPrice, x);
        if (idx == -1)
            cout << -1 << endl;
        else
        {
            cout << ticketPrice[idx] << endl;
            ticketPrice.erase(ticketPrice.begin() + idx);
        }
    }
}

void solveProblem()
{
    int n, m;
    cin >> n >> m;

    multiset<int> ticketPrice;

    while (n--)
    {
        int elem;
        cin >> elem;
        ticketPrice.insert(elem);
    }

    while (m--)
    {
        int customerPrice;
        cin >> customerPrice;

        auto ptr = ticketPrice.upper_bound(customerPrice);

        if (ptr == ticketPrice.begin())
            cout << -1 << endl;
        else{
            --ptr;
            cout<< *ptr << endl;
            ticketPrice.erase(ptr);
        }
    }
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