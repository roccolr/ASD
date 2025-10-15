def backtrack(str1:str,str2:str,ans:list):
    if str1 == str2:
        ans.append(len(str1))
    if len(str1) == 0 or len(str2) == 0:
        return 
    
    idx = 0
    while(1):
        if str1[idx] != str2[idx]:
            break
        idx += 1
    backtrack(str1.replace(str1[idx],''),str2.replace(str1[idx],''), ans)
    backtrack(str1.replace(str2[idx],''),str2.replace(str2[idx],''), ans)


def solve_trips(str1:str, str2:str):
    n1,n2 = len(str1), len(str2)
    dp = []
    for _ in range(n1+1):
        temp = []
        for _ in range(n2+1):
            temp.append(0)
        dp.append(temp)
    
    for i in range(1,n1+1):
        for j in range(1, n2+1):
            if str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[n1][n2]

if __name__ == '__main__':
    print(solve_trips("abcd","acdb"))