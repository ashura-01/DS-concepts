from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.left: Optional[node] = None
        self.right: Optional[node] = None


root: Optional[node] = None


def inorderprint(curr: Optional[node]):
    if curr is None:
        return
    inorderprint(curr.left)
    print(curr.data, end=" ")
    inorderprint(curr.right)

def insert(curr: Optional[node], value: int):
    if not curr:
        return node(value)
    if value < curr.data:
        curr.left = insert(curr.left, value)
    else:
        curr.right = insert(curr.right, value)
    return curr


if __name__ =="__main__":

    arr = [1,5,6,2,3,4,7,9,8,99]

    for elem in arr:
        root = insert(root,elem)

    inorderprint(root)

