from math import inf

def ferry_boat(schedule:list, m:int, t:int, n:int):
    dp = []
    trips = []

    for _ in range(m+1):
        dp.append(0)
        trips.append(0)
    
    dp[0] = 0
    trips[0] = 0

    for i in range(1, m+1):
        best_ready_time = inf
        best_index = 0

        for j in range(1, min(n,i)+1):
            ready_time = dp[i-j]
            if ready_time < best_ready_time:
                best_ready_time = ready_time
                best_index = j 
        
        if best_ready_time >= schedule[i-1]:
            dp[i] = best_ready_time + t 
            trips[i] = trips[i-best_index] + 1
        else:
            dp[i] = schedule[i-1] + t
            trips[i] = trips[i-best_index] + 1

    return dp[m], trips[m]

if __name__ == '__main__':
    schedule = list(range(0, 91, 10))
    schedule_2 = [10,30,40]

    print(*ferry_boat(schedule, 10, 10, 2))
    print(*ferry_boat(schedule_2, 3, 10, 2))
