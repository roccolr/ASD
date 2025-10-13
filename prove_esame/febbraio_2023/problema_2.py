import numpy as np

def backtrack(m, r1:int,c1:int,r2:int,c2:int,N:int,M:int,areas)->None:
    def is_free()->bool:
        for i in range(r1, r2+1):
            for j in range(c1, c2+1):
                if m[i,j] == 1:
                    return False
        return True
    
    if is_free() == False:
        return
    
    local_max = (r2-r1+1)*(c2-c1+1)
    if local_max not in areas:
        areas.append(local_max)
    
    if r2+1 < N:
        backtrack(m, r1, c1, r2+1, c2, N,M, areas)
    if c2+1 < M:
        backtrack(m, r1, c1, r2, c2+1, N, M, areas)


                


if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        matrice = []
        dim = input().split(' ')
        N = int(dim[0])
        M = int(dim[1])
        for i in range(N):
            string = input().split(' ')
            riga = []
            for j in range(M):
                riga.append(string[j])
            matrice.append(riga)
        matrice = np.array(matrice, dtype=np.int8)
        matrice = matrice.reshape(N,M)
        # chiamata a funzione

        areas = []
        for i in range(N):
            for j in range(M):
                backtrack(matrice, i, j, i, j, N, M, areas)
        print(np.max(areas))


