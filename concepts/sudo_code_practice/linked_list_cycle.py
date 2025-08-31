from typing import Optional

class node:
    def __init__(self,data):
        self.data = data
        self.next: Optional["node"]=None

root = None

def insertFirst(data):
    global root
    temp = node(data)
    temp.next = root   # always point to old root
    root=temp
    return temp

def printing():
    global root
    curr = root
    visited = set()
    while curr is not None:
        if curr in visited:
            print("-> cycle detected while printing")
            return
        visited.add(curr)
        print(curr.data,end=" ")
        curr=curr.next
    print()

def detectCycle():
    global root
    hare = root
    tortoise = root

    while hare is not None and hare.next is not None:
        tortoise = tortoise.next
        hare = hare.next.next

        if tortoise == hare:
            print("cycle here")
            return
    print("no cycle")

if __name__ == "__main__":
    test2=insertFirst(10)
    insertFirst(20)
    test = insertFirst(30)
    insertFirst(40)
    insertFirst(50)

    test2.next = test   # create cycle

    print(test.data)

    detectCycle()
