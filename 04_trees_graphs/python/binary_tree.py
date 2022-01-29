
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
            
    def pre_order(self, tree=None):
        if not tree:
            tree = self
        print(tree.val)
        if tree.left:
            tree.pre_order(tree.left)
        if tree.right:
            tree.pre_order(tree.right)
            
    def in_order(self, tree=None):
        if not tree:
            tree = self
        if tree.left:
            tree.pre_order(tree.left)
        print(tree.val)
        if tree.right:
            tree.pre_order(tree.right)
            
    def post_order(self, tree=None):
        if not tree:
            tree = self
        if tree.left:
            tree.pre_order(tree.left)
        if tree.right:
            tree.pre_order(tree.right)
        print(tree.val)
    

btree = BinaryTree(1)
btree.insert_left(2)
btree.insert_right(3)
btree.insert_right(4)

# btree.print_tree()
# btree.pre_order()
# btree.in_order()
btree.post_order()

