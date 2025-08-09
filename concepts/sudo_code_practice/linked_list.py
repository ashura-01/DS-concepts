from template import *


class node:
    def __init__(self, data):
        self.data = data
        self.next = None


root = None


def insertFirst(value):
    global root
    temp = node(value)
    temp.next = root
    root = temp


def insertlast(value):
    global root
    temp = node(value)

    if root == None:
        root = temp
        return

    curr = root
    prev = None

    while curr is not None:
        prev = curr
        curr = curr.next

    prev.next = temp


def insertByPositionBefore(position,value):
    global root

    if position < 0:
        print("invalid position")
        return

    if position == 0:
        insertFirst(value)
        return
    temp = node(value)
    curr=root

    i = 0

    while i<position-1 and curr != None:
        curr= curr.next
        i+=1
    
    if curr is None:
        print("size out of bound")
        return

    temp.next = curr.next
    curr.next = temp

def insertByPositionAfter(position, value):
    global root

    if position < 0:
        print("invalid position")
        return
    if position == 0:
        insertFirst(value)
        return
    
    temp = node(value)
    curr = root

    i=0

    while i<position and curr is not None:
        curr=curr.next
        i+=1
    
    if curr is None :
        print("out of bound")
        return
    
    temp.next = curr.next
    curr.next=temp




def printing():
    global root
    curr = root

    while curr != None:
        print(curr.data, end=" ")
        curr = curr.next


if __name__ == "__main__":
    insertFirst(50)
    insertFirst(40)
    insertFirst(30)
    insertFirst(20)
    insertFirst(10)
    insertFirst(0)

    # insertByPositionBefore(3,999)
    insertByPositionAfter(3,999)

    printing()
