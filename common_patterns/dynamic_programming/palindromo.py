def lcs(str1:str,str2:str)->int:
    n1,n2 = len(str1), len(str2)
    dp = []
    for _ in range(n1+1):
        temp = []
        for _ in range(n2+1):
            temp.append(0)
        dp.append(temp)
    
    for i in range(1, n1+1):
        for j in range(1, n2+1):
            if str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[n1][n2]

def solve_palindrome(str1:str)->int:
    return lcs(str1, str1[::-1])

if __name__ == '__main__':
    print(solve_palindrome("MADAM"))
    