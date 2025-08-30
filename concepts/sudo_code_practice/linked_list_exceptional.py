from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.next: Optional["node"] = None


root = None

def insertFirst(value):
    global root
    temp=node(value)
    temp.next=root
    root=temp

def printing():
    global root
    curr = root
    while curr is not None:
        print(curr.data,end=" ")
        curr=curr.next
    print()

def rotate():
    global root
    prev = None
    curr = root

    while curr.next is not None:
        prev = curr
        curr = curr.next

    head = prev.next
    head.next = root
    root = head
    prev.next = None


def rotating(times):
    global root
    while times:
        rotate()
        times-=1

def rotate2():
    global root
    holder = root.next
    head=root
    curr = root
    while curr.next is not None:
        curr=curr.next
        
    curr.next = head
    head.next = None
    root = holder

def rotating2(times):
    global root
    while times:
        rotate2()
        times-=1




if __name__ == "__main__":
    insertFirst(70)
    insertFirst(60)
    insertFirst(50)
    insertFirst(40)
    insertFirst(30)
    insertFirst(20)
    insertFirst(10)

    printing()
    rotating2(2)
    printing()
