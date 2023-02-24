#!/usr/bin/env python3

# complexite temporel O(n log n)
# complexite espace O(n)
def quick_sort(arr):
  if len(arr) <= 1:
    return arr
  pivot = arr[len(arr) // 2]
  left = [x for x in arr if x < pivot]
  middle = [x for x in arr if x == pivot]
  right = [x for x in arr if x > pivot]
  return quick_sort(left) + middle + quick_sort(right)

# for testing  
def main() :
    # random list of 15 integers between 0 and 10
    import random
    
    
    listofInt = [random.randint(0,10) for i in range(25)]
    print(listofInt)
    listofInt.sort()
    print()
    print(quick_sort(listofInt)==listofInt)
    

if __name__ == "__main__" :
    main()
    