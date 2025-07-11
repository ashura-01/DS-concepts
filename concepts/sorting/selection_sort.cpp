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
void print(const vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << i << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << " ";
    cout << "\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << arr[i] << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";
}

void seclectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int mindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mindex])
            {
                mindex = j;
            }
        }

        swap(arr[i], arr[mindex]);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    print(arr);

    seclectionSort(arr);

    print(arr);

    return 0;
}