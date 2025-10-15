from typing import Optional

class Node:
    def __init__(self, data):
        self.next: Optional["Node"] = None
        self.prev: Optional["Node"] = None
        self.data = data


root: Optional[Node] = None
tail: Optional[Node] = None


def insert(value: int):
    global root, tail
    temp = Node(value)

    if root is not None and tail is not None:
        temp.next = root
        root.prev = temp
        root = temp
    elif root is None and tail is None:
        root = temp
        tail = temp
    return temp


def cycle_detect() -> Optional[Node]:
    """Return meeting point node if cycle exists, else None."""
    global root
    slow = root
    fast = root

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return slow  # meeting point inside loop
    return None


def firstNodeOfLoop() -> Optional[Node]:
    meetingPoint = cycle_detect()
    if meetingPoint is None:
        return None  # No loop

    start = root
    while start != meetingPoint:
        start = start.next
        meetingPoint = meetingPoint.next

    return start  # first node of the loop


if __name__ == "__main__":
    temp2 = insert(50)
    insert(60)
    insert(70)
    temp = insert(80)
    insert(90)
    insert(10)
    insert(20)
    insert(30)

    temp2.next = temp

    nodeStart = firstNodeOfLoop()
    if nodeStart:
        print("Loop detected. First node of loop =", nodeStart.data)
    else:
        print("No loop detected.")
