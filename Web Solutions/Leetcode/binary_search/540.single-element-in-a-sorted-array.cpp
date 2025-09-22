/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */
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

// @lc code=start
class Solution
{
public:
    int binsingle(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (mid % 2 == 0) // even
            {
                if (arr[mid + 1] == arr[mid])
                {
                    low = mid + 2;
                }
                else
                {
                    high = mid;
                }
            }

            else
            {
                if (arr[mid - 1] == arr[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
        }
        return arr[low];
    }
    int singleNonDuplicate(vector<int> &nums)
    {
        return binsingle(nums);
    }
};
// @lc code=end
