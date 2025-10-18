#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

node *root = nullptr;
node *tail = nullptr;

void insertFirst(int value)
{
    node *temp = new node(value);
    if (root != nullptr && tail != nullptr)
    {
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    else if (root == nullptr && tail == nullptr)
    {
        root = temp;
        tail = temp;
    }
}

void insertLast(int value)
{
    node *temp = new node(value);
    if (root != nullptr && tail != nullptr)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else if (root == nullptr && tail == nullptr)
    {
        root = temp;
        tail = temp;
    }
}

void insertByValueAfter(int target, int value)
{
    if (root == nullptr)
        return;
    node *temp = new node(value);
    node *curr = root;
    while (curr)
    {
        if (curr->data == target)
            break;
        curr = curr->next;
    }
    if (curr == nullptr)
        return;
    temp->next = curr->next;
    if (curr->next)
        curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
    if (curr == tail)
        tail = temp;
}

void insertByValueBefore(int target, int value)
{
    if (root == nullptr)
        return;
    if (root->data == target)
    {
        insertFirst(value);
        return;
    }
    node *temp = new node(value);
    node *curr = root;
    while (curr->next)
    {
        if (curr->next->data == target)
            break;
        curr = curr->next;
    }
    if (curr->next == nullptr)
        return;
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}

void insertByPositionAfter(int position, int value)
{
    if (root == nullptr)
        return;
    node *temp = new node(value);
    node *curr = root;
    int count = 0;
    while (curr && count != position)
    {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr)
        return;
    temp->next = curr->next;
    if (curr->next)
        curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
    if (curr == tail)
        tail = temp;
}

void insertByPositionBefore(int position, int value)
{
    if (root == nullptr)
        return;
    if (position == 0)
    {
        insertFirst(value);
        return;
    }
    node *temp = new node(value);
    node *curr = root;
    int count = 0;
    while (curr && count != position - 1)
    {
        curr = curr->next;
        count++;
    }
    if (curr == nullptr || curr->next == nullptr)
        return;
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}

void deleteFirst()
{
    if (root == nullptr)
        return;
    if (root == tail)
    {
        root = tail = nullptr;
        return;
    }
    root = root->next;
    root->prev = nullptr;
}

void deleteLast()
{
    if (tail == nullptr)
        return;
    if (root == tail)
    {
        root = tail = nullptr;
        return;
    }
    tail = tail->prev;
    tail->next = nullptr;
}

void deleteByPosition(int position)
{
    if (root == nullptr)
        return;
    if (root->next == nullptr)
    {
        root = nullptr;
        return;
    }
    node *curr = root;
    for (int i = 0; i < position - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    node *before = curr->prev;
    node *after = curr->next;
    before->next = after;
    after->prev = before;
}

void deleteByValue(int value)
{
    if (root == nullptr)
        return;
    if (root->next == nullptr)
    {
        root = nullptr;
        return;
    }
    node *curr = root;
    while (curr && curr->data != value)
    {
        curr = curr->next;
    }
    if (!curr)
        return;
    node *before = curr->prev;
    node *after = curr->next;
    if (before)
        before->next = after;
    if (after)
        after->prev = before;
    if (curr == root)
        root = after;
    if (curr == tail)
        tail = before;
}

void printingF()
{
    node *curr = root;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printingB()
{
    node *curr = tail;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void searching(int target)
{
    node *curr = tail;
    while (curr)
    {
        if (curr->data == target)
        {
            cout << curr->data << endl;
            return;
        }
        curr = curr->prev;
    }
    cout << "Not found" << endl;
}

void last_node()
{
    if (tail)
        cout << "last node: " << tail->data << endl;
}

void previous_of_last_node()
{
    if (tail && tail->prev)
        cout << "previous of last node: " << tail->prev->data << endl;
}

void list_size()
{
    int count = 0;
    node *curr = root;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    cout << "the list size: " << count << endl;
}

int main()
{

    insertFirst(10);
    insertFirst(5);
    insertLast(20);
    insertLast(25);

    cout << "forward print: ";
    printingF();
    cout << "backward print: ";
    printingB();

    cout << " insert By Position Before 2,15: ";
    insertByPositionBefore(2, 15);
    printingF();
    cout << " insert By Position After 3,18: ";
    insertByPositionAfter(3, 18);
    printingF();

    cout << " insert By Position Before 20,17: ";
    insertByValueBefore(20, 17);
    printingF();
    cout << " insert By Position After 20,22: ";
    insertByValueAfter(20, 22);
    printingF();

    deleteFirst();
    cout << "List after deleteFirst: ";
    printingF();

    deleteLast();
    cout << "List after deleteLast: ";
    printingF();

    deleteByPosition(2);
    cout << "List after delete By Position 2 : ";
    printingF();

    deleteByValue(18);
    cout << "List after delete By Value 18: ";
    printingF();

    cout << "Forward print: ";
    printingF();
    cout << "Backward print: ";
    printingB();

    cout << "Searching for 15: ";
    searching(15);
    cout << "Searching for 100: ";
    searching(100);

    last_node();
    previous_of_last_node();
    list_size();

    return 0;
}