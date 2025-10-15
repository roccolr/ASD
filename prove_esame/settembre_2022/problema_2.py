import numpy as np 


def tartaglia(n:int):
    dp = [[] for _ in range(n)]
    dp[0] = [1]
    
    for i in range(1,n):
        prev_len = len(dp[i-1])
        dp[i].append(1)
        for j in range(1,prev_len):
            dp[i].append(dp[i-1][j-1]+dp[i-1][j])
        dp[i].append(1)
    return dp[n-1]


if __name__ == '__main__':
    print(*tartaglia(5))