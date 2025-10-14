from math import inf
from numpy import argmin

def ferry_boat_solver(arr, n, t, m):
    dp = []
    trips = []
    for _ in range(m+1):
        dp.append(inf)
        trips.append(0)

    dp[0] = arr[0] + t
    trips[0] = 1

    for i in range(1,m+1):
        times = [] # tempi in cui il ferry è pronto

        for k in range(1,min(n,i)+1):
            times.append(dp[i-k])

        start_time = max(min(times)+t, arr[i-1])
        if min(times)+t > arr[i-1]:
            start_time = min(times)+t
            idx = argmin(times)
            trips[i] = trips[i-idx]+2
        else:
            start_time = arr[i-1]
            trips[i] = trips[i-1]+2

        dp[i] = start_time+t
    
    return dp[m]-t, trips[m]



if __name__ == '__main__':
    input_1 = [0,10,20,30,40,50,60,70,80,90]
    input_2 = [10,30,40]
    m1 = 10
    m2 = 3
    t = 10 
    n1 = 2
    n2 = 2

    # chiamata 1
    print(*ferry_boat_solver(input_1, n1, t, m1))
    #chiamata 2
    print(*ferry_boat_solver(input_2, n2, t, m2))
