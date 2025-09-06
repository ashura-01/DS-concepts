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

void sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
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
void solveProblem()
{
    int n = 3;
    vector<int> arr = {5, 1, 9};
    vector<int> trr = {10, 2, 6};
    sort(arr);
    sort(trr);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += abs(arr[i] - trr[i]);
    }
    cout << sum << endl;
}

int32_t main()
{

    solveProblem();

    return 0;
}