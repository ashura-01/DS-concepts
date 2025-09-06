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

void reverseSegment(node *start, int k)
{
    node *prev = nullptr;
    node *curr = start;
    node *next = nullptr;

    node *before = root;
    while (before->next != start)
        before = before->next;

    int count = k;
    while (count--)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    before->next = prev;
    start->next = curr;
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
    int n = listLen();
    printing();
    int i = 0;
    node *curr = root;
    while(i<n)
    {
        if(n%3 == 0)
        {
            reverseSegment(curr,3);
        }

        curr = curr->next;
    }
        printing();

    return 0;
}