from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.next: Optional["node"] = None


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


def insertByPositionBefore(position, value):
    global root

    if position < 0:
        print("invalid position")
        return

    if position == 0:
        insertFirst(value)
        return
    temp = node(value)
    curr = root

    i = 0

    while i < position - 1 and curr != None:
        curr = curr.next
        i += 1

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

    i = 0

    while i < position and curr is not None:
        curr = curr.next
        i += 1

    if curr is None:
        print("out of bound")
        return

    temp.next = curr.next
    curr.next = temp


def insertByValueAfter(target, value):
    global root
    temp = node(value)

    curr = root

    while curr is not None and curr.data != target:
        curr = curr.next

    if curr is None:
        print("not found")
        return

    temp.next = curr.next
    curr.next = temp


def insertByValueBefore(target, value):
    global root
    temp = node(value)

    curr = root

    while curr is not None and curr.next.data != target:
        curr = curr.next

    if curr is None:
        print("not found")
        return

    temp.next = curr.next
    curr.next = temp


def deleteFirst():
    global root
    if root is not None:
        root = root.next


def deleteLast():
    global root

    if root is None:
        return
    if root.next is None:
        root = None
        return

    curr = root

    while curr.next.next is not None:
        curr = curr.next

    curr.next = None


def deleteByPosition(position):
    global root

    if position < 0:
        return
    if position == 0:
        deleteFirst()
        return

    curr = root

    i = 0
    while i != position - 1 and curr is not None:
        curr = curr.next
        i += 1

    if curr == None or curr.next is None:
        print("position out of bound")
        return

    curr.next = curr.next.next


def deleteByValue(target):
    global root

    if root is None:
        print("List is empty")
        return

    if root.data == target:
        root = root.next
        return

    prev = searchValueReturnAddressOfPrev(target)
    if prev is None:
        print("Value not found")
        return

    curr = prev.next
    prev.next = curr.next


def searchValueReturnAddressOfPrev(target):
    global root

    prev = root
    curr = root.next

    while curr is not None:
        if curr.data == target:
            return prev
        prev = curr
        curr = curr.next

    return None


def printing():
    global root
    curr = root

    while curr != None:
        print(curr.data, end=" ")
        curr = curr.next
    print()


# def insertionSort():
#     global root
#     sort= node(0)

#     curr = root

#     while curr is not None:

#         next = curr.next
#         temp = sort

#         while temp.next is not None and temp.next.data < curr.data:
#             temp = temp.next

#         curr.next = temp.next
#         temp.next = curr
#         curr = next

#     root = sort.next


def insertionSort():
    global root
    sort = node(0)
    curr = root

    while curr is not None:
        
        next = curr.next
        temp = sort

        while temp.next is not None and temp.next.data < curr.data:
            temp = temp.next

        curr.next = temp.next
        temp.next = curr
        curr = next

    root = sort.next


def selectionSort():
    global root
    i = root

    while i is not None:
        minm = i

        j = i.next

        while j is not None:

            if j.data < minm.data:
                minm = j
                i = i.next

        i.data, minm.data = minm.data, i.data

        i = i.next


def selectionSort2():
    global root
    for i in root:
        minm = i
        for j in i.next:
            if j.data < minm.data:
                minm = j
        i.data, minm.data = minm.data, i.data


if __name__ == "__main__":
    insertFirst(10)
    insertFirst(20)
    insertFirst(30)
    insertFirst(40)
    insertFirst(50)
    insertFirst(60)

    # insertByPositionBefore(3,999)
    insertByValueBefore(30, 999)
    # deleteByValue(999)
    printing()
    insertionSort()
    printing()
