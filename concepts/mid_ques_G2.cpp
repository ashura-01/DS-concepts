#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = nullptr;
    }
};

node *root = nullptr;

void insertLast(int value)
{
    node *temp = new node(value);
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

void printing(node *head)
{
    node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    insertLast(5);
    insertLast(6);
    node *curr = root;

    while (curr)
    {
        curr = curr->next;
    }

    return 0;
}
