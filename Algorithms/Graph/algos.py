#import queue
from collections import deque
import random


def bfs(G, s) : 
    
    q = deque()
    dist = {}
    q.append(s)
    dist[s] = 0
    
    while len(q) != 0 :
        current_node = q.pop()
        
        for node in G[current_node]:
            if node not in dist:
                q.append(node)
                dist[node] = dist[current_node] + 1
        
    return dist

#dfs iterative
def dfs(G, s) :
    
    q = deque()
    q.append(s)
    seen = set([s])
    path = []
    while len(q) != 0 :
        current_node = q.pop()
        for node in G[current_node]:
            if node not in path:
                q.append(node)
                seen.add(node)
        path.append(current_node)
                
    return path    
        

def dfs_recursive(G, s, seen = None) :
    
    if seen is None:
        seen = []
    
    seen.append(s)
    
    for node in G[s]:
        if node not in seen:
            dfs_recursive(G, node, seen)
    
    return seen
"""
def print_graph(G) :
    for node in G:
        print(node, G[node])
"""

#prints the graph in a nice way
def print_graph(G) :
    for node in G:
        print(node, end = " : ")
        for edge in G[node]:
            print(edge, end = " ")
        print()
    

#test on a very simple graph
def main() :
    
    # G

    G = {1: [2, 3], 2: [4, 5], 3: [5], 4: [5], 5: [6], 6: []}
    
    print(dfs(G, 1))
    print(dfs_recursive(G, 1))
    
if __name__ == "__main__" :
    main()