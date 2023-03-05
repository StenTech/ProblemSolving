def search(string: str, pattern: str) -> list[int]:
    matches = []
    for i in range(len(string)):
        for j in range(len(pattern)):
            if pattern[j] != string[i+j]: break
        else: matches.append(i)
    return matches


if __name__ == '__main__':
    #s = "je ne suis pas je, mais je peux je faire que des je"
    #p = "je"
    s = "je aaa fait"
    p = "aa"
    matches = search(s, p)
    print(matches)
    for i in matches:
        print(s[i])
    