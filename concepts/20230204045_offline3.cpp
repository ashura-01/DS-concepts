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

void insertByPosition(int position, int value)
{
    if (position < 0)
    {
        cout << "invalid position" << endl;
        return;
    }

    if (position == 0)
    {
        insertFirst(value);
        return;
    }

    node *temp = new node(value);
    node *curr = root;

    for (int i = 0; i < position - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "position out of bound SIR" << endl;
        return;
    }

    temp->next = curr->next;
    curr->next = temp;
}

void insertByValue(int target, int value)
{
    node *temp = new node(value);
    node *curr = root;

    while (curr != nullptr && curr->data != target)
        curr = curr->next;

    if (curr == nullptr)
    {
        cout << "target is not here SIR" << endl;
        return;
    }

    temp->next = curr->next;
    curr->next = temp;
}

void deleteFirst()
{
    if (root != nullptr)
        root = root->next;
}

void deleteLast()
{
    if (root == nullptr)
        return;

    if (root->next == nullptr)
    {
        root = nullptr;
        return;
    }

    node *curr = root;
    while (curr->next->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = nullptr;
}

void deleteByPosition(int position)
{
    if (position < 0)
    {
        cout << "invalid position" << endl;
        return;
    }

    if (position == 0)
    {
        deleteFirst();
        return;
    }

    node *curr = root;

    for (int i = 0; i < position - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }

    if (curr == nullptr || curr->next == nullptr)
    {
        cout << "position out of bound SIR" << endl;
        return;
    }

    curr->next = curr->next->next;
}

void deleteByValue(int target)
{
    if (root == nullptr)
        return;

    if (root->data == target)
    {
        deleteFirst();
        return;
    }

    node *prev = root;
    node *curr = root->next;

    while (curr != nullptr && curr->data != target)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "value not found SIR" << endl;
        return;
    }

    prev->next = curr->next;
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

void searching(int target)
{
    node *curr = root;

    while (curr != nullptr)
    {
        if (curr->data == target)
        {
            cout << "found : " << curr->data << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "Not here" << endl;
}

void last_node()
{
    if (root == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *curr = root;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    cout << "The last elem: " << curr->data << endl;
}
void previous_of_last_node()
{
    if (root == nullptr || root->next == nullptr)
    {
        cout << "No previous node SIR" << endl;
        return;
    }

    node *curr = root;
    node *prev = nullptr;

    while (curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }

    cout << "Previous of last node: " << prev->data << endl;
}

void list_size()
{
    node *curr = root;
    int count = 0;

    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    cout<<"the size of the list is: "<<count<<endl;
}

void reversePrint(node *curr)
{
    if(curr == nullptr)
        return;

    reversePrint(curr->next);
    cout<<curr->data<<" ";
}

int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(99);
    insertLast(40);
    insertLast(50);
    insertLast(60);

    cout << "Initial list: ";
    printing();

    searching(99);

    insertFirst(25);
    cout << "Inserted 25 at first: ";
    printing();

    insertByPosition(4, 35);
    cout << "inserted 35 at position 4: ";
    printing();

    insertByValue(99, 45);
    cout << "inserted 45 by value 99: ";
    printing();

    deleteFirst();
    cout << "deletd first element:  ";
    printing();

    deleteLast();
    cout << "deleted last element: ";
    printing();

    deleteByPosition(4);
    cout << "deleted 4th node: ";
    printing();

    deleteByValue(45);
    cout << "deleted node containing 45: ";
    printing();

    last_node();

    previous_of_last_node();

    list_size();

    cout << "Reverse printing datas: ";
    reversePrint(root);
    cout << endl;

    return 0;
}
