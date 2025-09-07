from typing import Final

size: Final = 50
queue = [None] * size
front = -1
rear = -1


def push(data):
    global front
    global rear

    if rear == size - 1:
        print("overflow...")
        return
    
    if front == -1:
        front = 0

    rear+=1
    queue[rear]=data

def pop():
    global font, rear
    if front == -1 or front > rear:
        print("underflow")
        return
    front+=1

    if front>rear:
        front=-1
        rear=-1

def display():
    if front ==-1 or front>rear:
        print("empty...")
        return
    
    for i in range(front,rear+1):
        print(queue[i],end=" ")
    print()

if __name__=="__main__":
    push(5)
    push(6)
    push(7)
    push(8)
    display()
    print(queue[front])