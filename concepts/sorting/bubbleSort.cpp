#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void output(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<long long> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int32_t main()
{
    vector<int> arr = {116, 364, 456, 98, 290, 1000, 50};
    output(arr);
    bubbleSort(arr);
    output(arr);

    return 0;
}