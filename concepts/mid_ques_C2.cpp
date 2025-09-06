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

void insertLast(int value)
{
    node *temp = new node(value);
    if (root == nullptr)
    {
        root = temp;
        return;
    }

    node *curr = root;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;
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

void rotate()
{
    node *prev = nullptr;
    node *curr = root;

    while(curr->next)
    {
        prev = curr;
        curr= curr->next;
    }

    node *head = prev->next;
    head->next=root;
    root=head;
    prev->next=nullptr;
}
void rotateB()
{
    node *curr = root;
    node *prev = nullptr;
    while(curr->next)
    {
        prev = curr;
        curr= curr->next;
    }
    node *tail = root;
    root=root->next;
    curr->next=tail;
    tail->next=nullptr;
}
int listLen()
{
    int count=0;
    node* curr = root;
    while (curr)
    {
        count++;
        curr=curr->next;
    }
    return count;
}

int main()
{
    input();
    printing();
    int k;
    cin>>k;
    int n = listLen();
    int times = abs(n-k);
    cout<<times<<endl;

    while(times--)
    {
        rotateB();
    }
    printing();

    return 0;
}