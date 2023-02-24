
"""
    is it the correct implementation of selection sort?
    I think it is, but I am not sure.
    I am not sure about the time complexity of this algorithm.
    I think it is O(n^2), but I am not sure.    
"""
def selection(arr) : 
    n = len(arr)
    for i in range(n) :
        min_ = arr[i]
        k = i
        for j in range(i+1, n):
            if arr[j] < min_ : 
                min_ = arr[j]
                k = j
            
        arr[i], arr[k]  = min_, arr[i]
        
    return arr

# complexite temporel O(n^2)
# complexite espace O(n)
def selection_sort(arr):
  for i in range(len(arr)):
    min_index = i
    for j in range(i+1, len(arr)):
      if arr[j] < arr[min_index]:
        min_index = j
    arr[i], arr[min_index] = arr[min_index], arr[i]
  return arr


# for testing
def main() :
    # random list of 15 integers between 0 and 10
    import random
    
    
    listofInt = [random.randint(0,10) for i in range(25)]
    sortedList = selection(listofInt)
    listofInt.sort()
    print(listofInt)
    print()
    print(sortedList == listofInt)
    
if __name__ == "__main__" :
    main()