"""
Problem: Perket
Link: https://open.kattis.com/problems/perket
"""

from math import inf
import os, sys


def solve():
    
    n = int(input())
    
    ingredients = []
    
    for i in range(n):
        ingredients.append(list(map(int, input().split())))
        
    
    if len(ingredients) == 1:
        return abs(ingredients[0][0] - ingredients[0][1])
    
    # initialisation de la valeur minimale à l'infini
    min_diff = inf
    
    # Loop through all possible combinations of ingredients
    # other approaches with itertools are possible
    for i in range(1, 1 << n):
        # initialisation de la valeur de sour et bitter à 1
        sour = 1
        bitter = 0
        
        for j in range(n):
            # if the jth bit is set, add the jth ingredient to the mix
            if i & (1 << j):
                sour *= ingredients[j][0]
                bitter += ingredients[j][1]
        
        # update the minimum difference if necessary
        min_diff = min(min_diff, abs(sour - bitter))
    
    return min_diff
    
def main():
    # chdir to the directory of the file in posix systems
    os.chdir("open.kattis.com/Perket/testdata")
    
    #judge file
    ##judge = open("judge.out", "w")
    
    for i in range(1, 11):
        
        
        sys.stdin = open(f'perket.in.{i}', "r")
        
        with open(f'perket.out.{i}', "r") as f:
            expected = str(f.read()).strip()
            result = str(solve())
            if result == expected:
                # with check mark emoji
                print(i, ": Test passed \u2705")
            else:
                print(i, ": Test failed \u274C")
                print("\tExpected: " + str(expected))
                print("\tResult: " + str(result))
    
    
if __name__ == "__main__":
    main()