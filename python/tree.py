from typing import no_type_check_decorator

class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left = None
        self.right = None
    def __str__(self) -> str:
        return "{}".format(self.data)
    
class tree:
    def __init__(self) -> None:
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, node):
        if data > node.data:
            if node.right is not None:
                self._insert(data, node.right)
            else:
                node.right = Node(data)
        elif data < node.data:
            if node.left is not None:
                self._insert(data, node.left)
            else:
                node.left = Node(data)

    def findMin(self, node):
        temp = node
        while(temp.left is not None):
            temp = temp.left
        return temp.data

    def find(self, value, node):
        if node is None:
            return None
        elif value<node.data:
            return self.find(value, node.left)
        elif value>node.data:
            return self.find(value, node.right)
        else:
            return node

    def delete(self, value, node):
        if node is None:
            print("element not present")
            return
        elif value > node.data:
            node.right = self.delete(value, node.right)
        elif value < node.data:
            node.left = self.delete(value, node.left)
        else:
            if node.left is not None and node.right is not None:
                node.data = self.findMin(node.right)
                node.right = self.delete(node.data, node.right)
            elif node.left is None and node.right is None:
                return None
            elif node.left is None:
                return node.right
            else:
                return node.left
        return node            


    def inorderTraversal(self, root):
        if root is not None:
            self.inorderTraversal(root.left)
            print(root.data, end=" ")
            self.inorderTraversal(root.right)
    
    def countNodes(self, root):
        if root is None:
            return 0
        return self.countNodes(root.left) + self.countNodes(root.right) + 1
    
bst = tree()
bst.insert(5)
bst.insert(3)
bst.insert(4)
bst.insert(1)
bst.insert(2)
bst.insert(6)
bst.insert(9)
bst.insert(10)
bst.insert(7)

bst.inorderTraversal(bst.root)
print()
print("min ", bst.findMin(bst.root))

print("find 4 : ", bst.find(4, bst.root))
# bst.delete(3, bst.root)
# bst.inorderTraversal(bst.root)

print(bst.countNodes(bst.root))

"""
aabbcc
d 
"""