import numpy as np

def flip(arr:np.ndarray, n:int, pos:int):
    arr[:pos+1] = arr[:pos+1][::-1]

def sort(arr:np.ndarray, n:int)->tuple[np.ndarray, list]:
    flip_seq = []
    for i in range(n-1, 0, -1):
        pos = np.argmax(arr[:i+1])

        if pos != i:
            flip(arr, n, pos)
            arr[:i+1] = arr[:i+1][::-1]
            flip_seq.append(int(pos+1))

    
    flip_seq.append(0)
    return arr, flip_seq

if __name__ == '__main__':
    in_list = input().split(' ')
    arr = []
    for elem in in_list:
        arr.append(int(elem))

    n = len(arr)
    arr = np.array(arr, dtype=np.int32)
    
    print(*arr)
    print(*(sort(arr,n)[1]))
