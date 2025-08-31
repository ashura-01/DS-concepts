/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start

//  Definition for singly-linked list.
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
    void deleteByValue(node *&root, int target)  // pass root by reference
    {
        node *curr = root;
        node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->val == target)
            {
                if (prev == nullptr)  
                {
                    root = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                return; 
            }
            prev = curr;
            curr = curr->next;
        }
    }

    ListNode* removeElements(ListNode *root, int target)
    {
        node *curr = root;
        while (curr != nullptr)
        {
            deleteByValue(root, target);  
            curr = root;  
            bool found = false;
            node *tmp = root;
            while(tmp) {
                if(tmp->val == target) { found = true; break; }
                tmp = tmp->next;
            }
            if(!found) break;
        }
        return root;
    }
};

// @lc code=end
