import random

class bNode:
    
    def __init__(self) -> None:
        #node's value
        self.value = random.randint

        #node's children
        self.left = bNode(random.randint)
        self.right = bNode(random.randint)

class nNode:
    
    def __init__(self, num) -> None:
        #node's value
        self.value = num

        #node's children
        self.children = []

class bTree:
    
    def __init__(self) -> None:
        self.root = bNode(random.randint)
    
    def create_children(self){
        pass
    }

class nTree:
    pass