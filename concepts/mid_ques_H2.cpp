#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *next;
    int data;
    node(int value)
    {
        next = nullptr;
        data = value;
    }
};

node *root = nullptr;

void insertFirst(int value)
{
    node *temp = new node(value);
    temp->next = root;
    root = temp;
}

node *insertLast(int value)
{
    node *temp = new node(value);
    if (root == nullptr)
    {
        root = temp;
        return root;
    }

    node *curr = root;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;

    return curr;
}
void printing()
{
    node *curr = root;

    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void input()
{
    while (1)
    {
        int data;
        cin >> data;

        if (data == -1)
        {
            break;
        }

        insertFirst(data);
    }
}

node* reverseSegment(node *head, int k)
{
    node *prev = nullptr;
    node *curr = head;
    node *next = nullptr;

    int count = k;
    while (count--)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (next!=nullptr)
    {
        head->next = reverseSegment(next,k);
    }

    return prev;

   
}

int listLen()
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

int main()
{
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    insertLast(5);
    insertLast(6);
    int k =2;
    root = reverseSegment(root,k);
    printing();

    return 0;
}