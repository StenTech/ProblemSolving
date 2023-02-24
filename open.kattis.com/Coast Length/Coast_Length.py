# global variables
from collections import deque
import sys, os

directions = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0]
]

coast = 0


def dfs(G, grid, s = (0, 0)):
    
    global coast
    
    q = deque()
    q.append(s)
    seen = set()
    
    #s_str = " ".join([str(i) for i in s])
    seen.add(s)
    
    while len(q) != 0 :
        s = q.pop()
        if is_valid(s, grid) and is_water(s, grid) and is_bord(s, grid) or any([is_sea((s[0] + dir[0], s[1] + dir[1]), grid) for dir in directions]):
            grid[s[0]][s[1]] = 2
            for dir in directions :
                current = (s[0] + dir[0], s[1] + dir[1])
                if is_valid(current, grid) and is_land(current, grid):
                    coast += 1        
        for node in G[s]:
            if node not in seen:
                q.append(node)
                seen.add(node)
                
    return coast
            

def is_valid(vertex, grid):
    return vertex[0] >= 0 and vertex[0] < len(grid) and vertex[1] >= 0 and vertex[1] < len(grid[0])    
    
# verify if a vertex is a border
def is_bord(vertex,grid):
    return vertex[0] == 0 or vertex[0] == len(grid) - 1 or vertex[1] == 0 or vertex[1] == len(grid[0]) - 1

# verify if a vertex is water
def is_water(vertex, grid):
    if is_valid(vertex, grid):
        return grid[vertex[0]][vertex[1]] == 0
    return False

# verify if a vertex is land
def is_land(vertex, grid):
    if is_valid(vertex, grid):
        return grid[vertex[0]][vertex[1]] == 1
    return False

# verify if a vertex is sea water
def is_sea(vertex, grid):
    if is_valid(vertex, grid):
        return grid[vertex[0]][vertex[1]] == 2
    return False
"""
def is_sea(vertex, grid):
    if is_valid(vertex, grid):
        if is_water(vertex, grid):
            if is_bord(vertex, grid):
                return True
            set_sea = set()
            for direction in directions:
                set_sea.add(is_water((vertex[0] + direction[0], vertex[1] + direction[1]), grid))
            
            return True in set_sea
        
        else:
            return False
    return True
"""

# verify if a vertex is sea coast
def is_sea_coast(vertex, grid):
    if is_valid(vertex, grid):
        if is_land(vertex, grid):
            for direction in directions:
                if is_sea((vertex[0] + direction[0], vertex[1] + direction[1]), grid):
                    return True
        return False
    return False

# verify if a vertex belongs to a lake
def is_lake(vertex, grid):
    pass

#construc the graph of the grid
def construct_graph(grid):
    
    graph = {}
    
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if is_water((i, j), grid):
                graph[(i, j)] = []
                for direction in directions:
                    current = (i + direction[0], j + direction[1])
                    if is_valid(current, grid) and is_water(current, grid):
                        graph[(i, j)].append(current)

    return  graph

# print the grid
def print_grid(grid):
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            print(grid[i][j], end = " ")
        print()
        
def print_graph(G) :
    for node in G:
        print(node, end = " : ")
        for edge in G[node]:
            print(edge, end = " ")
        print()
    


def main():
    
    # chdir to the directory of the file in posix systems
    #os.chdir("open.kattis.com/Coast Length/testdata")
    
    #judge file
    #judge = open("judge.out", "w")
    
    """for i in range(1, 26):
        file = None
        if i < 10:
            file = "0" + str(i)
        else:
            file = str(i)
            
        
        #sys.stdin = open(file+".in", "r")
        
        with open(file+".ans", "r") as f:
            expected = int(f.read())
            
            if result == expected:
                # with check mark emoji
                print(file, ": Test passed \u2705")
            else:
                print(file, ": Test failed \u274C")
                print("\tExpected: " + str(expected))
                print("\tResult: " + str(result))
        """

    n, m = map(int, input().split())

    grid = [[0 for _ in range(m + 2)] for _ in range(n + 2)]
    for k in range(n):
        line = input()
        for j in range(m):
            if line[j] == "0":
                grid[k + 1][j + 1] = 0
            else:
                grid[k+ 1][j + 1] = 1
    
    graph = construct_graph(grid)
    
    result = dfs(graph, grid)
    #print_grid(g)
    print(result)
    

if __name__ == "__main__" : 
    main()
    
