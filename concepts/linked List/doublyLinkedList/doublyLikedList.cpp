#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

class Node
{
public:
    int value;
    Node *previous;
    Node *next;

    Node(int value)
    {
        this->value = value;
        previous = NULL;
        next = NULL;
    }
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void printValues()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << " " << temp->value << " <->";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }

    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        return;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        Node *temp;

        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        return;
    }

    void insertAtPosition(int value)
    {
        
    }
};

int32_t main()
{
    DoublyLinkedList dlst;
    dlst.insertAtStart(1);
    dlst.insertAtStart(2);
    dlst.insertAtStart(3);

    dlst.insertAtEnd(99);

    dlst.printValues();

    return 0;
}