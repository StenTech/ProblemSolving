from boyer_moore_horspool import same
from boyer_moore import bm_array_1
from naive import search as search2 # for testing the current algorithm

def same_raita(str1: str, patt: str) -> bool:
    i = 0
    n = len(patt)
    mid = n//2 + n%2
    if n >= 3 :
        if(patt[mid] != str1[mid]): return False
    
    if (n >= 1):
        if(patt[0] != str1[0]): return False
        
    if (n >= 2):
        if(patt[n-1] != str1[n-1]): return False
        
    return n < 3 or same(str1[1:-1], patt[1:-1])

def raita_1(string: str, pattern: str) -> list[int]:
    l, n = len(string), len(pattern)
    d = bm_array_1(pattern)
    i = 0
    matches = []
    while( l - i >= n ):
        
        if same_raita(string[i:], pattern): matches.append(i)
        
        i += d.get(string[i + n - 1], n-1)
        
    return matches

def raita_2(string: str, pattern: str) -> list[int]:
    pass


if __name__ == '__main__':
    #s = "je ne suis pas je, mais je peux je faire que des je"
    #p = "je"
    #s = "je aaa fait"
    #p = "aa"
    s = "avec tous ce qui ce passe avec le monde, j'ai décidé de partir avec mes amis et de revenir avec ma conjointe"
    p = "avec"
    #s = "stupid_spring_string"
    #p = "string"
    #p="abcdabd"
    matches1 = raita_1(s, p)
    matches2 = search2(s, p)
    print(matches1)
    print(matches2)
    print(matches1 == matches2)
    #print(kmp_array(p))