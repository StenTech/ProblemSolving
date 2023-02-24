from Gene import Gene

class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False
        self.genomeDatas = []
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.genomeDatas.append((word.nucleotides, word.health, word.position))
        node.isEnd = True
        
    def search(self, word) -> list:
        node = self.root
        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]
        return True if node.isEnd else False
    
    def startsWith(self, prefix):
        node = self.root
        for c in prefix:
            if c not in node.children:
                return False
            node = node.children[c]
        return True
    
    def delete(self, word):
        def deleteHelper(node, word, i):
            if i == len(word):
                if node.isEnd:
                    node.isEnd = False
                    return len(node.children) == 0
                return False
            c = word[i]
            if c not in node.children:
                return False
            shouldDelete = deleteHelper(node.children[c], word, i+1)
            if shouldDelete:
                del node.children[c]
                return len(node.children) == 0
            return False
        deleteHelper(self.root, word, 0)
        
    def printTrie(self):
        def printHelper(node, word):
            if node.isEnd:
                print(word, node.genomeDatas)
            for c in node.children:
                printHelper(node.children[c], word+c)
        printHelper(self.root, '')
        
    def __str__(self) -> str:
        return self.printTrie()
    
    def __repr__(self) -> str:
        return self.printTrie()
    
    
    