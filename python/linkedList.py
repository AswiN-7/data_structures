class LinkedList:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

def createLinkedList(data, l):
    newNode = LinkedList(data)
    if l is None:
        l= newNode
    else:
        temp = l
        while(temp.next):
            temp = temp.next
        temp.next = newNode
    return l
def printLL(l):
    temp = l
    while(temp):
        print(temp.data, end=" ")
        temp = temp.next
    print()

"""
1-> 2-> 3
"""
def reverseLinkedList(root):
    prv = None
    next = root.next
    current = root
    while(next.next):
        current.next = prv
        prv = current
        current = next
        next = next.next
    next.next = prv
    root = next
    printLL(root)



root  = None
root = createLinkedList(5, root)
root = createLinkedList(10, root)
createLinkedList(1001, root)
createLinkedList(1003, root)
createLinkedList(1005, root)
createLinkedList(1006, root)
createLinkedList(1005, root)

printLL(root)
reverseLinkedList(root)