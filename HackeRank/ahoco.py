class Trienode :
    def __init__(self, value) :
        self.value = value
        self.children = {}
        self.isEnd = False

class Trie :
    def __init__(self, patterns = None):
        self.root = Trienode(None)
        if pattern != None :
            for pattern in patterns :
                self.insert(pattern)
    
    def insert(self, word) :
        node = self.root
        for c in word :
            if c not in node.children : 
                node.children[c] = Trienode(c)
            node = node.children[c]
        node.isEnd = True


class Ahoco :

    def __init__(self, patterns) :
        self.patterns = patterns
        self.trie = Trie(patterns)
        self.build_transition_table()
        self.build_failure_table()

    def build_transition_table(self) :
        self.transition = []
        