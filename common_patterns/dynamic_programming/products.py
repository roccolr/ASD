def solve(b:int, c:int, m:list)->int:
    dp = [[-1]*(b+1) for i in range(c+1)]
    
    for j in range(b+1):
        dp[0][j] = 0

    for i in range(1, c+1):
        n = len(m[i-1])
        for j in range(b+1):
            candidates = []
            for k in range(0,n):
                p = m[i-1][k]
                if j >= p and dp[i-1][j-p] != -1:
                    candidates.append(dp[i-1][j-p]+p)
            
            dp[i][j] = max(candidates) if len(candidates) != 0 else dp[i][j-1]
    return dp[c][b]

if __name__ == '__main__':
    n = int(input())
    suite = []
    for _ in range(n):
        test = {}
        b_c_list = input().split()
        test["budget"] = int(b_c_list[0])
        test["n_class"] = int(b_c_list[1])

        p_matrix = []
        for _ in range(test["n_class"]):
            row = input().split()
            k = int(row[0])
            items = []
            for i in range(1,k+1):
                items.append(int(row[i]))
            p_matrix.append(items)

        test["p_matrix"] = p_matrix
        suite.append(test)
    
    for i in range(n):
        print(solve(suite[i]["budget"], suite[i]["n_class"], suite[i]["p_matrix"]))
