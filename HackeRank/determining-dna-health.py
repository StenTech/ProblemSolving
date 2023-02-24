#!/bin/python3

import math
import os
import random
import re
import sys
from Trie import *
from Gene import *



"""
    cette fonction permet de calculer la santé d'une chaine de caractère en :
    1. parcourant la chaine de caractère
    2. parcourant les gènes
    3. calculer la santé de la chaine de caractère
    
    ce problème est le problème determining-dna-health de hackerrank
    https://www.hackerrank.com/challenges/determining-dna-health/problem

def healthDNA(dna, start :int, end :int, genes: list, ohealth: list, char_pos: dict) :
    
    health_ = 0
    d = {}
    for i in range(start, end + 1) :
        gene = genes[i]  
        lenn = len(gene)
        count_h = d.get(gene, -1) 
        
        if count_h == -1: 
            count_h = 0
            for j in char_pos.get(gene[0], []) :
                if j+lenn <= len(dna) and gene == dna[j:j+lenn]:
                    count_h += 1
            
            d[gene] = count_h
        
        health_ += count_h*ohealth[i]
    
    return health_

"""

def healthDNA(dna, start :int, end :int, trie : Trie) :
    k = 0
    health_ = 0
    node = trie.root
    visited = []
    potential = 0
    have_potential = False
    begin = 0
    while k < len(dna):
        c = dna[k]
        if not have_potential and c in trie.root.children and k != 0:
            #print(potential, k)
            potential = k
            have_potential = True
            
        if c in node.children:
            node = node.children[c]
            visited = [c, k] 
            if node.isEnd:
                for i in node.genomeDatas:
                    if start <= i[2] <= end :
                        #print(i[1], end=" ")
                        #print(i[0], end=" ")
                        health_ += i[1]
                                
                if have_potential: 
                    k = potential
                    #print("k = ", k)
                    have_potential = False
                    
                node = trie.root.children[dna[k]]
                
            k += 1
                    
            #print()
            
        else:
            
            node = trie.root
            if visited == [c, k]:
                visited = []
                k += 1
            else:
                if have_potential:     
                    k = potential
                    have_potential = False
                
                visited = [c, k]
            #print("k = ", k)
            #k += 1
                
                
            
    print()     
    
    return health_

"""
    node = trie.root
        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]
        return node.genomeDatas if node.isEnd else False 
"""
    #print(health_)

if __name__ == '__main__':
    
    n = int(input().strip())

    genes = input().rstrip().split()

    health = list(map(int, input().rstrip().split()))
    
    genes_datas = {}
    
    trie = Trie()
    
    k = 0
    for i, j in zip(genes, health) : 
        trie.insert(Gene((i, j, k)))
        k += 1
    
    #trie.printTrie()
       
    
    s = int(input().strip())
    
    maxi = 0
    mini = math.inf

    for s_itr in range(s):
        
        first_multiple_input = input().rstrip().split()

        first = int(first_multiple_input[0])

        last = int(first_multiple_input[1])

        d = first_multiple_input[2]
        
        health_ = healthDNA(d, first, last, trie)
        #print()
        #print(health_)
        
        mini = min(health_, mini)
        maxi = max(health_, maxi)

        
    print(mini, maxi)
    
    
    
    #un ensemble complet de 10 gènes de type Gene

    #une liste des gènes
    """genes_list = [
        Gene(("abc", 2, 0)),
        Gene(("aa", 1, 1)),
        Gene(("ab", 3, 2)),
        Gene(("a", 4, 3)),
        Gene(("b", 5, 4)),
        Gene(("cd", 6, 5)),
        Gene(("cd", 6, 6)),
        Gene(("bc", 7, 7)),
        Gene(("bc", 7, 8)),
        Gene(("bd", 8, 9)),
        Gene(("abg", 9, 10)),
    ]
    
    for i in genes_list:
        trie.insert(i)
        #genes.add(i)
        #print(i)
        
    trie.printTrie()

    #une liste des 10 santé de chaque gènes de type Gene entre 1 et 7
    health = [ random.randint(1, 7) for i in range(10) ]
    """