"""
Ici nous essayerons de resoudre le probleme determining-dna-health de hackerrank
https://www.hackerrank.com/challenges/determining-dna-health/problem
avec l'algorithme de aho-corasick
"""

from typing import List, Tuple, Dict, Set
from collections import defaultdict
from collections import Counter
from dataclasses import dataclass
from functools import reduce
from operator import add
from Trie import Trie
import math

class AhoCorasick:
   pass
            
            
    
def determine_health(genomes: str, patterns: List[str], health_values: List[int], first: int, last: int) -> int:
    """
    Determine the health of the given patterns in the given genomes.
    """
    # Build the Aho-Corasick automaton.
    ac = AhoCorasick(patterns)
    # Search for the patterns in the genomes.
    matches = Counter(ac.search(genomes))
    
    # Compute the health.
    health = 0
    for match in matches:
        health += matches[match] * health_values[match]
    
    return health


        

def main():
    
    n = int(input().strip())

    genes = input().rstrip().split()

    health = list(map(int, input().rstrip().split()))
    
    genes_datas = {}
    
    #trie = Trie()
    
    """k = 0
    for i, j in zip(genes, health) : 
        trie.insert(Gene((i, j, k)))
        k += 1
    """
    #trie.printTrie()
    
    #building the automatom
    ac = AhoCorasick(genes)
    ac.print_Automatom()
       
    
    s = int(input().strip())
    
    maxi = 0
    mini = math.inf

    for s_itr in range(s):
        
        first_multiple_input = input().rstrip().split()

        first = int(first_multiple_input[0])

        last = int(first_multiple_input[1])

        d = first_multiple_input[2]
        
        #test the Aho-Corasick automaton
        #print(ac.search(d))
        
        
if __name__ == "__main__":
    main()
    # right alignement print
    