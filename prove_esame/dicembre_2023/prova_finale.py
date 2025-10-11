import numpy as np 

def find_max_spesa(B:int, C:int, prezzi):
    dp = np.full((C+1,B+1), -1)
    # dp[i][j] = spesa massima effettuabile con i classi e j<=B budget 
    # la soluzione al problema sarà il max dell'ultima riga

    # caso base 
    dp[0, :] = 0
    for i in range(1, C+1):
        for j in range(1,B+1):
            n_elem = prezzi[i-1][0]
            candidati = []
            for k in range(1,n_elem+1):
                elem = prezzi[i-1][k]
                if j >= elem and dp[i-1, j-elem] != -1:
                    candidati.append(dp[i-1,j-elem]+elem)
            if candidati:
                candidati = np.array(candidati, dtype=np.int32)
                dp[i,j] = np.max(candidati)
    return np.max(dp[C,:]) if np.max(dp[C,:]!=-1) else "denaro insufficiente"   




if __name__ == '__main__':
    n = int(input()) # numero di casi di test
    arg = input().split(" ")
    B, C = int(arg[0]), int(arg[1])
    
    prezzi = []
    for i in range(0, C):
        arg_list = input().split(" ")
        arg_list_int = []
        for elem in arg_list:
            arg_list_int.append(int(elem))
        prezzi.append(arg_list_int)

    # input farlocco 
    # B = 10 
    # C = 3 
    # prezzi = [[2,1,2],[3,4,5,6],[3,6,7,1]]
    print(find_max_spesa(B, C, prezzi))

