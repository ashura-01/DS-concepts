from typing import Optional


class node:
    def __init__(self, data):
        self.data = data
        self.left: Optional[node] = None
        self.right: Optional[node] = None


root: Optional[node] = None


def preOrder(temp: node):
    if temp is None:
        return
    print(temp.data, end=" ")
    preOrder(temp.left)
    preOrder(temp.right)


def inorder(temp: node):
    if temp is None:
        return
    inorder(temp.left)
    print(temp.data, end=" ")
    inorder(temp.right)


def postOrder(temp: node):
    if temp is None:
        return
    postOrder(temp.left)
    postOrder(temp.right)
    print(temp.data, end=" ")


def findMin(node: node):
    while node and node.left:
        node = node.left
    return node


"""successor"""


def successor(target: node):
    global root

    if target is None:
        return None
    if target.right is not None:
        return findMin(target.right)

    succ: Optional[node] = None
    curr = root

    while curr is not None:
        if target.data < curr.data:
            succ = curr
            curr = curr.left
        elif target.data > curr.data:
            curr = curr.right
        else:
            break
    return succ


"""predecessor"""


def findMax(node: node):
    while node and node.right:
        node = node.right
    return node


def predecessor(target: node):
    global root

    if target is None:
        return None
    if target.left is not None:
        return findMax(target.left)
    pred: Optional[node] = None
    curr = root

    while curr is not None:
        if target.data > curr.data:
            pred = curr
            curr = curr.right
        elif target.data < curr.data:
            curr = curr.left
        else:
            break
    return pred


"""insert"""


def insert(nodes: node, value):
    if nodes is None:
        return node(value)
    if value < nodes.data:
        nodes.left = insert(nodes.left, value)
    else:
        nodes.right = insert(nodes.right, value)
    return nodes


"""deleting"""


def delete(target: int):
    global root

    """checking validity"""
    if root is None:
        return
    curr = root
    prev: Optional[node] = None

    """searching..."""
    while curr:
        if curr.data == target:
            break
        prev = curr
        if curr.data > target:
            curr = curr.left
        else:
            curr = curr.right

    if curr is None:
        print("target not found...")
        return

    # has no child
    if curr.left is None and curr.right is None:
        if prev is None:
            root = None
        elif prev.left == curr:
            prev.left = None
        else:
            prev.right = None
    elif curr.left is None or curr.right is None:
        child = curr.left if curr.left is not None else curr.right
        if prev is None:
            root = child
        elif prev.left == curr:
            prev.left = child
        else:
            prev.right = child
    else:
        prev = curr

        succ = curr.right

        while succ.left is not None:
            prev = succ
            succ = succ.left
        curr.data = succ.data

        if prev.left == succ:
            prev.left = succ.right
        else:
            prev.right = succ.right


"""searching"""


def search(target: int):
    global root

    curr = root

    while curr is not None:
        if curr.data == target:
            return curr
        elif target < curr.data:
            curr = curr.left
        else:
            curr = curr.right
    return None


""" same bst verification"""


def isSameBst(root1: node, root2: node):
    if root1 is None and root2 is None:
        return True
    if root1 is None or root2 is None:
        return False
    return (
        (root1.data == root2.data)
        and isSameBst(root1.left, root2.left)
        and isSameBst(root1.right, root2.right)
    )


""" Kth smallest element """


def inorder(curr: node, k: list, stack: list):
    if curr is None or k[0] == 0:
        return

    inorder(curr.left, k, stack)

    k[0] -= 1
    if k[0] == 0:
        stack.append(curr.data)
        return

    inorder(curr.right, k, stack)


def kthSmallest(root: node, k: int) -> int:
    stack = []
    inorder(root, [k], stack)
    return stack[-1] if stack else None


"""main function"""
if __name__ == "__main__":

    arr = [12, 6, 9, 18, 4, 10, 5, 16, 49, 31, 43]

    for values in arr:
        root = insert(root, values)
    inorder(root)

    print()
    data = successor(search(5))
    print("successor of 5 is: ", data.data)
