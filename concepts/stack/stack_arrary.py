from typing import Final

size: Final = 50
stack = [None] * size
top = -1

def push(data):
    global top
    if top == size - 1:
        print("stack overflow")
        return
    top += 1
    stack[top] = data

def pop():
    global top
    if top == -1:
        print("stack underflow")
        return None
    value = stack[top]
    stack[top] = None
    top -= 1
    return value

def display():
    if top == -1:
        print("empty...")
        return
    for i in range(0, top + 1):
        print(stack[i], end=" ")
    print()


if __name__=="__main__":
    push(5)
    push(6)
    push(7)
    push(8)
    display()
    print(stack[top])