from typing import Optional


class Node:
    def __init__(self, data):
        self.data = data
        self.next: Optional["Node"] = None


head = None


def push(data):
    global head
    temp = Node(data)
    if head is None:
        head = temp
        return
    curr = head
    while curr.next is not None:
        curr = curr.next
    curr.next = temp


def pop():
    global head
    if head is None:
        
        print("queue underflow")
        return

    head = head.next


def display():
    global head
    if head is None:
        print("queue empty")
        return
    curr = head
    while curr is not None:
        print(curr.data, end=" ")
        curr = curr.next
    print()


if __name__ == "__main__":
    push(10)
    push(20)
    push(30)
    push(40)
    push(50)

    display()
    pop()
    display()
