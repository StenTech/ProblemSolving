from naive import search # for testing the current algorithm


def kmp_array(pat):
    n = len(pat)
    lps = [0] * n
    i = 1
    j = 0
    while i < n:
        if(pat[i] == pat[j]) : 
            lps[i] = j+1
            i+=1; j+=1
        else:
            i+=1; j=0
            
    return lps + [-1]

def kmp_search(string: str, pattern: str) -> list[int]:
    matches = []
    lps = kmp_array(pattern)
    n = len(pattern)
    l = len(string)
    i = 0
    m = 0
    #return l, n
    while(i+m < l):
        
        #if(i+m == l): return matches
        #print(m+i, i)
        if(string[m+i] == pattern[i]):
            i+=1
            if(i == n): 
                matches.append(m)
                m = m+i-lps[i-1]
                if i > 0:
                    i = lps[i-1]
                
        else:
            m = m+i-lps[i-1]
            if i > 0:
                i = lps[i-1]
    
    return matches


if __name__ == '__main__':
    #s = "je ne suis pas je, mais je peux je faire que des je"
    #p = "je"
    s = "je aaa fait"
    p = "aa"
    #p="abcdabd"
    matches = kmp_search(s, p)
    print(matches == search(s, p))
    #print(kmp_array(p))
    