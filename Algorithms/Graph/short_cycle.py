"""
Compute the shortest cycle in a graph.
"""

# NB : all here are not working


def bfs(G, s) : 
    
    q = []
    # store the distance from s
    dist = {}
    q.append(s)
    dist[s] = 0
    
    # store path from s to each node in the graph G and the distance
    path = [[[s], 0]]
    __path  = []
    
    while len(q) != 0 :
        current_node = q.pop()
        current_dist = dist[current_node]
        __path.append(current_node)
        for node in G[current_node]:
            if node not in dist:
                q.append(node)
                dist[node] = current_dist + 1
                path.append([__path + [node], dist[node]])
            elif node == s :
                path.append([__path + [node], current_dist + 1])
                
        current_dist += 1
        if __path != [s] :
            __path.pop()
                
    
    return path
    
#test on a very complex graph

def main() : 
    
    G = {1: [2, 3], 2: [1, 3, 4], 3: [1, 2, 4], 4: [2, 3, 5], 5: [4, 6], 6: [5]} 
    
    for node in G :
        paths = bfs(G, node)
        
        for path in paths :
            print(path)
        
        
        
if __name__ == "__main__" :
    main()