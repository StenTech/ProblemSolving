#!/usr/bin/env python3


#
def insert_in_sortedlist(arr, el):
    n = len(arr)
    if n == 0:
        arr.append(el)
    elif n == 1:
        if el <= arr[0]: arr.insert(0, el)
        else: arr.append(el)
    else:
        if el <= arr[0]: arr.insert(0, el)
        elif el >= arr[-1]: arr.append(el)
        else:
            i = 0
            while i < n-1:
                if arr[i] <= el <= arr[i+1]:
                    arr.insert(i+1, el)
                    break
                i += 1
    return arr


"""
ce algorithme est-il correct?
je pense que oui, mais je ne suis pas sur.
je ne suis pas sur de la complexité temporelle de cet algorithme.
je pense que c'est O(n^2), mais je ne suis pas sur.
"""
def insertion (arr) :
    n = len(arr)
    sortedList = []
    for el in arr :
        sortedList = insert_in_sortedlist(sortedList, el)
        
    return sortedList


#complexité temporelle: O(n^2)
#complexité spatiale: O(n)
def insertion_sort(arr):
  for i in range(1, len(arr)):
    curr = arr[i]
    j = i-1
    while j >= 0 and curr < arr[j]:
      arr[j+1] = arr[j]
      j -= 1
    arr[j+1] = curr
  return arr


# for testing
def main() :
    # random list of 15 integers between 0 and 10
    import random
    
    
    listofInt = [random.randint(0,10) for i in range(25)]
    print(listofInt)
    
    sortedList = insertion_sort(listofInt)
    listofInt.sort()
    print(listofInt)
    print()
    print(sortedList == listofInt)
    print()
    

if __name__ == "__main__" :
    main()