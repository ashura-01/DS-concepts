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

void rightRotate(vector<int> &arr, int rotation)
{
    int len = arr.size() - 1;

    while (rotation--)
    {
        int last = arr[len];
        for (int i = len; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
}

void leftRotate(vector<int> &arr, int rotation)
{
    int len = arr.size() - 1;

    while (rotation--)
    {
        int first = arr[0];
        for (int i = 0; i < len; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[len] = first;
    }
}

void frequency(vector<int> &arr)
{
    int len = arr.size();
    vector<bool> visited(len, false);

    for (int i = 0; i < len; i++)
    {
        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = true;
            }
        }

        cout << arr[i] << " appears: " << count << " times" << endl;
    }
}

void duplicateDelete(vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len;)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < len; k++)
                {
                    arr[k] = arr[k + 1];
                }

                len--;
            }
            else
            {
                j++;
            }
        }
    }
    arr.resize(len);
}

void bubbleSort(vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len - 1; i++)
    {
        bool isSorted = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = true;
            }
        }
        if (!isSorted)
            break;
    }
}

void inversebubbleSort(vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len - 1; i++)
    {
        bool isSorted = false;
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = true;
            }
        }
        if (!isSorted)
            break;
    }
}

void evenOddBubbleSort(vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len - 1; i++)
    {
        bool isSorted = false;
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] % 2 != 0 && arr[j + 1] % 2 == 0)
            {
                swap(arr[j], arr[j + 1]);
                isSorted = true;
            }
        }
        if (!isSorted)
            break;
    }
}

void accendingDecendingBubbleSort(vector<int> &arr)
{
    int len = arr.size();
    int mid = len / 2;

    // First half: Ascending
    for (int i = 0; i < mid - 1; i++)
    {
        bool sorted = false;
        for (int j = 0; j < mid - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = true;
            }
        }
        if (!sorted)
            break;
    }

    // Second half: Descending
    for (int i = 0; i < len - mid - 1; i++)
    {
        bool sorted = false;
        for (int j = mid; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = true;
            }
        }
        if (!sorted)
            break;
    }
}
void output(vector<int> &arr)
{
    for (auto elem : arr)
        cout << elem << " ";
    cout << endl;
}

int32_t main()
{

    int n;
    cout << "enter the size of Array and elements: ";
    // cin >> n;
    vector<int> arr = {1,3,2,5,6,8,10,9,7,4};
    // for (auto elem : arr)
    //     cin >> elem;

    int rotation = 2;
    string direction;
    cout << "enter the size of rotation & direction : ";

    // cin >> rotation >> direction;

    // leftRotate(arr, rotation);

    frequency(arr);
    accendingDecendingBubbleSort(arr);

    // duplicateDelete(arr);
    output(arr);

    return 0;
}