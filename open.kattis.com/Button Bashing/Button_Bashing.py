"""
Problem: Button Bashing 
URL: https://open.kattis.com/problems/buttonbashing
"""
from collections import deque

#library for binary search
import bisect as bs

#construct a graph with the buttons and the time
def construct_graph(buttons):
    G = {}
    for i in range(3601):
        G[i] = []
        for b in buttons:
            cur = b + i
            if cur <= 0: continue
            elif cur > 3600: cur = 3600
            G[i].append(cur)
    return G

def bfs(G, s) : 
    
    q = deque()
    dist = {}
    q.append(s)
    dist[s] = 0
    
    while len(q) != 0 :
        current_node = q.popleft()
        for node in G[current_node]:
            if node not in dist:
                q.append(node)
                dist[node] = dist[current_node] + 1
                
    return dist

def solve(t, buttons):
    G = construct_graph(buttons)
    dist = bfs(G, 0)
    if t in dist:
        return (dist[t], 0)
    else:
        #find the first time above t
        times = list(dist.keys())
        times.sort()
        i = bs.bisect_right(times, t)
        return (dist[times[i]], times[i] - t)

def main():
    T  = int(input())
    
    for _ in range(T):
        n, t = map(int, input().split())
        buttons = list(map(int, input().split()))
        
        print(*solve(t, buttons))    
        
        
if __name__ == "__main__" :
    main()

