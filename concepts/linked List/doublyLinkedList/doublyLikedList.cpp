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

void reverseprint(node *curr)
{
    if (curr == nullptr)
    {
        return;
    }
    reverseprint(curr->next);
    cout << curr->data << " ";
}

void searching(int target)
{
    node *curr = tail;
    while (curr)
    {
        if (curr->data == target)
        {
            cout << curr->data << " ";
            break;
        }
        curr = curr->prev;
    }
}

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

void deleteFirst()
{
    if (root == nullptr)
        return; // nothing to delete

    if (root == tail) // only one node
    {
        delete root;
        root = tail = nullptr;
        return;
    }

    node *temp = root;
    root = root->next;
    root->prev = nullptr;
    delete temp;
}

void deleteLast()
{
    if (tail == nullptr)
        return; // nothing to delete

    if (root == tail) // only one node
    {
        delete tail;
        root = tail = nullptr;
        return;
    }

    node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void insertMid(int value)
{
    if (root == nullptr)
        return; // no mid in empty list

    node *temp = new node(value);
    node *first = root;
    node *slow = root;

    while (first->next != nullptr && first->next->next != nullptr)
    {
        slow = slow->next;
        first = first->next->next;
    }

    node *mid = slow;
    if (mid->next)
        mid->next->prev = temp;
    temp->next = mid->next;
    mid->next = temp;
    temp->prev = mid;

    if (mid == tail)
        tail = temp;
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
        return; // target not found

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

    if (root->data == target) // before first node
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
        return; // target not found

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
        return; // invalid position

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

    if (position == 0) // before first node
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
        return; // invalid position

    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}

void deleteMid()
{
    if (root == nullptr || root == tail)
        return; // empty or single node

    node *first = root;
    node *slow = root;

    while (first->next != nullptr && first->next->next != nullptr)
    {
        slow = slow->next;
        first = first->next->next;
    }

    if (slow == root) // if mid is first
    {
        deleteFirst();
        return;
    }
    if (slow == tail) // if mid is last
    {
        deleteLast();
        return;
    }

    node *before = slow->prev;
    node *after = slow->next;

    before->next = after;
    after->prev = before;
    delete slow;
}

void deleteByPositionBEfore(int position)
{
    if (root == nullptr)
        return;
    if (root->next == nullptr)
        root = nullptr;
    return;
    node *curr = root;
    for (int i = 0; i < position - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    node *before = curr->prev;
    node *after = curr->next;

    before->next=after;
    after->prev = before;
}
void searching(int target)
{
    node *curr= tail;
    while(curr)
    {
        if(curr->data==target)
        {
            cout<<curr->data<<" ";
            break;
        }
        curr=curr->prev;
    }
}

void deleteByPosition(int position)
{
    if (root == nullptr)
        return;
    if (root->next == nullptr)
        root = nullptr;
    return;
    node *curr = root;
    for (int i = 0; i < position - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    node *before = curr->prev;
    node *after = curr->next;

    before->next=after;
    after->prev = before;
}

void deleteByValue(int value)
{
    if (root == nullptr)
        return;
    if (root->next == nullptr)
        root = nullptr;
    return;
    node *curr = root;
    for (int i = 0; i !=value && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    node *before = curr->prev;
    node *after = curr->next;

    before->next=after;
    after->prev = before;
}

void lastNode()
{
    cout<<"last node: "<<tail->data<<endl;
}

void previous_of_last_node()
{
    cout<<"previous of last node"<<tail->prev->data<<endl;
}

void list_size()
{
    int count =0;
    node* curr=root;
    while(curr)
    {
        count++;
        curr=curr->next;
    }
    cout<<"the list size: "<<count<<endl;
}

int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(50);
    insertLast(60);

    printingF();
    insertByPositionBefore(2, 25);
    printingF();

    return 0;
}
