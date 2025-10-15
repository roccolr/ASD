from math import inf

def solve(op_list:list, sym_list:list)->tuple:
    len_op = len(op_list)
    len_sym = len(sym_list)

    max_dp = [[-inf]*len_op for _ in range(len_op)]
    min_dp = [[inf]*len_op for _ in range(len_op)]

    for i in range(len_op):
        max_dp[i][i] = op_list[i]
        min_dp[i][i] = op_list[i]
    
    for k in range(1, len_op):
        for i in range(0, len_op-k):
            j = i+k
            candidates_max = []
            candidates_min = []

            for l in range(i, j):
                if sym_list[l] == '*':
                    candidates_max.append(max_dp[i][l]*max_dp[l+1][j])
                    candidates_min.append(min_dp[i][l]*min_dp[l+1][j])
                else:
                    candidates_max.append(max_dp[i][l]+max_dp[l+1][j])
                    candidates_min.append(min_dp[i][l]+min_dp[l+1][j])
            max_dp[i][j] = max(candidates_max)
            min_dp[i][j] = min(candidates_min)
    
    return max_dp[0][len_op-1], min_dp[0][len_op-1]

if __name__ == '__main__':
    print(*solve([3,14,19,3,10], ['*','+','+','*']))
    