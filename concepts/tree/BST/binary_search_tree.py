from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.left: Optional[node] = None
        self.right: Optional[node] = None


root: Optional[node] = None


def preOrder(temp: Optional[node]):
    if temp is None:
        return
    print(temp.data, end=" ")
    preOrder(temp.left)
    preOrder(temp.right)


def inOrder(temp: Optional[node]):
    if temp is None:
        return
    inOrder(temp.left)
    print(temp.data, end=" ")
    inOrder(temp.right)


def postOder(temp: Optional[node]):
    if temp is None:
        return
    print(temp.data, end=" ")
    postOder(temp.left)
    postOder(temp.right)


def insert(data: int):

    global root

    temp = node(data)
    if root is None:
        root = temp
    else:

        curr = root
        prev = root

        while curr is not None:
            prev = curr

            if curr.data > data:
                curr = curr.left
            else:
                curr = curr.right
        if prev.data > data:
            prev.left = temp
        else:
            prev.right = temp


def search(target: int):

    global root
    if root in None:
        print("dead tree")
        return
    curr = root
    while curr is not None:
        if curr.data == target:
            print(f"target found: {curr.data}")
            return curr
        elif curr.data > target:
            curr = curr.left
        else:
            curr = curr.right
    print("not found")


def delete(target: int):
    global root

    if root is None:
        return

    curr = root
    prev = None

    while curr is not None:
        if curr.data == target:
            break
        prev = curr

        if target < curr.data:
            curr = curr.left
        else:
            curr = curr.right

    if curr is None:
        return

    # case 1 where the node is a leaf
    if curr.left is None and curr.right is None:

        if prev is None:
            root = None
        elif prev.left == curr:
            prev.left = None
        else:
            prev.right = None

    # case 2: where thw node has one child
    elif curr.left is None or curr.right is None:

        child = curr.left if curr.left is not None else curr.right

        if prev is None:
            root=child
            return
        elif prev.left == curr:
            prev.left = child
        else:
            prev.right = child

    # case 3: where the node has two children
    else:
        temp = curr
        prev = curr
        succ = curr.right

        while succ.left is not None:
            prev = succ
            succ = succ.left
        temp.data = succ.data

        if prev.left == succ:
            prev.left = succ.right
        else:
            prev.right = succ.right


if __name__ == "__main__":
    
    arr = [12,6,9,18,4,10,5,16,49,31,43]

    for elem in arr:
        insert(elem)
    
    inOrder(root)
    print()
    delete(6)
    print("after deleting 6: ")
    inOrder(root)