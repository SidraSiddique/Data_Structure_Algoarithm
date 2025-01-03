import random


class BST:
    class BTNode:
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.left = left
            self.right = right

    def __init__(self):
        self.root = None

    def add(self, d, t):
        if t is None:
            return self.BTNode(d)
        if t.data > d:
            t.left = self.add(d, t.left)
        elif t.data < d:
            t.right = self.add(d, t.right)
        return t

    def add_node(self, d):
        self.root = self.add(d, self.root)

    def inorder(self, t):
        if t is not None:
            self.inorder(t.left)
            print(t.data, end=' ')
            self.inorder(t.right)

    def inorder_traversal(self):
        self.inorder(self.root)
        print()

    def preorder(self, t):
        if t is not None:
            print(t.data, end=' ')
            self.preorder(t.left)
            self.preorder(t.right)

    def preorder_traversal(self):
        self.preorder(self.root)
        print()

    def count_nodes(self, t): #Count nodes
        pass  # Implementation required

    def inorder_array(self, t, array, index):
        # call function for left of tree and get index
        # store value of current node in array according to index
        # call function for right of tree with index+1 and get index
        if t is not None:
            pass  # Implementation required

        return index

    def add_binary_search(self, array, start, end):
        # calculate middle index
        # add element in BST from middle
        # call same function for left sub-array
        # call same function for right sub-array
        if start <= end:
            pass  # Implementation required

    def check_and_balance_tree(self, count_nodes):
        # declare arrya of approriate size
        # call inorderArray with appropriate arguments
        # remove BST
        # call addBinarySearch with appropriate arguments
        pass  # Implementation required

    def check_and_balance(self):
        # get left count at root
        # get right count at root
        # get difference
        # if difference is inappropriate
        # call checkAndBalanceTree with appropriate arguments
        pass  # Implementation required

    def remove_nodes(self, t):
        # call this function for left
        # call this function for right
        # delete t
        pass

    def __del__(self):
        self.remove_nodes(self.root)


if __name__ == "__main__":
    tree = BST()
    for _ in range(20):
        tree.add_node(random.randint(100, 999))
    tree.preorder_traversal()
    tree.inorder_traversal()
    # tree.check_and_balance()
    tree.preorder_traversal()
    tree.inorder_traversal()

