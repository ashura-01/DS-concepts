#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *root = nullptr;

// indert code

node *insert(node *temp, int value)
{
    if(!temp)
    {
        return new node(value);
    }

    if(value<temp->data)
    {
        temp->left = insert(temp->left, value);
    }
    else
    {
        temp->right = insert(temp->right, value);
    }
    return temp;
}

node *findmin(node *temp)
{
    while(temp && temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

node *successor(node *target)
{
    if(!target)
    {
        return nullptr;
    }
    if(target->right)
    {
        return findmin(target->right);
    }

    node *succ = nullptr;
    node *curr = root;

    while(curr)
    {
        if(curr->data> target->data)
        {
            succ = curr;
            curr= curr->left;
        }
        else if(curr->data<target->data)
        {
            curr = curr->right;
        }
        else if(curr->data==target->data)
        {
            break;
        }
    }
    return succ;
}

node *findmax(node *temp)
{
    while(temp && temp->right)
    {
        temp=temp->right;
    }
    return temp;
}

node *predecessor(node *target)
{
    if(!target)
    {
        return nullptr;
    }

    if(target->left)
    {
        return findmax(target->left);
    }

    node *pred = nullptr;
    node *curr = root;

    while(curr)
    {
        if(curr->data < target->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else if(curr->data > target->data)
        {
            curr = curr->left;
        }
        else
        {
            break;
        }
    }

    return pred;
}