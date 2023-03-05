def bm_array_1(patt: str) -> dict[str, int]:
    n = len(patt)
    d = {}
    for i in range(n-2, -1, -1):
        c = patt[i]
        if c not in d:
            d[c] = n - i - 1
    return d

def bm_array_2(patt: str) -> list[int]: 
    pass

def boyer_moore():
    pass



if __name__ == '__main__':
    print(bm_array_1("wikipedia"))