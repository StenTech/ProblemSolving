"""
Problem : 4 thought
url : https://open.kattis.com/problems/4thought

"""

from collections import deque

class Node:
    def __init__(self, parent = None, operation = None):
        self.operation = operation
        self.parent = parent
        self.children = []
    
    def add_child(self, node):
        self.children.append(node)
    
    def set_children(self, children):
        self.children = children
    
    def is_leaf(self, node):
        return node.is_leaf
    
    def __eq__(self, __o: object) -> bool:
        if not isinstance(__o, Node):
            return False
        return self.operation == __o.operation


class Tree:
    def __init__(self, root):
        self.root = root
    
    def insert(self, node, parent):
        parent.children.append(node)
    

    
    # print the tree in grafical form awesome
    def print_tree(self, node = None, depth = 0):
        if(node == None) :
            node = self.root
        print("  " * depth + str(node.operation))
        for child in node.children :
            self.print_tree(child, depth + 1)
        
    

def build_tree(root : Node, depth = 3):
    if(depth == 0) :
        return
    
    root.add_child(Node(root, '+'))
    root.add_child(Node(root, '-'))
    root.add_child(Node(root, '*'))
    root.add_child(Node(root, '/'))
    
    for child in root.children :
        build_tree(child, depth -1)
        
def dfs(root : Node, path = [], paths = []):
    if(root == None) :
        return
    
    if root.operation != None :
        path.append(root.operation)
    
    if root.children == [] :
        paths.append(path.copy())

    for child in root.children :
        dfs(child, path, paths)
        path.pop()
     
    return paths   
    
    
        
def main() :
    tree = Tree(Node())
    build_tree(tree.root)
    #print(len(dfs(tree.root, [], [])))
    m = int(input())
    paths = dfs(tree.root, [], [])
    
    for i in range(m) :
        target = int(input())
        #paths.append(path)
        for path in paths :
            calculus = "4 "
            for operation in path :
                calculus += operation + " 4 "
            calculus = calculus.replace("/", "//")
            result = eval(calculus)
            if (result == target) :
                calculus = calculus.replace("//", "/")
                print(calculus + " = " + str(target))
                break
            
        else :
            print("no solution")

if __name__ == "__main__" :
    main()