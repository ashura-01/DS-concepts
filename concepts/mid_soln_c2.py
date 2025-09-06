from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.next: Optional["node"] = None


root = None

def insertFirst(data):
    temp=node(data)
    temp.next=root
    root=temp
    
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


if __name__=="__main__":
    while True:
        data = int(input("data input: "))
        temp = node(data)