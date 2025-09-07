from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.next: Optional["node"] = None


top = None

"""insertFirst ----> push"""


def push(data):
    global top
    temp = node(data)
    temp.next = top
    top = temp


"""deleteFirst ----> pop"""


def pop():
    global top
    if top is None:
        print("stck underflow")
        return
    top = top.next


"""first element ----> peek"""


def peek():
    global top
    if top is None:
        print("empty stack")
        return -1
    return top.data


def display():
    global top
    curr = top
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
