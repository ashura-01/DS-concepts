#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

node *root = nullptr;

void preorder(node *temp)
{
    if(temp== nullptr) return;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(node *temp)
{
    if(temp== nullptr) return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

void postorder(node *temp)
{
    if(temp== nullptr) return;
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}

void insert(int data)
{
    node *temp= new node(data);

    if(root==nullptr)
    {
        root=temp;
    }
    else
    {
        node *curr = root;
        node *prev = nullptr;

        while(curr != nullptr)
        {
            prev=curr;
            if(curr->data > data) curr=curr->left;
            else curr=curr->right;
        }

        if(prev->data > data) prev->left = temp;
        else prev->right = temp;
    }
}

void search(int target)
{
    if(root==nullptr)
    {
        cout<<"dead tree"<<endl;
        return;
    }

    node *curr = root;

    while(curr)
    {
        if(curr->data == target)
        {
            cout<<"found: "<<curr->data<<endl;
            return;
        }
        else if(curr->data > target) curr=curr->left;
        else curr=curr->right;
    }

    cout<<"not found"<<endl;
}
void BST_delete(int val)
{
    if (root == nullptr) 
    {
        return;
    }

    node *curr_node = root;
    node *prev_node = nullptr;

    while (curr_node != nullptr)
    {
        if (curr_node->data == val) 
        {
            break;
        }
        prev_node = curr_node;
        if (curr_node->data > val) 
        {
            curr_node = curr_node->left;
        }
        else 
        {
            curr_node = curr_node->right;
        }
    }

    if (curr_node == nullptr) 
    {
        return;
    }

    if (curr_node->left == nullptr && curr_node->right == nullptr) 
    {
        if (prev_node == nullptr) 
        {
            root = nullptr;
        }
        else if (prev_node->left == curr_node) 
        {
            prev_node->left = nullptr;
        }
        else 
        {
            prev_node->right = nullptr;
        }

    }
    else if (curr_node->left == nullptr || curr_node->right == nullptr) 
    {
        node *child = (curr_node->left != nullptr) ? curr_node->left : curr_node->right;

        if (prev_node == nullptr) 
        {
            root = child;
        }
        else if (prev_node->left == curr_node) 
        {
            prev_node->left = child;
        }
        else 
        {
            prev_node->right = child;
        }
    }
    else 
    {
        node *temp = curr_node;
        prev_node = curr_node;
        node *succ = curr_node->right;
        while (succ->left != nullptr) 
        {
            prev_node = succ;
            succ = succ->left;
        }
        temp->data = succ->data;
        if (prev_node->left == succ) 
        {
            prev_node->left = succ->right;
        }
        else 
        {
            prev_node->right = succ->right;
        }
    }
}

int main()
{
    // int n;
    // cout<<"how many data want to insert: ";
    // cin>>n;

    // while(n--)
    // {
    //     int data;
    //     cout<<"input data: ";
    //     cin>>data;
    //     insert(data);
    // }

    vector<int> demo = {3, 1, 4, 5, 2};
    for(int val : demo) insert(val);

    cout<<"pre: ";
    preorder(root);
    cout<<endl;

    cout<<"in: ";
    inorder(root);
    cout<<endl;

    cout<<"post: ";
    postorder(root);
    cout<<endl;

    search(5);

    return 0;
}
