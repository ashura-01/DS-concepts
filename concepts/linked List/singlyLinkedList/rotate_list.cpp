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

    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void rotate()
{
    node *curr = root;
    node *prev = nullptr;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    node *head = prev->next;
    head->next = root;
    root = head;
    prev->next = nullptr;
}

void listLen()
{
    node *curr = root;
    int count = 0;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    cout << count << endl;
}

void rotating(int times)
{
    while (times--)
    {
        rotate();
    }
}

void rotate2()
{
    node *head = root;
    node *curr = root;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    root = root->next;
    curr->next = head;
    head->next = nullptr;
}
void rotating2(int times)
{
    while (times--)   
    {
        rotate2();
    }
}
int main()
{
    insertFirst(70);
    insertFirst(60);
    insertFirst(50);
    insertFirst(40);
    insertFirst(30);
    insertFirst(20);
    insertFirst(10);

    printing();
    rotating2(3);
    printing();
    listLen();
    return 0;
}