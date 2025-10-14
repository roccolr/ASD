def backtrack(n, h, base_array, arr:list, curr_dim, curr_diff):
    if curr_dim == n:
        if curr_diff == h:
            print(*arr)
        return 
    if curr_diff > h or curr_diff + (n-curr_dim) < h:
        return 
    
    arr.append(0)
    backtrack(n, h, base_array, arr, curr_dim+1, curr_diff + (0 == base_array[curr_dim]))
    arr.pop()
    arr.append(1)
    backtrack(n,h, base_array, arr, curr_dim+1, curr_diff + (1 == base_array[curr_dim]))
    arr.pop()



if __name__ == '__main__':
    n = 4
    h = 2
    base_array = [0] * n
    arr = []
    #chiamata a funzione 
    backtrack(n, h, base_array, arr, 0, 0)