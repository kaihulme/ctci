
class BinaryTree:
    
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
    def insert_left(self, x):
        if not self.left:
            self.left = BinaryTree(x)
        else:
            new_left = BinaryTree(x)
            new_left.left = self.left
            self.left = new_left
            
    def insert_right(self, x):
        if not self.right:
            self.right = BinaryTree(x)
        else:
            new_right = BinaryTree(x)
            new_right.right = self.right
            self.right = new_right
    
    def print_tree(self, tree=None):
        if not tree:
            tree = self
        print(tree.val)
        if tree.left:
            tree.print_tree(tree.left)
        if tree.right:
            tree.print_tree(tree.right)
    

btree = BinaryTree(1)
btree.insert_left(2)
btree.insert_right(3)
btree.insert_right(4)

btree.print_tree()

