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

void insertFirst(int value)
{
    node *temp = new node(value);
    temp->next = root;
    root = temp;
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

void selectionSort()
{
    for (node *i = root; i != nullptr; i = i->next)
    {
        node *minm = i;

        for (node *j = i->next; j != nullptr; j = j->next)
        {
            if (j->data < minm->data)
            {
                minm = j;
            }
        }

        swap(i->data, minm->data);
    }
}

void insertionSort()
{
    if (!root || !root->next)
        return;

    node* sorted = new node(0);

    node* current = root;

    while (current != nullptr)
    {
        node* next = current->next;

        node* temp = sorted;

        while (temp->next != nullptr && temp->next->data < current->data)
        {
            temp = temp->next;
        }

        current->next = temp->next;
        temp->next = current;

        current = next;
    }

    root = sorted->next;
    delete sorted;
}

void insertionSortData()
{
    for (node *i = root; i != nullptr; i = i->next)
    {
        int key = i->data;
        node *j = root;

        // Find the node just before i where data > key (to shift right)
        // We'll move data in nodes forward until we find correct position for key

        while (j != i)
        {
            if (j->data > key)
            {
                // swap data
                swap(j->data, key);
            }
            j = j->next;
        }

        i->data = key; // place key in correct node
    }
}


int main()
{
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(99);
    insertFirst(40);
    insertFirst(50);
    insertFirst(60);

    printing();
    insertionSortData();
    printing();

    return 0;
}
