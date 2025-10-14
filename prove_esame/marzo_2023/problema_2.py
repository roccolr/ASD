def power(x,n):
    if n == 0:
        return 1
    
    half = power(x, n//2)
    if n % 2 == 0:
        return half*half 
    else:
        return x*half*half

if __name__ == '__main__':
    print(power(3,9))