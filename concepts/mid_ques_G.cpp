#include <bits/stdc++.h>
using namespace std;
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

void selectionSort(vector<int> &arr)
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

int max(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    int n = 4;
    int fund = 1000;
    vector<int> arr = {500, 200, 300, 400};
    selectionSort(arr);


    int count = 0;

    int i=0;
    while(fund>=arr[i] && i<n)
    {
        fund-=arr[i];
        count++;
        i++;
    }
    cout<<count<<endl;
    return 0;
}