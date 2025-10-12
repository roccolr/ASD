from math import ceil

def calc(D, I, depth, ret_value):
    if(depth == D):
        return ret_value
    
    # prev_value = 1 -> sono il figlio sinistro
    # prev_value = 0 -> sono il figlio destro 
    if I%2 == 0:
        return calc(D, ceil(I/2), depth+1, ret_value*2+1)
    else:
        return calc(D, ceil(I/2), depth+1, ret_value*2)
    

if __name__ == '__main__':
    n = int(input())
    test = []
    # test = [[D1,N1], [D2,N2],...,[Dn,Nn]]
    for _ in range(n):
        param_list = input().split(' ')
        test.append([int(param_list[0]), int(param_list[1])])
    
    for i in range(n):
        print(f"D={test[i][0]}, I={test[i][1]}")
        print(calc(test[i][0], test[i][1], 1, 1))