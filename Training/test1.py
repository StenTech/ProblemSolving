# random list of 15 integers between 0 and 10
import random


listofInt = [random.randint(0,10) for i in range(25)]

n = len(listofInt)
i = 0
ans = 0
val = 2
while i != n :
    while i < n and listofInt[i] != val :
        i += 1
    if i != n :
        ans += 1
        i += 1
        
print(listofInt)
print()
print(ans)