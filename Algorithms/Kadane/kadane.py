# this find the maximum sub array sum

"""
def kadane(arr) :
    max_sum = 0
    local_sum = 0
    i, j = 0, 0
    
    for k in range(len(arr)) :
        local_sum = max(0, local_sum+arr[k])
        max_sum = max(max_sum, local_sum)
        if local_sum == 0 : 
            i = k + 1
            j = k + 1
        else : j = k
        
    return max_sum, [i, j]
"""

# Kadane's algorithm proposed by github copilot
# the maximum sub array index is also returned
def kadane(arr) :
    max_sum = 0
    local_sum = 0
    best_start = 0
    best_end = 0
    k = 0
    for i, x in enumerate(arr) :
        local_sum = local_sum+x
        if local_sum <= 0 :
            local_sum = 0
            best_start = i+1
        
        if local_sum > max_sum :
            max_sum = local_sum
            best_end = i
            k = best_start
    
    return max_sum, [k, best_end-k+1]

# test
def main() :
    arr = [-2, -3, 4, -1, -2, 1, 5, 1]
    res = kadane(arr)
    i, l = res[1]
    print(res[0])
    print(arr[i:i+l])

if __name__ == "__main__" :
    main()