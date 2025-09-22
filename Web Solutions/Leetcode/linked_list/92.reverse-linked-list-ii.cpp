/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
class Solution
{
    typedef ListNode node;

public:
    // insert at end
    void insert(node *&root, int val)
    {
        node *temp = new node(val);
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

    // reverse a list recursively into rev
    void reverse(node *root, node *&rev)
    {
        if (!root)
            return;
        reverse(root->next, rev);
        insert(rev, root->val);
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        node *curr = head;
        node *prev = nullptr;

        for (int i = 1; i < left; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        node *start = curr;
        node *end = curr;
        for (int i = left; i < right; i++)
        {
            end = end->next;
        }

        node *nextPortion = end->next;

        // 2. detach sublist
        end->next = nullptr;

        // 3. reverse sublist into rev
        node *rev = nullptr;
        reverse(start, rev);

        // 4. reconnect reversed sublist
        if (prev)
        {
            prev->next = rev;
        }
        else
        {
            head = rev;
        }

        node *tail_rev = rev;
        while (tail_rev->next)
        {
            tail_rev = tail_rev->next;
        }
        tail_rev->next = nextPortion;

        return head;
    }
};

// @lc code=end
