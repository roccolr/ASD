from math import inf

def max_crossing_subarray(arr, p,q,r):
    partial_sum_left = -inf 
    partial_sum_right = -inf

    local_left_sum = 0
    for i in range(q, p-1, -1):
        local_left_sum += arr[i]
        if local_left_sum > partial_sum_left:
            partial_sum_left = local_left_sum
    
    local_right_sum = 0
    for i in range(q+1, r+1):
        local_right_sum += arr[i]
        if local_right_sum > partial_sum_right:
            partial_sum_right = local_right_sum
    
    return partial_sum_left+partial_sum_right

def find_max_subarray(arr, p, r):
    if p==r:
        return arr[p]
    
    q = (p+r) // 2
    left_sum = find_max_subarray(arr, p, q)
    right_sum = find_max_subarray(arr, q+1, r)
    cross_sum = max_crossing_subarray(arr, p, q, r)

    if left_sum > right_sum and left_sum > cross_sum:
        return left_sum
    elif right_sum > left_sum and right_sum > cross_sum:
        return right_sum
    else:
        return cross_sum
    
if __name__ == '__main__':
    arr = [-1, 2, -5, 7]
print(find_max_subarray(arr, 0, 3))