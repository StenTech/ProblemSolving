#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

"""
    HackerRank: Connected Cell in a Grid
"""

#
# Complete the 'connectedCell' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY matrix as parameter.
#

def connectedCell(matrix):
    l = len(matrix)
    c = len(matrix[0])
    #create a matrix of zeros
    grouped = [[0 for i in range(c)] for j in range(l)]
    
    directions = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]
    
    #create a queue
    q = []
    
    # count the number of groups starting from 2
    count_group = 2
    
    #dictionary to store the number of elements in each group
    d = {}
    
    for i in range(l):
        for j in range(c):
            
            if grouped[i][j] == 0 and matrix[i][j] == 1:
            
                grouped[i][j] = count_group
                q.append([i, j])
                
                d[grouped[i][j]] = 1
                
                while(len(q) > 0) :
                
                    cur_pos = q[0]
                    q = q[1:]
                    
                    for dir_ in directions :
                        
                        x = cur_pos[0] + dir_[0]
                        y = cur_pos[1] + dir_[1]
                        
                        if (x >= 0 and x < l and y >= 0 and y < c and grouped[x][y] == 0 and matrix[x][y] == matrix[cur_pos[0]][cur_pos[1]] and matrix[x][y] == 1) :                    
                            grouped[x][y] = grouped[cur_pos[0]][cur_pos[1]]
                            d[grouped[x][y]] += 1
                            q.append([x, y])
                                
                
                count_group += 1
            
        #print(grouped)
        
        
    return d[max(d, key=d.get)]
                
                
    
if __name__ == '__main__':

    n = int(input().strip())

    m = int(input().strip())

    matrix = []

    for _ in range(n):
        matrix.append(list(map(int, input().rstrip().split())))

    result = connectedCell(matrix)
    """for i in range(n):
        for j in range(m) : print(result[i][j], end=" ")
        print()"""
    print(result)

    
