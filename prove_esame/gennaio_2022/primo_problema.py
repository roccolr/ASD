from math import inf

def bubble_sort(arr, n):
    count = 0
    for i in range(n-1):
        for j in range(0,n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                count += 1
    return count

def swap_predict(arr, n) -> int:

    def merge(arr, p, q, r):
        count = 0
        n1 = q - p + 1
        n2 = r - q

        left = [arr[i] for i in range(p, q + 1)]
        right = [arr[i] for i in range(q + 1, r + 1)]

        left.append(inf)
        right.append(inf)

        i = 0
        j = 0

        for k in range(p, r + 1):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
                count += n1 - i  # inversion count (gli elementi restanti in left sono > right[j])
        return count

    def merge_sort(arr, p, r):
        count = 0
        if p < r:
            q = (p + r) // 2
            count += merge_sort(arr, p, q)
            count += merge_sort(arr, q + 1, r)
            count += merge(arr, p, q, r)
        return count

    return merge_sort(arr, 0, n - 1)

        
    
        

if __name__ == '__main__':
    n = int(input())
    arr = []
    in_list = input().split(' ')
    for i in range(n):
        arr.append(int(in_list[i])) 
    arr1 = list(arr)
    n_swap = bubble_sort(arr1, n)
    print(f'swap predetti {swap_predict(arr, n)} swap effettivi {n_swap}')


