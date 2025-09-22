/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

//   Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseList(ListNode *root)
    {

        ListNode *prev = nullptr;
        ListNode *curr = root;
        ListNode *after = nullptr;

        while (curr!= nullptr)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }

        return prev;
    }
};
// @lc code=end
