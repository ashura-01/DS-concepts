/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */
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
    typedef ListNode node;

public:
    int listLength(node *root)
    {
        int count = 0;
        node *curr = root;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode *swapNodes(ListNode *root, int k)
    {
        int n = listLength(root); 

        node* first = root;
        for (int i = 1; i < k; i++) { 
            first = first->next;
        }

        node* second = root;
        for (int i = 1; i <= n - k; i++) { 
            second = second->next;
        }

        swap(first->val, second->val);
        return root;
    }
};
// @lc code=end
