from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.next: Optional["node"] = None
        self.prev: Optional["node"] = None


root = None
tail = None


def printingForward():
    global root
    curr = root
    while curr is not None:
        print(curr.data, end=" ")
        curr = curr.next
    print()


def printBackward():
    global tail
    curr = tail
    while curr is not None:
        print(curr.data, end=" ")
        curr = curr.prev
    print()


def insertFirst(data):
    global root, tail
    temp = node(data)

    if root is not None and tail is not None:
        temp.next = root
        root.prev = temp
        root = temp
    elif root is None and tail is None:
        root = temp
        tail = temp


def insertLast(data):
    global root, tail
    temp = node(data)

    if root is not None and tail is not None:
        temp.prev = tail
        tail.next = temp
        tail = temp
    elif root is None and tail is None:
        root = temp
        tail = temp

def deleteFirst():
    global root, tail
    if root is None :
        return
    if root == tail:
        root=tail=None
        return
    
    root = root.next
    root.prev = None

def deleteLast():
    global root, tail

    if tail is None:
        return
    if tail == root:
        root=tail=None
        return
    
    tail = tail.prev
    tail.next = None

def insertAfterTargetValue(target, data):

    global root,tail
    if root is None:
        return
    temp = node(data)

    curr = root

    while curr is not None:
        if curr.data == target:
            break
        curr = curr.next

    if curr is None:
        print("target not found...")
        return
    
    temp.next = curr.next
    if curr.next is not None:
        curr.next.prev = temp
    curr.next = temp
    temp.prev = curr

def insertBeforeTargetValue(target, data):
    global root,tail

    if root is  None:
        return
    
    temp = node(data)
    curr = root

    while curr is not None:
        if curr.next.data == target:
            break
        curr = curr.next

    if curr.next is None:
        return
    
    temp.next = curr.next
    curr.next.prev = temp
    curr.next =temp
    temp.prev=curr

def insertBeforePosition(position , data):
    if root is None:
        return
    if position == 0:
        insertFirst(data)
        return
    
    temp = node(data)
    curr = root
    count = 0

    while curr is not None and count != position:
        curr = curr.next
        count+=1

    if curr is None or curr.next is None:
        return
    
    temp.next = curr.next
    curr.next.prev = temp
    curr.next=temp
    temp.prev = curr

    
    
    



if __name__ == "__main__":
    insertFirst(10)
    insertFirst(20)
    insertFirst(30)
    insertFirst(40)
    insertFirst(50)
    insertFirst(60)

    printingForward()
