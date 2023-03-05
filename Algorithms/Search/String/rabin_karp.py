def rabin_karp_uniq(string: str, pattern: str):
    n = len(string)
    m = len(pattern)
    hn = hash(string[:m])
    hm = hash(pattern)
    matches = []
    
    for i in range(n-m+1):
        if hn == hm: matches.append(i)
        