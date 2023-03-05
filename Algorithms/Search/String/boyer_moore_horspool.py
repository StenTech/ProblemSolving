from boyer_moore import bm_array_1 
from naive import search as search2 # for testing the current algorithm

def same(str1: str, patt: str) -> bool:
    n = len(patt)
    i = n - 1
    
    while(patt[i] == str1[i]):
        if i == 0: return True
        i -= 1
        
    return False
        
        
def search(string: str, pattern: str) -> list[int]:
    l, n = len(string), len(pattern)
    d = bm_array_1(pattern)
    i = 0
    matches = []
    while( l - i >= n ):
        
        if same(string[i:], pattern): matches.append(i)
        #c = d.get(string[i + n - 1], n-1)
        #print(c)
        #print(string[i + n - 1])
        i += d.get(string[i + n - 1], n-1)
        
    return matches


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
    matches1 = search(s, p)
    matches2 = search2(s, p)
    print(matches1)
    print(matches2)
    print(matches1 == matches2)
    #print(kmp_array(p))