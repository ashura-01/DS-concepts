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
        cout << "     ";
    cout << "\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << arr[i] << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int sizeLeft = mid - low + 1;
    int sizeRight = high - mid;

    vector<int> arrleft, arrright;

    for (int i = 0; i < sizeLeft; i++)
        arrleft.pb(arr[low + i]);
    for (int i = 0; i < sizeRight; i++)
        arrright.pb(arr[mid + 1 + i]);

    arrleft.pb(INF);
    arrright.pb(INF);

    int i = 0, j = 0;
    for (int k = low; k <= high; k++)
    {
        if ((arrleft[i] % 2 == 0 && arrright[j] % 2 != 0) || (arrleft[i] % 2 == arrright[j] % 2 && arrleft[i] <= arrright[j]))
        {
            arr[k] = arrleft[i++];
        }
        else
        {
            arr[k] = arrright[j++];
        }
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {19, 18, 16, 17, 9, 9, 7, 8, 0, 1, 2, 3, 15, 14, 12, 11, 10, 9};

    print(arr);
    mergeSort(arr, 0, arr.size() - 1);
    print(arr);

    return 0;
}
