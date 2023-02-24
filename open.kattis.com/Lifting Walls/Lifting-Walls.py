######################################################################
###         Language: Python3                                        #
###         Problem: Lifting Walls                                   #
###         url: https://open.kattis.com/problems/liftingwalls       #
######################################################################

import sys, os, itertools as it

def distance(x1, y1, x2, y2):
    return ((x1 - x2)**2 + (y1 - y2)**2)

def solve():
    l, w, n, r = map(int, input().split())
    
    x0 = [-l, l, 0 , 0]
    y0 = [0, 0, -w, w]
    
    possible_cranes = []
    for i in range(n):
        x, y = map(int, input().split())
        
        walls = 0
        for j in range(4):
            if distance(2*x, 2*y, x0[j], y0[j]) <= 4*r**2:
                walls |= (1 << j)
            
        if walls == 15:
            return 1
        
        if walls != 0:
            possible_cranes.append(walls)

    #generate all possible combination of 1, 2, 3 and 4 cranes
    for i in range(2, 5):
        for comb in it.combinations(possible_cranes, i):
            walls = 0
            for c_ in comb:
                walls |= c_
            if walls == 15:
                return i
    else :
        return "Impossible"
    
    
    """
    for i in range(len(possible_cranes)):
        value += possible_cranes[i]
        nb_crane += 1
        if nb_crane > 4:
            return "Impossible"
        if value >= 4:
            return nb_crane
    else:
        return "Impossible"""


def main():
    # chdir to the directory of the file in posix systems
    os.chdir("open.kattis.com/Lifting Walls/testdata")
    
    #judge file
    ##judge = open("judge.out", "w")
    
    for i in range(1, 15):
        file = None
        if i < 10:
            file = "0" + str(i)
        else:
            file = str(i)
            
        
        sys.stdin = open(file+".in", "r")
        
        with open(file+".ans", "r") as f:
            expected = str(f.read()).strip()
            result = str(solve())
            if result == expected:
                # with check mark emoji
                print(file, ": Test passed \u2705")
            else:
                print(file, ": Test failed \u274C")
                print("\tExpected: " + str(expected))
                print("\tResult: " + str(result))
        
    
    
if __name__ == "__main__":
    main()
    