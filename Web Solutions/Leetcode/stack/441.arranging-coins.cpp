/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
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
    int bruteforce(int n)
    {
        int k = 0;
        while (n > 0)
        {
            k++;
            n -= k;
        }
        if (n == 0)
            return k;
        else
            return k - 1;
    }
    long long binaryforce(int n)
    {
        int low = 0, high = n;
        while (low <= high)
        {
            long long mid = (low + high) / 2;

            long long flag = 1LL *mid * (mid + 1) / 2;

            if (flag == n)
                return mid;
            else if (flag < n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
    int arrangeCoins(int n)
    {
        return binaryforce(n);
    }
};
// @lc code=end
