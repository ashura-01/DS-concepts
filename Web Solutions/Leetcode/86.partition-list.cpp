/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    void insert(node *&root, int data)
    {
        node *temp = new node(data);
        if (!root)
        {
            root = temp;
            return;
        }
        node *curr = root;
        while (curr->next)
            curr = curr->next;
        curr->next = temp;
    }

    ListNode *partition(ListNode *head, int x)
    {
        node *small = nullptr;
        node *big = nullptr;

        node *curr = head;
        while (curr)
        {
            if (curr->val < x)
                insert(small, curr->val);
            else
                insert(big, curr->val);
            curr = curr->next;
        }

        if (!small)
            return big; 
        if (!big)
            return small;

        node *temp = small;
        while (temp->next)
            temp = temp->next;
        temp->next = big;

        return small;
    }
};

// @lc code=end
