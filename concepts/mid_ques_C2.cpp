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

void insertLast(node *&head, int value)
{
    node *temp = new node(value);
    if (head == nullptr)
    {
        head = temp;
        return;
    }

    node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;
}
void printing(node* head)
{
    node *curr = head;

    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}



int main()
{
    node *odd=nullptr;
    node *even=nullptr;
    while(1)
    {
        int data;
        cin>>data;

        if(data ==-1)
        {
            break;
        }
        if(data%2 == 0)
        {
            insertLast(even,data);
        }
        else
        {
            insertLast(odd,data);
        }
        
    }
    node *curr=even;

    while(curr->next)
    {
        curr = curr->next;
    }

    curr->next = odd;
    printing(even);


    return 0;
}