#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node *&node, int value)
{
    Node *newNode = new Node(value);
    if (node == nullptr)
    {
        node = newNode;
        return;
    }
    Node *temp = node;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node *&head, int position, int value)
{
    if (position == 0)
    {
        insertAtHead(head, value);
        return;
    }

    Node *newNode = new Node(value);

    Node *temp = head;
    int currentPosition = 0;
    while (currentPosition != position - 1)
    {
        temp = temp->next;
        currentPosition++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void updateValueAtPosition(Node *head, int position, int value)
{
    Node *temp = head;
    int currentPos = 0;
    while (currentPos != position)
    {
        temp = temp->next;
        currentPos++;
    }

    temp->value = value;
}

void deleteAtHead(Node *&head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteAtTail(Node *&head)
{
    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        free(head);
        head = nullptr;
        return;
    }

    Node *secondLastNode = head;
    while (secondLastNode->next->next != nullptr)
    {
        secondLastNode = secondLastNode->next;
    }

    Node *lastNode = secondLastNode->next;
    free(lastNode);
    secondLastNode->next = nullptr;
}

void deleteAtPosition(Node *&head, int position, int value)
{
    if (position == 0)
    {
        deleteAtHead(head);
        return;
    }

    int currentPosition = 0;
    Node *previousofTargetNode = head;

    while (currentPosition != position - 1)
    {
        previousofTargetNode = previousofTargetNode->next;
        currentPosition++;
    }
    Node *target = previousofTargetNode->next;
    previousofTargetNode->next = previousofTargetNode->next->next;
    free(target);
}

void printValues(Node *&node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int32_t main()
{
    Node *head = nullptr;

    cout << "Insert at Head:\n";
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    printValues(head); // Expected: 30->20->10->NULL

    cout << "\nInsert at End:\n";
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    printValues(head); // Expected: 30->20->10->40->50->NULL

    cout << "\nInsert at Position (2, value=99):\n";
    insertAtPosition(head, 2, 99);
    printValues(head); // Expected: 30->20->99->10->40->50->NULL

    cout << "\nUpdate Value at Position (3, value=777):\n";
    updateValueAtPosition(head, 3, 777);
    printValues(head); // Expected: 30->20->99->777->40->50->NULL

    cout << "\nDelete at Head:\n";
    deleteAtHead(head);
    printValues(head); // Expected: 20->99->777->40->50->NULL

    cout << "\nDelete at Tail:\n";
    deleteAtTail(head);
    printValues(head); // Expected: 20->99->777->40->NULL

    cout << "\nDelete at Position (1):\n";
    deleteAtPosition(head, 1, 0); // Note: value param not used
    printValues(head);            // Expected: 20->777->40->NULL

    return 0;
}
