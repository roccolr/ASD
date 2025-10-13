import numpy as np
from math import inf

def find_parenthesis(num:np.ndarray, ops:list):
    n = len(num)
    dp_max = np.zeros(dtype=np.int16, shape=(n,n))
    dp_min = np.full((n,n), inf)
    for i in range(n):
        dp_max[i,i] = num[i]
        dp_min[i,i] = num[i]
    for l in range(1,n):
        for i in range(0, n-l):
            j = i+l
            candidates_max = []
            candidates_min = []
            for k in range(i,j):
                if ops[k] == '*':
                    candidates_max.append(dp_max[i,k]*dp_max[k+1,j])
                    candidates_min.append(dp_min[i,k]*dp_min[k+1,j])
                else:
                    candidates_max.append(dp_max[i,k]+dp_max[k+1,j])
                    candidates_min.append(dp_min[i,k]+dp_min[k+1,j])
            dp_max[i,j] = np.max(candidates_max)
            dp_min[i,j] = np.min(candidates_min)

    # linear_max = []
    # linear_min = []
    # for l in range(1,n):
    #     for i in range(0, n-l):
    #         j = i+l
    #         linear_max.append(dp_max[i,j])
    #         linear_min.append(dp_min[i,j])

    return dp_max[0,n-1], dp_min[0,n-1]

if __name__ == '__main__':
    input_str = input()
    input = []
    for c in input_str:
        input.append(c)
    
    nums = []
    ops = []
    for i in range(0,len(input),2):
        nums.append(int(input[i]))
    for i in range(1,len(input)-1,2):
        ops.append(input[i])
    
    nums = np.array(nums, dtype=np.int16)
    # chiamata a funzione
    print(find_parenthesis(nums, ops))
    